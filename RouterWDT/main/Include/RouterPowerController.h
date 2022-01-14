// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_ROUTERPOWERCONTROLLER_H_
#define MAIN_ROUTERPOWERCONTROLLER_H_

#pragma once

#include "Led.h"

using Drivers::Led;
using Drivers::Pio;

class RouterPowerController : public Led
{
public:
	RouterPowerController();
	RouterPowerController(Pio *pio, int pin);
	virtual ~RouterPowerController();
};

#endif /* MAIN_ROUTERPOWERCONTROLLER_H_ */
