
#include <ArduinoJson.h>

void manageWaterPumpState(String payload) {
    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    bool turnOn = doc["turnOn"];

    if (turnOn == false) {
        digitalWrite(PIN_RELE_BOMBA_AGUA, HIGH);
        Serial.println("Turn Off: Desligar a bomba d'agua: HIGH");
        return;
    }

    Serial.println("Turn on: Ligar a bomba d'agua: LOW");
    digitalWrite(PIN_RELE_BOMBA_AGUA, LOW);
}


void manageTemperature(String payload) {
    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    String command = doc["command"];

    if (command == "TURN_OFF_ALL") {
        digitalWrite(PIN_LAMPADA, HIGH);
        digitalWrite(PIN_RELE_COOLER, HIGH);
        Serial.println("DESLIGAR TODOS OS ATUADORES RELACIONADOS A TEMPERATURA");
        return;
    }

    if (command == "TURN_ON_COOLER") {
        digitalWrite(PIN_RELE_COOLER, LOW);
        digitalWrite(PIN_LAMPADA, HIGH);
        Serial.println("ligar COOLER");
    }else {
        digitalWrite(PIN_RELE_COOLER, HIGH);
        Serial.println("desligar COOLER");
    }

    if (command == "TURN_ON_LIGHT") {
        digitalWrite(PIN_LAMPADA, LOW);
        digitalWrite(PIN_RELE_COOLER, HIGH);
        Serial.println("ligar LAMPADA");
    } else {
        digitalWrite(PIN_LAMPADA, HIGH);
        Serial.println("desligar LAMPADA");
    }

}

