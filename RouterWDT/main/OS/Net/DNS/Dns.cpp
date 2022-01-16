// Copyright (c) 2022 Lukin Aleksandr
extern "C" {
#include <lwip/netdb.h>
}

#include "Dns.h"


namespace OS {
namespace Net {

ip_addr_t Dns::GetIp4AddressByName(char* domain)
{
	ip_addr_t target_addr;
	struct addrinfo hint;
	struct addrinfo *res = NULL;

	memset(&hint, 0, sizeof(hint));
	memset(&target_addr, 0, sizeof(target_addr));

	getaddrinfo(domain, NULL, &hint, &res);
	struct in_addr addr4 = ((struct sockaddr_in *) (res->ai_addr))->sin_addr;
	inet_addr_to_ip4addr(ip_2_ip4(&target_addr), &addr4);
	freeaddrinfo(res);

	return target_addr;
}

} /* namespace Net */
} /* namespace OS */
