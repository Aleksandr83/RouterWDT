// Copyright (c) 2021 Lukin Aleksandr
extern "C" {
#include <esp_event_loop.h>
}

#include "Delay.h"

namespace OS {

void Delay::Ms(uint32_t value)
{
#if (MCU_TYPE == ESP32)
	vTaskDelay(1000 / portTICK_PERIOD_MS);
#endif
}

} /* namespace OS */
