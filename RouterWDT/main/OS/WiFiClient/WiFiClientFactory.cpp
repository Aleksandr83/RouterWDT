// Copyright (c) 2022 Lukin Aleksandr

#include "WiFiClientFactory.h"
#include <stddef.h>

namespace OS {
namespace WiFi {

using std::make_shared;

shared_ptr<WiFiClient> WiFiClientFactory::_WiFiClient  = NULL;

shared_ptr<WiFiClient> WiFiClientFactory::Create()
{
	if (_WiFiClient == NULL)
		_WiFiClient = make_shared<WiFiClient>();
	return _WiFiClient;
}

} /* namespace WiFi */
} /* namespace OS */
