#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}
 const String webName = "FAM CUETO-2.4GHZ";
 const String password = "cuetosalazar573";

WebServer server (80); 
void loop() {
  digitalWrite(2,LOW);
  Serial.println("desConecting to wifi");
  delay(1000);
  WiFi.disconnect();
  Serial.println("Conectando a "+ webName);
  //conectamos el esp32 a internet
  WiFi.mode(WIFI_STA);
  WiFi.begin(webName, password);
  //intentamos conectar a la red
  while (WiFi.status()!= WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  //logramos la conexion
  Serial.println();
  Serial.println(WiFi.localIP());

}