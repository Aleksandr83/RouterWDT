// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <freertos/FreeRTOS.h>
}

#include <RouterWDT.h>
#include "Delay.h"
#include "LedFactory.h"
#include "WiFiClientFactory.h"

using OS::Delay;
using OS::WiFi::WiFiClientFactory;

RouterWDT::RouterWDT() {

}

void RouterWDT::Init()
{
	_PowerLed   = LedFactory::Create(TLedType::PWR);
	_WiFiLed    = LedFactory::Create(TLedType::WiFi);
	_RouterPowerController = CreateRouterPowerController();

	_WiFiClient = WiFiClientFactory::Create();	
	_WiFiClient->Init();

}



RouterPowerController* RouterWDT::CreateRouterPowerController()
{
	return new RouterPowerController(NULL, RouterWDT::ROUTER_PWR_PIN);
}

void RouterWDT::Run()
{
	Init();

	for(;;)
	{
		if (!_WiFiClient->IsConnected())
		{
			_WiFiClient->Connect();
			continue;
		}

    	Delay::Ms(1000);
	}
}


RouterWDT::~RouterWDT() {

}


