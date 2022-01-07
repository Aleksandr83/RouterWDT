// Copyright (c) 2021 Lukin Aleksandr
extern "C" {
#include <esp_wifi.h>
}

#include "WiFiClient.h"

namespace OS {
namespace WiFi {

WiFiClient::WiFiClient() {
	// TODO Auto-generated constructor stub

}

void WiFiClient::Connect()
{
	wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
	ESP_ERROR_CHECK( esp_wifi_set_storage(WIFI_STORAGE_RAM) );
	ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
	/*
	wifi_config_t sta_config = {
		.sta = {
		.ssid = CONFIG_ESP_WIFI_SSID,
		.password = CONFIG_ESP_WIFI_PASSWORD,
		.bssid_set = false
		}
	};

	ESP_ERROR_CHECK( esp_wifi_set_config(WIFI_IF_STA, &sta_config) );
	ESP_ERROR_CHECK( esp_wifi_start() );
	ESP_ERROR_CHECK( esp_wifi_connect() );
	*/
}

void WiFiClient::Disconnect()
{
	ESP_ERROR_CHECK( esp_wifi_disconnect() );
	ESP_ERROR_CHECK( esp_wifi_stop() );
	ESP_ERROR_CHECK( esp_wifi_deinit() );
}

WiFiClient::~WiFiClient() {
	// TODO Auto-generated destructor stub
}

} /* namespace WiFi */
} /* namespace OS */
