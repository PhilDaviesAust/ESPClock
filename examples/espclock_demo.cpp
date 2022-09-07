#include "ESPClock.h"

ESPClock myClock;

void setup(){
    Serial.begin(115200);
    uint32_t timeOfDaySeconds = 12*60*60;
    myClock.setTime(timeOfDaySeconds);
}
void loop(){
    if(myClock.isSet()) {
        Serial.printf("time is %s\n", myClock.getTime());
    }

    uint8_t hours = myClock.getHours();
    uint8_t minutes = myClock.getMinutes();
    Serial.printf("time is %i:%i\n", hours, minutes);
}