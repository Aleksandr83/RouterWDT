// Copyright (c) 2022 Lukin Aleksandr
#ifndef MAIN_CONFIGURATION_SETTINGS_H_
#define MAIN_CONFIGURATION_SETTINGS_H_

extern "C" {
#include <driver/gpio.h>
}

#pragma once

#define DEF_TIME_ROUTER_LOAD					10000
#define DEF_NUMBER_CONNECTION_ATTEMPTS_WIFI		30
#define DEF_NUMBER_ERRORS_PING					3
#define DEF_TIME_SHUTDOWN_ROUTER				10000
#define DEF_DOMAIN_CHECK_INTERVAL				10000



#endif /* MAIN_CONFIGURATION_SETTINGS_H_ */
