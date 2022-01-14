// Copyright (c) 2022 Lukin Aleksandr
#include <freertos/FreeRTOS.h>
#include "esp_wifi.h"
#include <esp_system.h>

wifi_config_t GetWiFiConfig()
{
	wifi_config_t result  =  {
	        .sta = {
	            .ssid     = CONFIG_ESP_WIFI_SSID,
	            .password = CONFIG_ESP_WIFI_PASSWORD,

				.threshold.authmode = WIFI_AUTH_WPA2_PSK,

				.pmf_cfg = {
				                .capable = true,
				                .required = false
				            },
	        },

	};
	return result;
}


