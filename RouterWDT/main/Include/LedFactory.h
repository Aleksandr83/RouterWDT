// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_LEDFACTORY_H_
#define MAIN_LEDFACTORY_H_

#pragma once

#include "Led.h"

enum TLedType
{
	PWR,
	WiFi
};

using Drivers::Led;

class LedFactory {
private:
	static shared_ptr<Led> _PowerLed;
	static shared_ptr<Led> _WiFiLed;
public:
	static shared_ptr<Led> Create(TLedType ledType);
};

#endif /* MAIN_LEDFACTORY_H_ */
