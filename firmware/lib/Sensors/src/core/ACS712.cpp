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

/**
 *  Get averaged current measurment
 *  n - number of readings to average
 *  Returns - sensed current in Ampere.
 */
float ACS712::getCurrent(int n) {
    int rawVal = 0;

    for (int i = 0; i < n; ++i) {
        delay(100);
        rawVal += this->read() - this->_calFactor;
    }

    return 0.0264 * (float(rawVal) / n);
}
