#include <MQTTClient.h>
#include "environment.h"
#include "certs.h"

void sendJsonToAWS(MQTTClient* client, String message)
{
    // StaticJsonDocument<200> doc;
    // doc["time"] = "4444";
    // doc["sensor_a0"] = "123";

    // char jsonBuffer[512];
    // serializeJson(doc, jsonBuffer);

    // bool ok = client->publish(AWS_IOT_PUBLISH_TOPIC_WATER_PUMP, jsonBuffer);
    bool ok = client->publish(AWS_IOT_PUBLISH_TOPIC_WATER_PUMP, message);
    Serial.println("Success publish: ");
    Serial.print(ok);
    Serial.print("\n\n");
}