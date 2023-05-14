
#include <ArduinoJson.h>

void manageWaterPumpState(String payload) {
    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    bool turnOn = doc["turnOn"];

    if (turnOn == false) {
        digitalWrite(rele, HIGH);
        Serial.print("Turn Off: Desligar a bomba d'agua: HIGH");
        return;
    }

    Serial.print("Turn on: Ligar a bomba d'agua: LOW");
    digitalWrite(rele, LOW);
}

