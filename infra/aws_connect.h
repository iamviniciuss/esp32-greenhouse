#include <MQTT.h>
#include <MQTTClient.h>
// #include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager
#include <HTTPClient.h>
// #include <ArduinoJson.h>
// #include <string.h>
#include "environment.h"
#include "certs.h"
// #include <PubSubClient.h>
#include <WiFiClientSecure.h>




void connectToAWS(MQTTClient* client, WiFiClientSecure* net)
{
    net->setCACert(AWS_CERT_CA);
    net->setCertificate(AWS_CERT_CRT);
    net->setPrivateKey(AWS_CERT_PRIVATE);

    client->begin(AWS_IOT_ENDPOINT, 8883, *net);
    int retries = 0;

    Serial.print("Connecting to AWS IOT");
    while (!client->connect(DEVICE_NAME) && retries < AWS_MAX_RECONNECT_TRIES) {
        Serial.print(".");
        delay(100);
        retries++;
    }
 
    if(!client->connected()){
        Serial.println(" Tempo esgotado!");
        return;
    }
    
    Serial.println("Conectado!");

    return;
}

// MQTTClient AAconnectToAWS(MQTTClient* pclient, WiFiClientSecure net)
// {
    // MQTTClient client = MQTTClient();

    // net->setCACert(AWS_CERT_CA);
    // net->setCertificate(AWS_CERT_CRT);
    // net->setPrivateKey(AWS_CERT_PRIVATE);

    // client.begin(AWS_IOT_ENDPOINT, 8883, net);
    // int retries = 0;

    // Serial.print("Connecting to AWS IOT");
    // while (!client.connect(DEVICE_NAME) && retries < AWS_MAX_RECONNECT_TRIES) {
    //     Serial.print(".");
    //     delay(100);
    //     retries++;
    // }
 
    // if(!client.connected()){
    //     Serial.println(" Tempo esgotado!");
    //     return client;
    // }
    
    // Serial.println("Conectado!");
    // *pclient = client;

    // return client;
// }