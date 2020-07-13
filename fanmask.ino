#include <DHT.h>

#define Type DHT11

int sensorPin=6;
int motorPin1=9;
int motorPin2=11;
float temp;
float maxtemp=23;
;

DHT HT(sensorPin,Type);


void setup() {
HT.begin();
Serial.begin(9600);
delay(400);
pinMode(motorPin1,OUTPUT);
pinMode(motorPin2,OUTPUT);

}

void loop() {
temp=HT.readTemperature();
Serial.print(temp);
delay(4000);
if (temp>maxtemp){
  digitalWrite(motorPin1,HIGH);
  digitalWrite(motorPin2,HIGH);

}
else {
  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
}
}
