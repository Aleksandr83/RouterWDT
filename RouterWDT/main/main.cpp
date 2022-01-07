
// Copyright (c) 2021 Lukin Aleksandr
extern "C" {
#include <freertos/FreeRTOS.h>
#include <esp_wifi.h>
#include <esp_system.h>
#include <esp_event.h>
#include <esp_event_loop.h>
#include <nvs_flash.h>
#include <driver/gpio.h>

void app_main(void);
}

#include "RouterWDT.h"


void Init();
void EnableWiFi();
void DisableWiFi();

esp_err_t event_handler(void *ctx, system_event_t *event)
{
    return ESP_OK;
}

void app_main(void)
{

    nvs_flash_init();
    tcpip_adapter_init();
    ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL) );

    RouterWDT *routerWDT = new RouterWDT();
    routerWDT->Run();

}

