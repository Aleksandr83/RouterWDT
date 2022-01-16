// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_ROUTERPOWERCONTROLLER_H_
#define MAIN_ROUTERPOWERCONTROLLER_H_

#pragma once

#include "Pio.h"
#include "StatusLed.h"
#include "PinSwitcher.h"

using Drivers::Generic::Pio;
using OS::Types::StatusLed;
using OS::Types::Generic::PinSwitcher;

class RouterPowerController
	: public PinSwitcher, public StatusLed
{

public:
	RouterPowerController(Pio *pio, int pin);
	virtual ~RouterPowerController();

	virtual void On()  override;
	virtual void Off() override;
};

#endif /* MAIN_ROUTERPOWERCONTROLLER_H_ */
