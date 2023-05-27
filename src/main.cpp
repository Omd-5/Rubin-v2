#include <Arduino.h>
#include <ESP32Servo.h>


//Big Doors 
#define LbigS1pin 12
#define LbigS2pin 11

#define RbigS1pin 12
#define RbigS2pin 11

Servo lsb1, lsb2;
Servo rsb1, rsb2;

Servo RbigS1, RbigS2;

//Small
Servo Rsmall;
Servo Lsmall;


void LDoor(int dgree){
    if (dgree < 181){
      lsb1.write(dgree);
      lsb2.write(180 - dgree);
    }
}

void RDoor(int dgree){
    if (dgree < 181){
      rsb1.write(dgree);
      rsb2.write(180 - dgree);
    }
}

void setup(){
  lsb1.attach(LbigS1pin);
  lsb2.attach(LbigS2pin);
  Serial.begin(115200);
}

void loop(){
  if(Serial.available()){
      int state = Serial.parseInt();
      Serial.println(state);
      LDoor(state);
  }
  

}



  