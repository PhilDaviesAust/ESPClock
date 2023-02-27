# Arduino library for the ESP8266 Clock
    Tracks time of day once a base time is set
    returns time of day

    initialise clock    -  ESPClock myClock;
    set time            -  myClock.setTime(unit32_t timeOfDayInSeconds);
    has time been set   -  myClock.isSet();         true if time has been set
    get current time    -  myClock.getTime();       returns a String (HH:MM:SS)
    get current hours   -  myClock.getHours();      returns hours as uint8_t 
    get current minutes -  myClock.getMinutes();    returns minutes as uint8_t
    get current seconds -  myClock.getSeconds();    returns seconds as uint8_t


