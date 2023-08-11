
#ifndef __ESP_CLOCK_H
#define __ESP_CLOCK_H

#include "Arduino.h"

class ESPClock{
public:
	ESPClock();
	String getTime();
	uint8_t getHours();		// get current hour
	uint8_t getMinutes();	// get current minutes
	uint8_t getSeconds();	// get current seconds
	// set time of day in seconds
	uint8_t setTime(uint32_t seconds);
	bool isSet();

private:
	uint32_t now();
	uint32_t _baseSeconds;
	uint32_t _baseMillis;
	bool _isSet; 
};

#endif

