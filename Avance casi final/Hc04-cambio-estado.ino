#include <Arduino.h>
int trig1=18, trig2=22;
int echo1=15, echo2=23;
int pinBuzzer=4;

float duracion1 =0, distancia1 =0;
float duracion2 =0, distancia2 =0;

int frecuencia =2000, canal  =0 , resolucion =8;

int sonido =200;


void setup() {
  Serial.begin(115200);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(2, OUTPUT);
  ledcSetup(canal,frecuencia,resolucion);
  ledcAttachPin(pinBuzzer, 0);
}

bool det1 = false;
void sensor1(){
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duracion1 = pulseIn(echo1, HIGH);
  // Calculating the distance
  //distancia= duracion/58.2;//0.034/2;
  distancia1 = duracion1/120;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distancia1);
}


void sensor2(){
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duracion2 = pulseIn(echo2, HIGH);
  // Calculating the distance
  distancia2= duracion2/120;//0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(duracion2);
}


void loop() {
  sensor1();
  sensor2();
/*   if(duracion >=235 || duracion <)
  //sensor2();
 */
  if (distancia1 >=1 && distancia1 <=20 || (distancia2 >=1 && distancia2 <=20)){
    digitalWrite(2, HIGH);
    ledcWriteTone(0,sonido);
  }
  else{
    digitalWrite(2, LOW);
    ledcWriteTone(0,0);
  }
  delay(100);
}
