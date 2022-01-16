// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <freertos/FreeRTOS.h>
}

#include "Settings.h"
#include <RouterWDT.h>
#include "Delay.h"
#include "LedFactory.h"
#include "WiFiClientFactory.h"
#include "Dns.h"

using OS::Delay;
using OS::WiFi::WiFiClientFactory;

using OS::Net::Dns;

RouterWDT::RouterWDT()
	: _RouterPowerController(NULL)
{

}

void RouterWDT::Init()
{
	_PowerLed   = LedFactory::Create(TLedType::PWR);
	_WiFiLed    = LedFactory::Create(TLedType::WiFi);

	_RouterPowerController = CreateRouterPowerController();
	_RouterPowerController->SetStatusLed(_PowerLed);
	_RouterPowerController->On();

	_WiFiClient = WiFiClientFactory::Create();	
	_WiFiClient->SetStatusLed(_WiFiLed);
	_WiFiClient->GetConectionCounter()->Max()->SetValue(DEF_NUMBER_CONNECTION_ATTEMPTS_WIFI);
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
		// start test
		auto _Counter = _WiFiClient->GetConectionCounter();
		printf("Counter value: %d\n",_Counter->GetValue());
		if (_Counter->IsMaxLimit())
		{
			printf("Counter is max value. His was the reset. \n");
			_Counter->Reset();
		}
		else
			_Counter->Inc();
		// end test

		if (!_WiFiClient->Connect())
		{
			Delay::Ms(1000);
			continue;
		}



		//Dns::GetIp4AddressByName("www.google.com");

    	Delay::Ms(1000);
	}
}


RouterWDT::~RouterWDT() {

}


