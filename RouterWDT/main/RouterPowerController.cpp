// Copyright (c) 2022 Lukin Aleksandr
#include "RouterPowerController.h"

RouterPowerController::RouterPowerController(Pio *pio, int pin)
	: PinSwitcher(pio,pin), StatusLed()
{
}

void RouterPowerController::On()
{
	PinSwitcher::On();
	StatusLedOn();
}

void RouterPowerController::Off()
{
	PinSwitcher::Off();
	StatusLedOff();
}

RouterPowerController::~RouterPowerController() {
	// TODO Auto-generated destructor stub
}

