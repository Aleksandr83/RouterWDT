// Copyright (c) 2022 Lukin Aleksandr

#ifndef MAIN_WIFICLIENT_H_
#define MAIN_WIFICLIENT_H_

#pragma once

extern "C" {
#include "esp_event.h"
#include "freertos/event_groups.h"
}

#include "Led.h"

using Drivers::Led;

namespace OS {
namespace WiFi {

class WiFiClient {
public:
	bool _IsShowPasswordInLog;

private:
	bool _IsConnected;
	bool _IsRunConnect;

	shared_ptr<Led> _WiFiLed;

	static esp_event_handler_instance_t _EventAnyId;
	static esp_event_handler_instance_t _EventGotIP;

	static EventGroupHandle_t    _WiFiEventGroup;

public:
	WiFiClient();
	virtual ~WiFiClient();

	void Init();

	bool IsConnected();

	void Connect();
	void Disconnect();
	void Reconnect();

private:

	void RegistredWiFiEventHandler();
	void RegistredIPEventHandler();

	static void WiFiEventHandler
		(void* arg, esp_event_base_t eventBase, int32_t eventId, void* eventData);
	static void IpEventHandler
		(void* arg, esp_event_base_t eventBase, int32_t eventId, void* eventData);

	void WaitEvents();

	void OnConnected();
	void OnDisconnected();
};

} /* namespace WiFi */
} /* namespace OS */

#endif /* MAIN_WIFICLIENT_H_ */
