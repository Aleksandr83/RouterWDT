// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_SYSTEM_TIMER_H_
#define MAIN_OS_SYSTEM_TIMER_H_

#pragma once

extern "C" {
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
}

#include "PreCompiller.h"
#include "Registrator.h"

namespace OS {
namespace System {

using OS::Types::Registrator;

template <class TArgs>
class Timer {
public:
	typedef void (* TimerCallbackMethod_t)(Timer* timer,TArgs args);
private:
	bool			_IsEnable;
	char * 		   	_TimerName;
	TickType_t 		_TimerPeriod;
	bool 			_IsAutoReload;
	void*			_TimerId;

	TArgs 			_Args;
	TimerHandle_t  	_TimerHandle;

	TimerCallbackMethod_t _Callback;

	static Registrator<TimerHandle_t,Timer<TArgs>*> _Registrator;

public:
	Timer(uint32_t period,TimerCallbackMethod_t callback, TArgs args);
	virtual ~Timer();

	virtual void Start();
	virtual void Stop();

protected:
	virtual void Reset();

	static  void OnTimer(TimerHandle_t  timerHandle);

private:
	static void Reset(TimerHandle_t  timerHandle);
	TimerHandle_t CreateTimer();

};

} /* namespace System */
} /* namespace OS */

#include "../Timer.tpp"

#endif /* MAIN_OS_SYSTEM_TIMER_H_ */
