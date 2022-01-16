// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "lwip/err.h"
#include "lwip/sys.h"

#include "WiFiConfig.h"

wifi_config_t GetWiFiConfig();
}

#include "WiFiClient.h"
#include "WiFiClientFactory.h"
#include "TcpAdaptor.h"
#include "Delay.h"
#include "LedFactory.h"

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

static const char *TAG = "WiFi Client";

namespace OS   {
namespace WiFi {

using OS::Net::Tcp::TcpAdaptor;
using OS::Delay;

EventGroupHandle_t  WiFiClient::_WiFiEventGroup;
esp_event_handler_instance_t WiFiClient::_EventAnyId;
esp_event_handler_instance_t WiFiClient::_EventGotIP;

WiFiClient::WiFiClient()
	:StatusLed(), _IsShowPasswordInLog(false),_IsConnected(false),_IsRunConnect(false)
{
	_WiFiEventGroup   = xEventGroupCreate();

	RegistredWiFiEventHandler();
	RegistredIPEventHandler();

	_ConectionCounter = make_shared<Counter<uint8_t>>();
}

void WiFiClient::Init()
{
	TcpAdaptor::Init();
	esp_netif_create_default_wifi_sta();

	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
	ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );

	wifi_config_t sta_config = GetWiFiConfig();
	printf("WiFi SSID:%s \n",sta_config.sta.ssid);
	if (_IsShowPasswordInLog)
		printf("WiFi PASS:%s \n",sta_config.sta.password);

	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &sta_config) );
}

void WiFiClient::RegistredWiFiEventHandler()
{
	ESP_ERROR_CHECK
		(
			esp_event_handler_instance_register
				(
					WIFI_EVENT,
	                ESP_EVENT_ANY_ID,
	                &WiFiClient::WiFiEventHandler,
	                NULL,
	                &_EventAnyId
				)
		);
}

void WiFiClient::RegistredIPEventHandler()
{
	ESP_ERROR_CHECK
		(
			esp_event_handler_instance_register
				(
					IP_EVENT,
	                IP_EVENT_STA_GOT_IP,
	                &WiFiClient::IpEventHandler,
	                NULL,
	                &_EventGotIP
				)
		);
}

void WiFiClient::WaitEvents()
{
	xEventGroupWaitBits
		(
			_WiFiEventGroup,
			WIFI_CONNECTED_BIT | WIFI_FAIL_BIT, pdFALSE, pdFALSE, portMAX_DELAY
		);
}

bool WiFiClient::IsConnected()
{
	return _IsConnected;
}

bool WiFiClient::IsRunConnect()
{
	return _IsRunConnect;
}

bool WiFiClient::Connect()
{
	if (IsConnected())
	{
		return true;
	}

	if (!IsRunConnect())
	{
		_IsRunConnect = true;
	}


	ESP_LOGI(TAG, "Init WiFi\n");

	ESP_ERROR_CHECK( esp_wifi_start() );

	WaitEvents();

	return IsConnected();
}

void WiFiClient::Reconnect()
{
	Disconnect();
	Connect();
}

void WiFiClient::Disconnect()
{
	esp_wifi_stop();
	Delay::Ms(200);

	esp_wifi_deinit();
	Delay::Ms(200);
}

void WiFiClient::WiFiEventHandler
	(void* arg, esp_event_base_t eventBase, int32_t eventId, void* eventData)
{
	if (eventBase != WIFI_EVENT) return;

	if (eventId == WIFI_EVENT_STA_START)
	{
		ESP_ERROR_CHECK( esp_wifi_connect() );
		return;
	}

	if (eventId == WIFI_EVENT_STA_DISCONNECTED)
	{
		xEventGroupSetBits(_WiFiEventGroup, WIFI_FAIL_BIT);

		auto client = WiFiClientFactory::Create();
		if (client != NULL)
		{
			client->OnDisconnected();
			client->Reconnect();
		}
		return;
	}
}

void WiFiClient::IpEventHandler
	(void* arg, esp_event_base_t eventBase, int32_t eventId, void* eventData)
{
	if (eventBase != IP_EVENT)   return;

	if (eventId == IP_EVENT_STA_GOT_IP)
	{
		ip_event_got_ip_t* event = (ip_event_got_ip_t*) eventData;
		ESP_LOGI(TAG, "ip:" IPSTR, IP2STR(&event->ip_info.ip));

		auto client = WiFiClientFactory::Create();

		if (client != NULL)
			client->OnConnected();

		xEventGroupSetBits(_WiFiEventGroup, WIFI_CONNECTED_BIT);

		return;
	}
}

void WiFiClient::OnConnected()
{
	ESP_LOGI(TAG, "WiFi is connected\n");
	_IsConnected = true;
	StatusLedOn();
}

void WiFiClient::OnDisconnected()
{
	ESP_LOGI(TAG, "WiFi is disconnected\n");
	_IsConnected = false;
	StatusLedOff();
}

shared_ptr<Counter<uint8_t>> WiFiClient::GetConectionCounter()
{
	return _ConectionCounter;
}

WiFiClient::~WiFiClient() {
	// TODO Auto-generated destructor stub
}

} /* namespace WiFi */
} /* namespace OS */
