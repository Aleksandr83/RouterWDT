# RouterWDT

#ESP32-WROOM-32 </br>
This device reboots the router if Wifi or Internet stops working

Problems:

There were problems associated with the stability of the Wi Fi connection on the d-link router.
He had the following Wi FI settings: </br>
	Network Authentication: Mixed WPA/WPA2 -PSK </br>
	WPA Encryption:		TKIP+AES </br>	

In this mode, Wi Fi connected, worked for several seconds, the connection was broken, and for a sufficiently long time it was not restored.

The router settings have been changed to:

	Network Authentication: Mixed WPA/WPA2 -PSK
	WPA Encryption:		AES
	
After that, the Wi-Fi connection worked stably.

