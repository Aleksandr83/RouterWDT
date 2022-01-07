#include "RouterPowerController.h"

RouterPowerController::RouterPowerController() {
	// TODO Auto-generated constructor stub

}

RouterPowerController::RouterPowerController(Pio *pio, int pin)
	:Led(pio,pin)
{
}

RouterPowerController::~RouterPowerController() {
	// TODO Auto-generated destructor stub
}

