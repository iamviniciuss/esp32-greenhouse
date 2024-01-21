#include <Adafruit_Sensor.h>
#include <SimpleDHT.h>
#include "DHT.h"
#include <MQTT.h>
#include <MQTTClient.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <string.h>
#include "infra/aws_connect.h"
#include "infra/aws_publish_message.h"
#include "infra/environment.h"
#include "infra/certs.h"
#include "infra/wifi.h"
#include "application/manage_water_pump_state.h"
#include "application/soil_collector.h"
#include <WiFiClientSecure.h>
#include "DHT.h"

HTTPClient http;
WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(512);
DHT dht(PIN_SENSOR_TEMPERATURA, DHTTYPE);

float Temperature;
float Humidity;

void setup() {
    
    pinMode(PIN_RELE_COOLER, OUTPUT);
    dht.begin();     

    // Bomba D'agua
    pinMode(PIN_RELE_BOMBA_AGUA, OUTPUT);
    digitalWrite(PIN_RELE_BOMBA_AGUA, HIGH);
    // digitalWrite(PIN_RELE_BOMBA_AGUA, LOW);

    //Lampada
    pinMode(PIN_LAMPADA, OUTPUT);
    digitalWrite(PIN_LAMPADA, HIGH);

    Serial.begin(9600);
    setupWifi();
    connectToAWS(&client, &net);
    consumerCommand();
}

void temperature() {
    Serial.println("**Read temperature");    
    temperatureCollector(&client, &dht);    
    client.loop();
}

void humidity() {
    Serial.println("**Read humidity");

    int waterPumpturnOff = digitalRead(PIN_RELE_BOMBA_AGUA);
    int delayTime = 2000;
    if (!waterPumpturnOff) {
        delayTime = 2000;
    }

    delay(delayTime);
    client.loop();
    delay(delayTime);
    client.loop();
    delay(delayTime);
    soilCollector(&client);    
    client.loop();
}

void loop() {
    Serial.println("*** Start Looping***");
    humidity();
    temperature();
    Serial.println("\n===================================\n");

}

void consumerCommand() {
  Serial.println("\n** Start consumers...\n");
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC_WATER_PUMP);
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC_TEMPERATURE);
  client.onMessage(messageHandlerWaterPump);
}

void messageHandlerWaterPump(String &topic, String &payload) {
    Serial.println("incoming: " + topic + " - " + payload);

    if (topic == AWS_IOT_SUBSCRIBE_TOPIC_WATER_PUMP) {
        manageWaterPumpState(payload);
        return;
    }

    if (topic == AWS_IOT_SUBSCRIBE_TOPIC_TEMPERATURE) {
        manageTemperature(payload);
        return;
    }


    Serial.println("Não existe handler para o topico:" + topic);
}


