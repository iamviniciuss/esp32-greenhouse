#include <MQTTClient.h>
#include "environment.h"
#include "certs.h"

void sendJsonToAWS(MQTTClient* client, String message, String topic)
{
    bool ok = client->publish(topic, message);
    Serial.println("Success publish: ");
    Serial.print(ok);
    Serial.print("\n\n");
}