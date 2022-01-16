// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include "esp_netif.h"
}

#include "TcpAdaptor.h"

namespace OS {
namespace Net {
namespace Tcp {

void TcpAdaptor::Init()
{
	    //tcpip_adapter_init();
	ESP_ERROR_CHECK(esp_netif_init());
}

} /* namespace Tcp */
} /* namespace Net */
} /* namespace OS */
