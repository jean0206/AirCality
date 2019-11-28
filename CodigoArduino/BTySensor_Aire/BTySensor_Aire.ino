
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
SoftwareSerial miBT(2,3);
int s_analogica_mq135=0;


void setup() {
  
Serial.begin(9600);

Serial.begin(9600);
  //Serial.println("Listo");
  miBT.begin(38400);

}

void loop() {
  
  s_analogica_mq135=analogRead(0);
  // put your main code here, to run repeatedly:

  //Serial.print(s_analogica_mq135,DEC);
  //Serial.print(s_analogica_mq135,DEC);
  miBT.print(s_analogica_mq135,DEC);
  delay(3500);

  if(miBT.available())    //lee BT y envia a Arduino
  Serial.write(miBT.read());

  if(Serial.available())
  miBT.write(Serial.read());

}
