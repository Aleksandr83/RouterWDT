// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_DRIVERS_PIO_H_
#define MAIN_DRIVERS_PIO_H_

#pragma once

#include "PreCompiller.h"

namespace Drivers {
namespace Generic {

enum TPinDirection
{
	Input,
	Output
};

class Pio {
public:
	Pio();
	virtual ~Pio();

	virtual void SetPin(GpioPinType pin)   = 0;
	virtual void ResetPin(GpioPinType pin) = 0;

	virtual void SetPinDirection(TPinDirection direction, GpioPinType pin) = 0;
};

} /* namespace Generic */
} /* namespace Drivers */

#endif /* MAIN_DRIVERS_PIO_H_ */
