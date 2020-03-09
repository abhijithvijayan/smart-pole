#include "Arduino.h"
#include "Sensors.h"

#define ANALOG_INPUT_PIN 0

AnalogReader::AnalogReader(int pin) { this->_pin = pin; }

float AnalogReader::read() { return analogRead(ANALOG_INPUT_PIN); }
