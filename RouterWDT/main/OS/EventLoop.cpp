// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <esp_event.h>
}

#include "EventLoop.h"

namespace OS {

void EventLoop::Init()
{
	ESP_ERROR_CHECK(esp_event_loop_create_default());
}

} /* namespace OS */
