// Copyright (c) 2022 Lukin Aleksandr
extern "C"{
#include "esp_system.h"
}

#include "Device.h"

namespace OS {
namespace System {

void Device::Reboot()
{
	printf("Device restarting now.\n");
	esp_restart();
}

} /* namespace System */
} /* namespace OS */
