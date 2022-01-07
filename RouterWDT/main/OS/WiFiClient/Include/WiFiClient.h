// Copyright (c) 2021 Lukin Aleksandr
#ifndef MAIN_OS_WIFICLIENT_WIFICLIENT_H_
#define MAIN_OS_WIFICLIENT_WIFICLIENT_H_

namespace OS {
namespace WiFi {

class WiFiClient {
public:
	WiFiClient();
	virtual ~WiFiClient();

	void Connect();
	void Disconnect();
};

} /* namespace WiFi */
} /* namespace OS */

#endif /* MAIN_OS_WIFICLIENT_WIFICLIENT_H_ */
