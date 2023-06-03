#include <Arduino.h>
// #include <ESP32Servo.h>
// #include <Servo.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <FreeRTOS.h>
// #include <Wire.h>
// #include <RCWL_1X05.h>




// // #Project Files
// // #include <hundle.h>
// #include <Myconfig.h>


// // RCWL_1X05 sensor;

// //Big Doors Servos
// Servo lsb1, lsb2;
// Servo rsb1, rsb2;


// //Small Doors Servos
// Servo Rsmall;
// Servo Lsmall;


// // TwoWire Wi = TwoWire(0);

// // #define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
// // Adafruit_SSD1306 display(128, 64, &Wi, -1);


// // #include <ESP32Servo.h>
// #include <Arduino.h>
// #include <Myconfig.h>



// //Big Doors Functions
// void LDoor(int dgree){
  
//     if (dgree < 181){
//       lsb1.write(dgree);
//       lsb2.write(180 - dgree);
//     }
//   // lsb1.detach();
//   // lsb2.detach();
// }


// void RDoor(int dgree){
//   // int dgree = );

//     if (dgree < 181){
//       rsb1.write(dgree);
//       rsb2.write(180 - dgree);
//     }
//   // rsb1.detach();
//   // rsb2.detach();
// }



// //##################################

// //Small Doors Functions
// void Lbig(bool state){
//   if (state){
//     LDoor(maxBL);
//   }else{
//     LDoor(minBL);
//   }
// }


// void Rbig(bool state){

//   if (state){
//     RDoor(maxBR);
//   }else{
//     RDoor(minBR);
//   }

// }

// //##################################

// const int pingPin = 20;
// int inPin = 21;


// long microsecondsToCentimeters(long microseconds)
// {
//   return microseconds / 29 / 2;
// }




// void setup(){
//   // Wire.begin();
  
//   // sensor.setFilter(true); // filter is turned off by default
//   // sensor.setTimeout(50); // 100 ms is recommended, but lower values might work
//   // sensor.setMode(RCWL_1X05::continuous); 
//   // Wi.begin(4, 15)1060;
//   // display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
//   // rsb1.attach(RsmallPin);
//   // lsb1.attach(LsmallPin);
//   rsb1.attach(RbigS1pin);
//   rsb2.attach(RbigS2pin);
//   lsb1.attach(LbigS1pin);
//   lsb2.attach(LbigS2pin);

//   Serial.begin(9600);
// }

// void loop(){
//   long duration, cm;
//   pinMode(pingPin, OUTPUT);
//   digitalWrite(pingPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(pingPin, HIGH);
//   delayMicroseconds(5);
//   digitalWrite(pingPin, LOW);
//   pinMode(pingPin, INPUT);
//   duration = pulseIn(pingPin, HIGH);
//   cm = microsecondsToCentimeters(duration);
//   Serial.print(cm);
//   Serial.print("cm");
//   // if (sensor.update()) {
//   //   Serial.print(sensor.read()); Serial.println(" mm");
  
//   if(Serial.available()){
//     Serial.print(cm);
//     Serial.print("cm");
//   }
//   for (int i = 0; i < 180; i += 100)
//   {
//     LDoor(i);
//     delay(10);
//     RDoor(i + 30);
//     delay(10);
//   }
// }






// void setup(){
//   Serial.begin(115200);
//   pinMode(18, INPUT);
//   pinMode(33, INPUT);
//   pinmode(35, INPUT);

//   }

// void loop(){
//   Serial.println( analogRead(18));

// }


void setup(){
  Serial.begin(9600);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
}

void loop(){
  Serial.print("A0: ");
  Serial.print(analogRead(A0));
  Serial.print(" A1: ");
  Serial.print(analogRead(A1));
  Serial.print(" A2: ");
  Serial.print(analogRead(A2));
  Serial.print(" A3: ");
  Serial.println(analogRead(A3));
  delay(500);
}