
#include <ArduinoJson.h>

void manageWaterPumpState(String payload) {
    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    bool turnOn = doc["turnOn"];

    if (turnOn == false) {
        digitalWrite(rele, HIGH);
        Serial.println("Turn Off: Desligar a bomba d'agua: HIGH");
        return;
    }

    Serial.println("Turn on: Ligar a bomba d'agua: LOW");
    digitalWrite(rele, LOW);
}


void manageTemperature(String payload) {
    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    String command = doc["command"];

    if (command == "TURN_OFF_ALL") {
        Serial.println("DESLIGAR TODOS OS ATUADORES RELACIONADOS A TEMPERATURA");
        return;
    }

    if (command == "TURN_ON_COOLER") {
        Serial.println("ligar COOLER");
    }else {
        Serial.println("desligar COOLER");
    }

    if (command == "TURN_ON_LIGHT") {
        Serial.println("ligar LAMPADA");
    } else {
        Serial.println("desligar LAMPADA");
    }

}

