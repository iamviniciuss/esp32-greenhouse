// #include "../infra/environment.h"
// #include "../infra/aws_publish_message.h"
// #include <MQTTClient.h>

void soilCollector(MQTTClient* client) {
    String umidadeSolo = String(analogRead(pinSensorUmiSoloA));
    int myInt = atoi(umidadeSolo.c_str());
    int myHumidity = myInt;
    // int myHumidity = (4095 - myInt);
    char myChar[10];
    sprintf(myChar, "%d", myHumidity);
    String myString = String(myChar);
    String httpRequestData = "{\"humidity\":" + myString + ",\"sensor_id\": \""+SENSOR_ID+"\"}";
    Serial.println(httpRequestData);

    sendJsonToAWS(client, httpRequestData, AWS_IOT_PUBLISH_TOPIC_WATER_PUMP);
}

void temperatureCollector(MQTTClient* client) {
    Serial.println("temperature collector");
}