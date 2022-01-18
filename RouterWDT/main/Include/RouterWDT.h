// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_INETWDT_H_
#define MAIN_INETWDT_H_

extern "C" {
#include <driver/gpio.h>
#include <esp_system.h>
}

#pragma once

#include "PreCompiller.h"
#include "Led.h"
#include "RouterPowerController.h"
#include "WiFiClient.h"
#include "Icmp.h"

using Drivers::Led;
using OS::WiFi::WiFiClient;
using OS::Net::Icmp;

class RouterWDT {
private:
	const GpioPinType ROUTER_PWR_PIN = GPIO_NUM_25;

	shared_ptr<Led> 		_WiFiLed;
	shared_ptr<Led> 		_PowerLed;

	shared_ptr<Icmp> 		_Icmp;
	shared_ptr<WiFiClient> 	_WiFiClient;

	shared_ptr<RouterPowerController> _RouterPowerController;

public:
	RouterWDT();
	virtual ~RouterWDT();

	void Run();
	void RouterReboot();

private:
	void Init();
	void InitLed();
	void InitIcmp();
	void InitWiFiClient();
	void InitRouterPowerController();

};



#endif /* MAIN_INETWDT_H_ */
