// Copyright (c) 2022 Lukin Aleksandr
#include "Initializator.h"
#include <EventLoop.h>

namespace OS {

void Initializator::Run()
{
	EventLoop::Init();
}

} /* namespace OS */
