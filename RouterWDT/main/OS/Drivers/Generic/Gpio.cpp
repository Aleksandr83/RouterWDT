// Copyright (c) 2021 Lukin Aleksandr
extern "C" {
#include <driver/gpio.h>
}

#include "Gpio.h"

namespace Drivers {
namespace Generic {

Gpio::Gpio() {
	// TODO Auto-generated constructor stub

}

void Gpio::SetPin(GpioPinType pin)
{
#if (MCU_TYPE == ESP32)
	gpio_set_level((gpio_num_t)pin, 1);
#endif
}

void Gpio::ResetPin(GpioPinType pin)
{
#if (MCU_TYPE == ESP32)
	gpio_set_level((gpio_num_t)pin, 0);
#endif
}

void Gpio::SetPinDirection(TPinDirection direction, GpioPinType pin)
{
#if (MCU_TYPE == ESP32)
	gpio_reset_pin((gpio_num_t)pin);
	if (direction == TPinDirection::Input)
		gpio_set_direction((gpio_num_t)pin, GPIO_MODE_INPUT);
	else if (direction == TPinDirection::Output)
		gpio_set_direction((gpio_num_t)pin, GPIO_MODE_OUTPUT);
#endif
}

Gpio::~Gpio() {
	// TODO Auto-generated destructor stub
}

} /* namespace Generic */
} /* namespace Drivers */
