// Copyright (c) 2022 Lukin Aleksandr
#include "Timer.h"

namespace OS {
namespace System {

template <class TArgs>
Registrator<TimerHandle_t,Timer<TArgs>*> Timer<TArgs>::_Registrator;

template <class TArgs>
Timer<TArgs>::Timer(uint32_t period,TimerCallbackMethod_t callback, TArgs args)
	: _IsEnable(false), _TimerName((char*)"Timer"), _TimerPeriod(period),
	  _IsAutoReload(true), _Args(args), _Callback(callback)
{
	_TimerHandle = CreateTimer();
	_Registrator.Registration(_TimerHandle, this);
}

template <class TArgs>
TimerHandle_t Timer<TArgs>::CreateTimer()
{
	return xTimerCreate((const char*)_TimerName,_TimerPeriod,(_IsAutoReload)?1:0,_TimerId, Timer::OnTimer);
}

template <class TArgs>
void Timer<TArgs>::Start()
{
	if (_IsEnable) return;
	Reset();
	xTimerStart(_TimerHandle, 0);
	_IsEnable = true;
}

template <class TArgs>
void Timer<TArgs>::Stop()
{
	if (!_IsEnable) return;
	xTimerStop(_TimerHandle,  0);
	_IsEnable = false;
}

template <class TArgs>
void Timer<TArgs>::Reset()
{
	Timer::Reset(_TimerHandle);
}

template <class TArgs>
void Timer<TArgs>::Reset(TimerHandle_t  timerHandle)
{
	xTimerReset(timerHandle, 0);
}

template <class TArgs>
void Timer<TArgs>::OnTimer(TimerHandle_t  timerHandle)
{
	auto timer = Timer::_Registrator[timerHandle];
	if (timer->_IsEnable)
		timer->_Callback(timer,timer->_Args);
	timer->Reset();
}

template <class TArgs>
Timer<TArgs>::~Timer() {
	// TODO Auto-generated destructor stub
}

} /* namespace System */
} /* namespace OS */
