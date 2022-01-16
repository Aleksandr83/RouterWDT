// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <driver/gpio.h>
}

#include "LedFactory.h"

#define LED_PWR_PIN  GPIO_NUM_27
#define LED_WIFI_PIN GPIO_NUM_26

shared_ptr<Led> LedFactory::_PowerLed = NULL;
shared_ptr<Led> LedFactory::_WiFiLed  = NULL;

shared_ptr<Led> LedFactory::Create(TLedType ledType)
{
	if (ledType == TLedType::PWR)
	{
		if (_PowerLed == NULL)
			_PowerLed = make_shared<Led>((Drivers::Generic::Pio*)NULL, LED_PWR_PIN);
		return _PowerLed;
	}
	if (ledType == TLedType::WiFi)
	{
		if (_WiFiLed == NULL)
			_WiFiLed = make_shared<Led>((Drivers::Generic::Pio*)NULL,  LED_WIFI_PIN);
		return _WiFiLed;
	}
	return NULL;
}

