#include "Bibliotecas.h"

WiFiUDP udp;//Cria um objeto "UDP".

String hora_completa;//Váriavel que armazenara o horario do NTP.

// Variaveis do timer
// Timer t;
// unsigned long minuto = 60000;

// AWS INIT
#define DEBUG
// #define TEST
// Criacao de credenciais constantes
void callback(char* topic, byte* payload, unsigned int length);
String DEVICE_ID;
String SSID1;
String PWD1;
String SSID2;
String PWD2;
String ADM_COD;
String HOSTNAME_OTA;
String PREFIX_TOPIC;
String THINGNAME;
// String VERSAO;

// Criacao de topicos
String TOPIC_PUB_CAD;
String TOPIC_SUB_CAD;
String TOPIC_PUB_REG;
String TOPIC_SUB_REG;
String TOPIC_SUB_UPDATE;
String TOPIC_PUB_STATUS;

// Variaveis de envio e conexoes
String return_message;
String versao;

WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

// -----------------------------------------------------------------
//Saidas digiais
#define pin_Y1 13
#define pin_Y2 12
#define pin_Y3 27
#define pin_Y4 26
#define pin_Y5 25
#define pin_Y6 33
#define pin_Y7 32
#define pin_Y8 4

//Entradas digitais
#define pin_X1 15
#define pin_X2 34
#define pin_X3 35
#define pin_X4 5
#define pin_X5 18
#define pin_X6 19
#define pin_X7 14
#define pin_X8 36

//Entradas analógicas
#define pin_AI1 36

//Saídas analógicas
#define pin_AO1 23

//Pinos auxiliares
#define ENTX_pin 2 //Pino de comunicação RS485

int saida = 0;
unsigned long tmr_saida = 0;

// ------------------------
const int pinoSensor = pin_AI1; //PINO UTILIZADO PELO SENSOR
int valorLido; //VARIÁVEL QUE ARMAZENA O PERCENTUAL DE UMIDADE DO SOLO

int analogSoloSeco = 590; //VALOR MEDIDO COM O SOLO SECO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
int analogSoloMolhado = 250; //VALOR MEDIDO COM O SOLO MOLHADO (VOCÊ PODE FAZER TESTES E AJUSTAR ESTE VALOR)
int percSoloSeco = 0; //MENOR PERCENTUAL DO SOLO SECO (0% - NÃO ALTERAR)
int percSoloMolhado = 100; //MAIOR PERCENTUAL DO SOLO MOLHADO (100% - NÃO ALTERAR)
int UmidadePercentualTruncada;
float UmidadePercentualLida;
// -------------------------
