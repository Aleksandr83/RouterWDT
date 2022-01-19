// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <lwip/inet.h>
#include <lwip/sockets.h>
#include <esp_event.h>
}

#include "Icmp.h"
#include "Delay.h"
#include "Dns.h"
#include "Delay.h"

#define ICMP_OK_BIT 	BIT0

namespace OS {
namespace Net {

using OS::Delay;

EventGroupHandle_t Icmp::_IcmpEventGroup = xEventGroupCreate();

Icmp::Icmp()
	: _Domain((char*)""), _PingCount(0)
{
	memset(&_PingHandle, 0, sizeof(_PingHandle));
}

void Icmp::Init()
{
	ip_addr_t ip = Dns::GetIp4AddressByName(_Domain);

	printf("Start ping %s ", _Domain);
	esp_ping_config_t ping_config = ESP_PING_DEFAULT_CONFIG();
	ping_config.target_addr = ip;
	ping_config.count       = _PingCount;
	printf("(");
	printf(IPSTR, IP2STR(&ip));
	printf(")\n");

	esp_ping_callbacks_t cbs;
	memset(&cbs, 0, sizeof(cbs));
	cbs.on_ping_success = OnPingSuccess;
	cbs.on_ping_timeout = OnPingTimeout;
	cbs.on_ping_end     = OnPingEnd;
	cbs.cb_args 		= NULL;

	esp_ping_new_session(&ping_config, &cbs, &_PingHandle);

}

bool Icmp::Ping(char* domain, uint8_t count)
{
	uint32_t transmitted;
	uint32_t received;

	_Domain    = domain;
	_PingCount = count;

	Init();
	esp_ping_start(_PingHandle);

	WaitEvents();

	esp_ping_get_profile(_PingHandle, ESP_PING_PROF_REQUEST,  &transmitted,   sizeof(transmitted));
	esp_ping_get_profile(_PingHandle, ESP_PING_PROF_REPLY, 	  &received, 	  sizeof(received));

	esp_ping_delete_session(_PingHandle);

	return (transmitted == received&&received != 0);
}

void Icmp::OnPingSuccess(esp_ping_handle_t hdl, void *args)
{
	uint8_t   ttl;
	uint16_t  seqno;
	uint32_t  elapsed_time, recv_len;
	ip_addr_t target_addr;

	esp_ping_get_profile(hdl, ESP_PING_PROF_SEQNO,   &seqno,        sizeof(seqno));
	esp_ping_get_profile(hdl, ESP_PING_PROF_TTL,     &ttl,          sizeof(ttl));
	esp_ping_get_profile(hdl, ESP_PING_PROF_IPADDR,  &target_addr,  sizeof(target_addr));
	esp_ping_get_profile(hdl, ESP_PING_PROF_SIZE,    &recv_len,     sizeof(recv_len));
	esp_ping_get_profile(hdl, ESP_PING_PROF_TIMEGAP, &elapsed_time, sizeof(elapsed_time));

	printf
		(
			"%d bytes from %s icmp_seq=%d ttl=%d time=%d ms\n",
	        recv_len, ipaddr_ntoa((ip_addr_t*)&target_addr), seqno, ttl, elapsed_time
		);
}

void Icmp::OnPingTimeout(esp_ping_handle_t hdl, void *args)
{
	uint16_t seqno;
	ip_addr_t target_addr;

	esp_ping_get_profile(hdl, ESP_PING_PROF_SEQNO,  &seqno, 	 sizeof(seqno));
	esp_ping_get_profile(hdl, ESP_PING_PROF_IPADDR, &target_addr,sizeof(target_addr));

	printf("From %s icmp_seq=%d timeout\n", ipaddr_ntoa((ip_addr_t*) &target_addr), seqno);

}

void Icmp::OnPingEnd(esp_ping_handle_t hdl, void *args)
{
	uint32_t transmitted;
	uint32_t received;
	uint32_t total_time_ms;

	esp_ping_get_profile(hdl, ESP_PING_PROF_REQUEST,  &transmitted,   sizeof(transmitted));
	esp_ping_get_profile(hdl, ESP_PING_PROF_REPLY, 	  &received, 	  sizeof(received));
	esp_ping_get_profile(hdl, ESP_PING_PROF_DURATION, &total_time_ms, sizeof(total_time_ms));

	printf("%d packets transmitted, %d received, time %dms\n", transmitted, received, total_time_ms);

	xEventGroupSetBits(_IcmpEventGroup, ICMP_OK_BIT);
}

void Icmp::WaitEvents()
{
	const TickType_t xTicksToWait = Delay::GetDelayTicksMs(5000);
	xEventGroupWaitBits
			(
				_IcmpEventGroup,
				ICMP_OK_BIT, pdFALSE, pdFALSE, xTicksToWait
			);
	xEventGroupClearBits(_IcmpEventGroup, ICMP_OK_BIT);
}

Icmp::~Icmp() {
	// TODO Auto-generated destructor stub
}

} /* namespace Net */
} /* namespace OS */
