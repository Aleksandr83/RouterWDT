// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <esp_event.h>
}

#include "Delay.h"

namespace OS {

void Delay::Ms(uint32_t value)
{
#if (MCU_TYPE == ESP32)
	vTaskDelay(value / portTICK_PERIOD_MS);
#endif
}

} /* namespace OS */
