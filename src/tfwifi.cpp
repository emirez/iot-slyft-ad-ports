#include <Arduino.h>
#include "tfwifi.h"

const char* ssid     = "CASSINIguest";
const char* password = "Cassini2016!";

//const char* ssid     = "belkin.36ef";
//const char* password = "34e966fb";

void setup_wifi() {
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
