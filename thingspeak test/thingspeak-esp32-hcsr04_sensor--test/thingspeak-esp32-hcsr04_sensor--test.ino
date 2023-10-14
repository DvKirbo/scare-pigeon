#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "ThingSpeak.h"


//wifi connection
const String webName = "FAM CUETO-2.4GHZ";
const String password = "cuetosalazar573";
unsigned long channelID = 854224;
const char * apiKey = "S7SYIZUK9AITN02N";
WebServer server (80); 
WiFiClient cliente;
int a;
//sensor hc sr04
const int echo = 12;
const int trig = 13;
long duracion;
long distancia;

void sensor(){
  //digitalWrite(trig, HIGH);
  //delayMicroseconds(10);
  //pingTravelTime= pulseIn(echo, HIGH);
  //delay(25);
  //digitalWrite(trig, LOW);
  //distancia = pingTravelTime/58.2;
  //Serial.print(pingTravelTime);
  //Serial.print("   ");
  //Serial.println(distancia);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duracion = pulseIn(echo, HIGH);
  // Calculating the distance
  distancia= duracion/58.2;//0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distancia);
}

void setup() {
  //pines sensor distancia
  
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(115200);
  Serial.println("desConecting to wifi");
  WiFi.disconnect();
  Serial.println("Conectando a "+ webName);
  WiFi.mode(WIFI_STA);
  WiFi.begin(webName, password);
  Serial.println();
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(cliente);
  
}
void loop() {
  sensor();
  delay(2000);

  ThingSpeak.setField(1, distancia);
  ThingSpeak.writeFields(channelID, apiKey);
}