#include <Arduino.h>
#include <ESP32Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Myconfig.h>

Servo lsb1, lsb2;
Servo rsb1, rsb2;

Servo RbigS1, RbigS2;

//Small
Servo Rsmall;
Servo Lsmall;


TwoWire Wi = TwoWire(0);

#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(128, 64, &Wi, -1);



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

void Lbig(bool state){
  if (state){
    LDoor(maxBL);
  }else{
    LDoor(minBL);
  }

}


void Rbig(bool state){
  if (state){
    RDoor(maxBR);
  }else{
    RDoor(minBR);
  }

}




void setup(){
  Wi.begin(4, 15);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  lsb1.attach(LbigS1pin);
  lsb2.attach(LbigS2pin);
  rsb1.attach(RbigS1pin);
  rsb2.attach(RbigS2pin);
  Serial.begin(115200);
}

void loop(){
  if(Serial.available()){
      int state = Serial.parseInt();
      Serial.println(state);
      LDoor(state);
  }
  

}