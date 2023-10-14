#include <Arduino.h>
#include "WiFi.h"
#include "ThingSpeak.h"

unsigned long CHANNEL_ID = 2303980;
const char * apiKey = "HHH0AW3UE2HTB25R";

WiFiClient client;

#define WIFI_TIMEOUT_MS 20000
#define WIFI_NETWORK "HUAWEI-2.4G-S444"
#define WIFI_PASSWORD "qP75m4Xf"

void connectToWiFi(){
  Serial.print("Connecting to Wifi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

  unsigned long startAttempTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttempTime < WIFI_TIMEOUT_MS){
    Serial.print(".");
    delay(100);
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Fallo");
  }
  else{
    Serial.print("Conectado");
    Serial.println(WiFi.localIP());
  }
}
void setup(){
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  connectToWiFi();
  ThingSpeak.begin(client);
}

void loop(){
  int a=digitalRead(2);
  Serial.println(a);
  if(a==HIGH){
    Serial.println("Objeto Detectado");
  }
  else{
    Serial.println("Objeto no Detectado");
  }

  ThingSpeak.setField(1, a);
  ThingSpeak.writeFields(CHANNEL_ID,apiKey);
  delay(1000);
}