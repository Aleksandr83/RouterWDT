// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <freertos/FreeRTOS.h>
#include <esp_wifi.h>
#include <esp_system.h>
#include <esp_event.h>
#include <nvs_flash.h>
#include <driver/gpio.h>

void app_main(void);
}

#include "Initializator.h"
#include "RouterWDT.h"

#include "Delay.h"


using OS::Initializator;

void app_main(void)
{
	//Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
	      ESP_ERROR_CHECK(nvs_flash_erase());
	      ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

    Initializator::Run();

    static RouterWDT *routerWDT = new RouterWDT();
    routerWDT->Run();

    for(;;)
    {
        OS::Delay::Ms(1000);
    }

}

