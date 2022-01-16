// Copyright (c) 2022 Lukin Aleksandr
#ifndef OS_NET_DNS_DNS_H_
#define OS_NET_DNS_DNS_H_

#pragma once

namespace OS {
namespace Net {

class Dns {
public:
	static ip_addr_t GetIp4AddressByName(char* domain);
};

} /* namespace Net */
} /* namespace OS */

#endif /* OS_NET_DNS_DNS_H_ */
