// Copyright (c) 2022 Lukin Aleksandr
#include "StatusLed.h"

namespace OS {
namespace Types {

StatusLed::StatusLed()
	:_StatusLed(NULL)
{
	// TODO Auto-generated constructor stub

}

void StatusLed::SetStatusLed(shared_ptr<Led> led)
{
	_StatusLed = led;
}

void StatusLed::StatusLedOn()
{
	if (_StatusLed != NULL)
		_StatusLed->On();
}

void StatusLed::StatusLedOff()
{
	if (_StatusLed != NULL)
		_StatusLed->Off();
}

StatusLed::~StatusLed() {
	// TODO Auto-generated destructor stub
}

}
}
