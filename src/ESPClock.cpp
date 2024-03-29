#include "ESPClock.h"

#define SECONDS_PER_DAY 86400
/* 
	ESPClock class - 12 hr clock
	Will return 0 till clock is set setTime('time of day in seconds')
	Returns time of day as Hours, Minutes and Seconds
	Returns time of day '00:00:00' as String
*/

ESPClock::ESPClock()
{
	_baseMillis = 0;
	_baseSeconds = 0;
	_isSet = false;
}

// getTime() returns current time formatted (HH:mm:ss)
String ESPClock::getTime() {
	char time[9];
	snprintf(time, sizeof(time), "%2u:%02u:%02u", getHours(), getMinutes(), getSeconds());
	return String(time);
}

// getHours() returns hours component of current time (12hr time)
uint8_t ESPClock::getHours() {
	uint8_t hours = (now()/3600);
	if(hours !=12) hours %= 12;		// convert to 12hr time
	return hours;
}

// getMinutes() returns minutes component of current time
uint8_t ESPClock::getMinutes() {
	return (now()/60) % 60;
}

// getSeconds() returns seconds component of current time
uint8_t ESPClock::getSeconds() {
	return now() % 60;
}
// getNow() returns time of day in seconds
uint32_t ESPClock::getNow() {
	return now();
}

uint8_t ESPClock::setTime(uint32_t seconds) {
	_baseSeconds = seconds % SECONDS_PER_DAY;
	_baseMillis = millis();
	_isSet = true;
	return true;
}

bool ESPClock::isSet() {
	return _isSet;
}

uint32_t ESPClock::now() {
	if(!_isSet) return 0; 		//time has not been set
	//current time in seconds
	return (((millis() - _baseMillis)/1000) + _baseSeconds);
}