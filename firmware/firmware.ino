#include <ESP8266WiFi.h>
#include <Sensors.h>

// Network
#define WIFI_SSID "............"
#define WIFI_PASSWORD "............"

// Constants
#define DATA_PUBLISHING_DELAY 10000 // 10sec
#define SERIAL_DEBUG_PORT 115200

// sensor object (pin -> A0)
ACS712 acs712(0);

long lastReconnectAttempt = 0;

WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;

/**
 *  Handle WiFi Connectivity
 */
void connectToWifi() {
    Serial.println();
    Serial.print("[WiFi] Connecting to ");
    Serial.println(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

/**
 *  WiFi Connect event handler
 */
void onWifiConnect(const WiFiEventStationModeGotIP &event) {
    Serial.println();
    Serial.println("[WiFi] Connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

/**
 *  WiFi Disconnect event handler
 */
void onWifiDisconnect(const WiFiEventStationModeDisconnected &event) {
    Serial.println("[WiFi] Disconnected.");

    delay(1000);
    connectToWifi();
}

void setup() {
    // initialize serial
    Serial.begin(SERIAL_DEBUG_PORT);

    wifiConnectHandler    = WiFi.onStationModeGotIP(onWifiConnect);
    wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);

    // initialize & connect to WiFi
    connectToWifi();

    delay(100);
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        long now = millis();

        int maxValue = 0;    // store max value here
        int minValue = 1024; // store min value here

        if (now - lastReconnectAttempt > DATA_PUBLISHING_DELAY) {
            lastReconnectAttempt = now;

            double voltage = acs712.getVPP();
            double VRMS    = (voltage / 2.0) * 0.707; // root 2 is 0.707
            double AmpsRMS = (VRMS * 1000) / acs712.getmVPerAmpValue();

            Serial.println();
            Serial.print("Reading current:");
            Serial.print(AmpsRMS);
            Serial.println(" Amps RMS");
        }
    }
}
