// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_LED_H_
#define MAIN_LED_H_

#pragma once

#include "PinSwitcher.h"

namespace Drivers {

using Drivers::Generic::Pio;
using OS::Types::Generic::PinSwitcher;

class Led : public PinSwitcher {
public:
	Led(Pio *pio, int pin);
	virtual ~Led();

};

} /* namespace Drivers */

#endif /* MAIN_LED_H_ */
