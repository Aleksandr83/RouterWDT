// Copyright (c) 2022 Lukin Aleksandr
#ifndef OS_DRIVERS_STATUSLED_H_
#define OS_DRIVERS_STATUSLED_H_

#pragma once

#include "PreCompiller.h"
#include "Led.h"

namespace OS {
namespace Types {

using Drivers::Led;

class StatusLed {
private:
	shared_ptr<Led> _StatusLed;

public:
	StatusLed();
	virtual ~StatusLed();

	virtual void SetStatusLed(shared_ptr<Led> led);

	virtual void StatusLedOn();
	virtual void StatusLedOff();
};

}
}

#endif /* OS_DRIVERS_STATUSLED_H_ */
