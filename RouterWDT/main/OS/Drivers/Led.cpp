// Copyright (c) 2022 Lukin Aleksandr
#include "Led.h"
#include "Gpio.h"
#include <stddef.h>

namespace Drivers {

using Drivers::Generic::Gpio;
using Drivers::Generic::TPinDirection;

Led::Led()
	: PinSwitcher()
{
}

Led::Led(Pio *pio, int pin)
	: PinSwitcher(pio, pin)
{

}

Led::~Led() {
	// TODO Auto-generated destructor stub
}

} /* namespace Drivers */

