// Copyright (c) 2022 Lukin Aleksandr
#include "Timer.h"

namespace OS {
namespace System {

Timer::Timer()
	: _TimerName("Timer"), _TimerPeriod(1000),_IsAutoReload(true)
{

	_TimerHandle = CreateTimer();
}

Timer::Timer(uint32_t period, TimerCallbackFunction_t callbackFunction)
	: _TimerName("Timer"), _IsAutoReload(true)
{
	_TimerPeriod = period;
	_Callback    = callbackFunction;
	_TimerHandle = CreateTimer();
}

TimerHandle_t Timer::CreateTimer()
{
	return xTimerCreate((const char*)_TimerName,_TimerPeriod,(_IsAutoReload)?1:0,_TimerId,_Callback);
}

void Timer::Start()
{

}

void Timer::Stop()
{

}


Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

} /* namespace System */
} /* namespace OS */
