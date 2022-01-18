// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <freertos/FreeRTOS.h>
}

#include "Settings.h"
#include <RouterWDT.h>
#include "Delay.h"
#include "LedFactory.h"
#include "WiFiClientFactory.h"

using OS::Delay;
using OS::WiFi::WiFiClientFactory;

RouterWDT::RouterWDT()
	: _RouterPowerController(NULL)
{

}

void RouterWDT::Init()
{
	InitLed();
	InitRouterPowerController();
	InitWiFiClient();
	InitIcmp();

}

void RouterWDT::InitLed()
{
	_PowerLed   = LedFactory::Create(TLedType::PWR);
	_WiFiLed    = LedFactory::Create(TLedType::WiFi);
}

void RouterWDT::InitIcmp()
{
	_Icmp = make_shared<Icmp>();
}

void RouterWDT::InitWiFiClient()
{
	_WiFiClient = WiFiClientFactory::Create();
	_WiFiClient->SetStatusLed(_WiFiLed);
	_WiFiClient->GetConectionCounter()->Max()->SetValue(DEF_NUMBER_CONNECTION_ATTEMPTS_WIFI);
}

void RouterWDT::InitRouterPowerController()
{
	_RouterPowerController =
			make_shared<RouterPowerController>(static_cast<Pio*>(NULL), RouterWDT::ROUTER_PWR_PIN);
	_RouterPowerController->SetStatusLed(_PowerLed);
	_RouterPowerController->On();
}


void RouterWDT::Run()
{
	Init();

	for(;;)
	{
		if (!_WiFiClient->IsConnected())
		{
			if (!_WiFiClient->IsRunConnect())
			{
				printf("\nWaiting for the router to load(%d seconds)...\n", DEF_TIME_ROUTER_LOAD/1000);
				Delay::Ms(DEF_TIME_ROUTER_LOAD);
			}

			if (!_WiFiClient->Connect())
			{
				if (_WiFiClient->GetConectionCounter()->IsMaxLimit())
				{
					_WiFiClient->ResetState();
					RouterReboot();
				}
				Delay::Ms(1000);
				continue;
			}
		}

		if (!_Icmp->Ping((char*)"Mail.ru", 3))
		{

		}


    	Delay::Ms(1000);
	}
}

void RouterWDT::RouterReboot()
{
	printf("\nWaiting for router reboot...\n");

	_RouterPowerController->Off();

	Delay::Ms(DEF_TIME_SHUTDOWN_ROUTER);

	_RouterPowerController->On();
}

RouterWDT::~RouterWDT() {

}


