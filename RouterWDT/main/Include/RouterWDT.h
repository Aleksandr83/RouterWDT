#ifndef MAIN_INETWDT_H_
#define MAIN_INETWDT_H_

extern "C" {
#include <driver/gpio.h>
}

#pragma once

#include "PreCompiller.h"
#include "Led.h"
#include "RouterPowerController.h"

using namespace Drivers;

class RouterWDT {
private:
	const GpioPinType LED_PWR_PIN    = GPIO_NUM_13;
	const GpioPinType LED_WIFI_PIN   = GPIO_NUM_12;
	const GpioPinType ROUTER_PWR_PIN = GPIO_NUM_14;

	Led* _WiFiLed;
	Led* _PowerLed;
	RouterPowerController* _RouterPowerController;
public:
	RouterWDT();
	virtual ~RouterWDT();


	void Run();

private:
	void Init();
	Led* CreatePowerLed();
	Led* CreateWiFiLed();
	RouterPowerController* CreateRouterPowerController();

	inline Led* GetPowerLed();
	inline Led* GetWiFiLed();

};



#endif /* MAIN_INETWDT_H_ */
