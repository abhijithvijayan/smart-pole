#include "Arduino.h"
#include "Sensors.h"

const int ANALOG_INPUT_PIN = A0;

AnalogReader::AnalogReader(int pin) { this->_pin = pin; }

float AnalogReader::read() { return analogRead(ANALOG_INPUT_PIN); }
