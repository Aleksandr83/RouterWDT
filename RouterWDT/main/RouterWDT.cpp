// Copyright (c) 2021 Lukin Aleksandr
#include <RouterWDT.h>
#include "Delay.h"

using OS::Delay;

RouterWDT::RouterWDT() {

}

void RouterWDT::Init()
{
	_PowerLed = CreatePowerLed();
	_WiFiLed  = CreateWiFiLed();
	_RouterPowerController = CreateRouterPowerController();
}

Led* RouterWDT::CreatePowerLed()
{
	return new Led(NULL,RouterWDT::LED_PWR_PIN);
}

Led* RouterWDT::CreateWiFiLed()
{
	return new Led(NULL,RouterWDT::LED_WIFI_PIN);
}

RouterPowerController* RouterWDT::CreateRouterPowerController()
{
	return new RouterPowerController(NULL, RouterWDT::ROUTER_PWR_PIN);
}

Led* RouterWDT::GetPowerLed()
{
	return _PowerLed;
}

Led* RouterWDT::GetWiFiLed()
{
	return _WiFiLed;
}

void RouterWDT::Run()
{
	Init();

	while(true)
	{
		// test
		GetPowerLed()->On();
		GetWiFiLed()->On();
		Delay::Ms(1000);
		GetPowerLed()->Off();
		GetWiFiLed()->Off();
		Delay::Ms(1000);
	}
}

RouterWDT::~RouterWDT() {

}


