// Copyright (c) 2022 Lukin Aleksandr
#include "PinSwitcher.h"
#include "Gpio.h"
#include <stddef.h>

namespace OS {
namespace Types {
namespace Generic {

using Drivers::Generic::Gpio;
using Drivers::Generic::TPinDirection;

PinSwitcher::PinSwitcher()
	: Switcher(), _Pio(NULL)
{
	// TODO Auto-generated constructor stub

}

PinSwitcher::PinSwitcher(Pio *pio, int pin)
	: Switcher()
{
	_Pin = pin;
	_Pio = (pio == NULL)? new Gpio() : pio;
	_Pio->SetPinDirection(TPinDirection::Output , _Pin);
}

void PinSwitcher::On()
{
	Pio* portIO = GetPortIO();
	portIO->SetPin(GetPin());
}

void PinSwitcher::Off()
{
	Pio* portIO = GetPortIO();
	portIO->ResetPin(GetPin());
}

Pio* PinSwitcher::GetPortIO()
{
	return _Pio;
}

GpioPinType PinSwitcher::GetPin()
{
	return _Pin;
}

PinSwitcher::~PinSwitcher() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */
