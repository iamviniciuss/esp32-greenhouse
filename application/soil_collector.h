// #include "../infra/environment.h"
// #include "../infra/aws_publish_message.h"
// #include <MQTTClient.h>

void soilCollector(MQTTClient* client) {
    String umidadeSolo = String(analogRead(PIN_SENSOR_UMIDADE_SOLO));
    int myInt = atoi(umidadeSolo.c_str());
    // int myHumidity = myInt;
    int myHumidity = (4095 - myInt);
    char myChar[10];
    sprintf(myChar, "%d", myHumidity);
    String myString = String(myChar);
    String httpRequestData = "{\"humidity\":" + myString + ",\"sensor_id\": \""+SENSOR_ID+"\"}";
    Serial.println(httpRequestData);

    sendJsonToAWS(client, httpRequestData, AWS_IOT_PUBLISH_TOPIC_WATER_PUMP);
}

void temperatureCollector(MQTTClient* client, DHT* dht) {
    delay(2000);

    float humidity = dht->readHumidity();
    float temperatureCelcius = dht->readTemperature();

    if (isnan(humidity) || isnan(temperatureCelcius)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }


    DynamicJsonDocument doc(256);
    doc["humidity"] = humidity;
    doc["temperature"] = temperatureCelcius;
    doc["sensor_id"] = TEMPERATURE_SENSOR_ID;

    String jsonString;
    serializeJson(doc, jsonString);
    Serial.println(jsonString);
    sendJsonToAWS(client, jsonString, AWS_IOT_PUBLISH_TOPIC_TEMPERATURE);
}