// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_DRIVERS_GENERIC_GPIO_H_
#define MAIN_OS_DRIVERS_GENERIC_GPIO_H_

#pragma once

#include "Pio.h"

namespace Drivers {
namespace Generic {

using Drivers::Generic::TPinDirection;
using Drivers::Generic::Pio;


class Gpio : public Pio
{
public:
	Gpio();
	virtual ~Gpio();

	void SetPin(GpioPinType pin)   override;
	void ResetPin(GpioPinType pin) override;
	void SetPinDirection(TPinDirection direction, GpioPinType pin) override;
};

} /* namespace Generic */
} /* namespace Drivers */

#endif /* MAIN_OS_DRIVERS_GENERIC_GPIO_H_ */
