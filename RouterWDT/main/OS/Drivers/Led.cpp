// Copyright (c) 2021 Lukin Aleksandr
#include "Led.h"
#include "Gpio.h"

namespace Drivers {

using Drivers::Generic::Gpio;
using Drivers::Generic::TPinDirection;

Led::Led()
{
}

Led::Led(Pio *pio, int pin)
{
	_Pin = pin;
	_Pio = (pio == NULL)? new Gpio() : pio;
	_Pio->SetPinDirection(TPinDirection::Output , _Pin);
}

void Led::On()
{
	Pio* portIO = GetPortIO();
	portIO->SetPin(GetPin());
}

void Led::Off()
{
	Pio* portIO = GetPortIO();
	portIO->ResetPin(GetPin());
}

Pio* Led::GetPortIO()
{
	return _Pio;
}

int32_t Led::GetPin()
{
	return _Pin;
}

Led::~Led() {
	// TODO Auto-generated destructor stub
}

} /* namespace Drivers */

