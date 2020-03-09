#include <ESP8266WiFi.h>
#include <Sensors.h>

// Constants
#define DATA_PUBLISHING_DELAY 60000 // 1min

// sensor object (pin -> A0)
ACS712 acs712(0);

long lastReconnectAttempt = 0;

void setup() {
    // initialize serial
    Serial.begin(9600);

    // Manually calibrate the ACS712 current sensor.
    // acs712.calibrate();

    delay(100);
}

void loop() {
    long now = millis();

    if (now - lastReconnectAttempt > DATA_PUBLISHING_DELAY) {
        lastReconnectAttempt = now;

        // Get averaged current measurment for 10 readings
        float acs712Currrent = acs712.getCurrent(10);
        Serial.print(acs712Currrent);
        Serial.println(F(" [mA]"));
    }
}
