// Copyright (c) 2021 Lukin Aleksandr
#ifndef MAIN_LED_H_
#define MAIN_LED_H_

#pragma once

#include "Pio.h"

namespace Drivers {

using Drivers::Generic::Pio;

class Led {
private:
	Pio*        _Pio;
	GpioPinType _Pin;
public:
	Led();
	Led(Pio *pio, int pin);
	virtual ~Led();

	void On();
	void Off();

protected:
	virtual Pio*        GetPortIO();
	virtual GpioPinType GetPin();
};

} /* namespace Drivers */

#endif /* MAIN_LED_H_ */
