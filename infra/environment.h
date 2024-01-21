
// O endpoint MQTTT para o dispositivo (exclusivo para cada conta AWS, mas compartilhado entre os dispositivos dentro da conta)
#define AWS_IOT_ENDPOINT "ajjur8f2g6sva-ats.iot.us-east-1.amazonaws.com"
// O tópico MQTT em que este dispositivo deve publicar
// Quantas vezes devemos tentar nos conectar ao AWS
#define AWS_MAX_RECONNECT_TRIES 50



#define SENSOR_ID "645d82f4d2d163d2edc380a5"
#define TEMPERATURE_SENSOR_ID "645d83920442ac5161e0cc53"
// O nome do dispositivo. Isso DEVE corresponder ao nome definido no console AWS
#define DEVICE_NAME "esp32/greenhouse/645d82f4d2d163d2edc380a5"

#define AWS_IOT_SUBSCRIBE_TOPIC_WATER_PUMP "esp32/greenhouse/water_pump/sub/645d82f4d2d163d2edc380a5"
#define AWS_IOT_SUBSCRIBE_TOPIC_TEMPERATURE "esp32/greenhouse/temperature/sub/645d82f4d2d163d2edc380a5"

#define AWS_IOT_PUBLISH_TOPIC_WATER_PUMP "esp32/greenhouse/water_pump/pub"
#define AWS_IOT_PUBLISH_TOPIC_TEMPERATURE "esp32/greenhouse/temperature/pub"


#define PIN_SENSOR_UMIDADE_SOLO 34
#define PIN_RELE_BOMBA_AGUA 23
#define PIN_RELE_COOLER 21
#define PIN_SENSOR_TEMPERATURA 4
#define PIN_LAMPADA 18
#define DHTTYPE DHT22
