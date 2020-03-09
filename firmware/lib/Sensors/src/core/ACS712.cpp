#include "Arduino.h"
#include "Sensors.h"

// constructor
ACS712::ACS712(int pin) : AnalogReader(pin) {}

/**
 *  Manually calibrate current sensor.
 *  calFactor - current calibration factor.
 */
void ACS712::calibrate(int calFactor) {
    long rawVal = 0;

    for (int i = 0; i < 100; ++i) {
        rawVal += read();
    }

    // calculate average
    int cal = rawVal / 100;

    Serial.println(cal);
    if (abs(cal - calFactor) < 1) {
        Serial.print(F("Your calibration factor is good!"));
    } else {
        Serial.print(F("Your calibration factor is: "));
        Serial.println(cal);
    }

    this->_calFactor = cal;
}

float ACS712::getVPP() {
    float result;
    int readValue;       // value read from the sensor
    int maxValue = 0;    // store max value here
    int minValue = 1024; // store min value here

    uint32_t start_time = millis();
    while ((millis() - start_time) < 1000) // sample for 1 Sec
    {
        readValue = this->read();

        // see if you have a new maxValue
        if (readValue > maxValue) {
            /*record the maximum sensor value*/
            maxValue = readValue;
        }

        if (readValue < minValue) {
            /*record the minimum sensor value*/
            minValue = readValue;
        }
    }

    // Subtract min from max
    result = ((maxValue - minValue) * 5.0) / 1024.0;

    return result;
}

int ACS712::getmVPerAmpValue() { return this->_mVperAmp; }