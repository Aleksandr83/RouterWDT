// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_NET_ICMP_ICMP_H_
#define MAIN_OS_NET_ICMP_ICMP_H_

#pragma once

extern "C" {
#include <freertos/event_groups.h>
#include <ping/ping_sock.h>
}

namespace OS {
namespace Net {

class Icmp {
private:
	char*  			  _Domain;
	uint8_t 		  _PingCount;

	esp_ping_handle_t _PingHandle;

	static EventGroupHandle_t    _IcmpEventGroup;

public:
	Icmp();
	virtual ~Icmp();

	bool Ping(char* domain, uint8_t count);

private:
	void Init();

	static void OnPingSuccess(esp_ping_handle_t hdl, void *args);
	static void OnPingTimeout(esp_ping_handle_t hdl, void *args);
	static void OnPingEnd(esp_ping_handle_t hdl, void *args);

	void WaitEvents();
};

} /* namespace Net */
} /* namespace OS */

#endif /* MAIN_OS_NET_ICMP_ICMP_H_ */
