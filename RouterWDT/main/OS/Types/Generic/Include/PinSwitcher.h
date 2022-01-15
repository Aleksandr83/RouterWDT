// Copyright (c) 2022 Lukin Aleksandr
#ifndef OS_TYPES_GENERIC_PINSWITCHER_H_
#define OS_TYPES_GENERIC_PINSWITCHER_H_

#pragma once

#include "Pio.h"
#include "Switcher.h"

namespace OS {
namespace Types {
namespace Generic {

using Drivers::Generic::Pio;
using OS::Types::Generic::Switcher;

class PinSwitcher : public Switcher{
private:
	Pio*        _Pio;
	GpioPinType _Pin;

public:
	PinSwitcher();
	PinSwitcher(Pio *pio, int pin);
	virtual ~PinSwitcher();

	virtual void On()  override;
	virtual void Off() override;

protected:
	virtual Pio*        GetPortIO();
	virtual GpioPinType GetPin();
};

} /* namespace Generic */
} /* namespace Types */
} /* namespace OS */

#endif /* OS_TYPES_GENERIC_PINSWITCHER_H_ */
