
// O endpoint MQTTT para o dispositivo (exclusivo para cada conta AWS, mas compartilhado entre os dispositivos dentro da conta)
#define AWS_IOT_ENDPOINT "********"
// O tópico MQTT em que este dispositivo deve publicar
// Quantas vezes devemos tentar nos conectar ao AWS
#define AWS_MAX_RECONNECT_TRIES 50



#define SENSOR_ID "645d82f4d2d163d2edc380a5"
// O nome do dispositivo. Isso DEVE corresponder ao nome definido no console AWS
#define DEVICE_NAME "esp32/greenhouse/645d82f4d2d163d2edc380a5"

#define AWS_IOT_SUBSCRIBE_TOPIC_WATER_PUMP "esp32/greenhouse/water_pump/sub/645d82f4d2d163d2edc380a5"

#define AWS_IOT_PUBLISH_TOPIC_WATER_PUMP "esp32/greenhouse/water_pump/pub/645d82f4d2d163d2edc380a5"


#define pinSensorUmiSoloA 34
#define rele 22
#define releCooler 21
