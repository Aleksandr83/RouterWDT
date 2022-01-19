// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_SYSTEM_TIMER_H_
#define MAIN_OS_SYSTEM_TIMER_H_

#pragma once

extern "C" {
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
}

#include "PreCompiller.h"

namespace OS {
namespace System {

class Timer {
private:
	char * 		   	_TimerName;
	TickType_t 		_TimerPeriod;
	bool 			_IsAutoReload;
	void*			_TimerId;

	TimerHandle_t  	_TimerHandle;

	TimerCallbackFunction_t _Callback;  //void vCallbackFunction( TimerHandle_t xTimer )

public:
	Timer();
	Timer(uint32_t period, TimerCallbackFunction_t callbackFunction);
	virtual ~Timer();

	void Start();
	void Stop();

private:
	TimerHandle_t CreateTimer();

};

} /* namespace System */
} /* namespace OS */

#endif /* MAIN_OS_SYSTEM_TIMER_H_ */
