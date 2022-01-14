// Copyright (c) 2022 Lukin Aleksandr

#ifndef MAIN_WIFICLIENTFACTORY_H_
#define MAIN_WIFICLIENTFACTORY_H_

#pragma once

#include "WiFiClient.h"
#include <iostream>
#include <memory>

namespace OS {
namespace WiFi {

using std::shared_ptr;

class WiFiClientFactory {
private:
	static shared_ptr<WiFiClient> _WiFiClient;

public:
	static shared_ptr<WiFiClient> Create();
};

} /* namespace WiFi */
} /* namespace OS */

#endif /* MAIN_WIFICLIENTFACTORY_H_ */
