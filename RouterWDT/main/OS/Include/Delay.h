// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_OS_DELAY_H_
#define MAIN_OS_DELAY_H_

#pragma once

#include "PreCompiller.h"

namespace OS {

class Delay {
public:
	static void Ms(uint32_t value);

	static TickType_t GetDelayTicksMs(uint32_t value);
};

} /* namespace OS */

#endif /* MAIN_OS_DELAY_H_ */
