#include <MQTTClient.h>
#include "environment.h"
#include "certs.h"

void sendJsonToAWS(MQTTClient* client, String message, String topic)
{
    bool ok = client->publish(topic, message);
    Serial.print("\nSuccess publish: ");
    Serial.print(ok);
    if (!ok) {
        Serial.print("\nError: ");
        Serial.print(client->lastError());
    }
    Serial.print("\n\n");
}