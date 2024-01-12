
#include "DEV_Config.h"
#include <SPI.h>

void GPIO_Config(void){
    pinMode(EPD_BUSY_PIN,  INPUT);
    pinMode(EPD_RST_PIN , OUTPUT);
    pinMode(EPD_DC_PIN  , OUTPUT);
    pinMode(EPD_CS_PIN , OUTPUT);
    digitalWrite(EPD_CS_PIN , HIGH);
}
/******************************************************************************
function:	Module Initialize, the BCM2835 library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_Module_Init(void){
	//gpio
	GPIO_Config();

	//serial printf
	//Serial.begin(115200);
	
	// spi
	SPI.begin();

	return 0;
}

/******************************************************************************
function:
			SPI read and write
******************************************************************************/
void DEV_SPI_WriteByte(UBYTE data){
    SPI.transfer(data);
}
