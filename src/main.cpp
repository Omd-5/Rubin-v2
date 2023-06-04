#include <Arduino.h> // Arduino Core for ESP32
// #include <ESP32Servo.h>
#include <Servo.h> // Servo Library
#include <SoftwareSerial.h>
#include <Myconfig.h>
#include <FreeRTOS_AVR.h>
#include <NewPing.h>
#include <hundle.h>

SoftwareSerial PlasticSensorPort(pspR, pspT); // RX, TX


//Big Doors Servos
Servo lsb1, lsb2;
Servo rsb1, rsb2;


//Small Doors Servos
Servo Rsmall;
Servo Lsmall;
Servo fsb;


//Big Doors Functions
void LDoor(int dgree){
  
    if (dgree < 181){
      lsb1.write(dgree);
      lsb2.write(180 - dgree);
    }
}



void RDoor(int dgree){
  // int dgree = );

    if (dgree < 181){
      rsb1.write(dgree);
      rsb2.write(180 - dgree);
    }
}


//##################################

//Small Doors Functions
void LbigOpen(bool state){
  if (state){
    LDoor(maxBL);
  }else{
    LDoor(minBL);
  }
}


void RbigOpen(bool state){

  if (state){
    RDoor(maxBR);
  }else{
    RDoor(minBR);
  }

}


void LsmallOpen(bool state){
  if (state){
    Lsmall.write(maxSL);
  }else{
    Lsmall.write(minSL);
  }
}

void RsmallOpen(bool state){
  if (state){
    Rsmall.write(maxSR);
  }else{
    Rsmall.write(minSR);
  }
}



// TaskHandle_t frontDoor = NULL;

void frontDoor(void *pvParameters){
  NewPing sonar(trig1, echo1, 200); // NewPing setup of pins and maximum distance.
  
  for(;;){
    int distance = sonar.ping_cm();
  if (distance < 10) { // If the distance is less than 10cm, open the door
    fsb.write(maxF);
    vTaskResume(checkElemntP1H);
    vTaskDelay(10000); // Wait for 100ms before taking another measurement
  } else { // Else, close the door
    fsb.write(minF);
  }
  
  }
}



TaskHandle_t checkElemntP1H = NULL;

void checkElemntP1(void *pvParameters){
  NewPing sonar(trig2, echo2, 200); 
  for(;;){
    int distance = sonar.ping_cm();
  if (distance < checkElementDistance ) { // If the distance is less than 10cm, open the door
    if (digitalRead(metal) == LOW){
      LbigOpen(true);
      vTaskDelay(1500); // Wait for 100ms before taking another measurement
      LbigOpen(false);
    }else{
      RbigOpen(true);
      vTaskDelay(1500); // Wait for 100ms before taking another measurement
      RbigOpen(false);
    }
    
  }
  }
}

void PlasticSensor(){
 String SRead = PlasticSensorPort.read();
  int A1 = getValue(inputString, ',', 0);
  int A2 = getValue(inputString, ',', 1);
  int A3 = getValue(inputString, ',', 2);
  int A4 = getValue(inputString, ',', 3);
  
  upThen(A1, plSens);
  upThen(A2, plSens);
  upThen(A3, plSens);
  upThen(A4, plSens);
}






//##################################



void setup(){
  //..Set Serials
  PlasticSensorPort.begin(9600);
  Serial.begin(9600);

  //..Set Pins
  pinMode(metal, INPUT);
  

  //..Attach Servos
  rsb1.attach(RbigS1pin);
  rsb2.attach(RbigS2pin);
  lsb1.attach(LbigS1pin);
  lsb2.attach(LbigS2pin);
  Rsmall.attach(RsmallPin);
  Lsmall.attach(LsmallPin);

  //..Set Servos to default position
  LDoor(minBL);
  RDoor(minBR);
  LsmallOpen(false);
  RsmallOpen(false);

  //..Set Serial
  Serial.begin(9600);
  Serial.println("Start...");
  delay(1000);
  Serial.println("Rubbin V2.0");

//FreeRTOS Tasks
  xTaskCreate(
    frontDoor,          /* Task function. */
    "frontDoor",        /* String with name of task. */
    10000,              /* Stack size in bytes. */
    NULL,               /* Parameter passed as input of the task */
    1,                  /* Priority of the task. */
    NULL);              /* Task handle. */
  
  xTaskCreate(
    checkElemntP1,          /* Task function. */
    "checkElemntP1",        /* String with name of task. */
    10000,              /* Stack size in bytes. */
    NULL,               /* Parameter passed as input of the task */
    1,                  /* Priority of the task. */
    checkElemntP1H);              /* Task handle. */
}

if (checkElemntP1H != NULL){
  vTaskSuspend(checkElemntP1H);
}

void loop(){

}
























//===========Test
//##################################
// void loop(){
  
//     //..Read Serial
//     if (Serial.available() > 0){
//       String data = Serial.readString();
//       Serial.println(data);
//       if (data == "LbigOpen"){
//         LbigOpen(true);
//       }else if (data == "LbigClose"){
//         LbigOpen(false);
//       }else if (data == "RbigOpen"){
//         RbigOpen(true);
//       }else if (data == "RbigClose"){
//         RbigOpen(false);
//       }else if (data == "LsmallOpen"){
//         LsmallOpen(true);
//       }else if (data == "LsmallClose"){
//         LsmallOpen(false);
//       }else if (data == "RsmallOpen"){
//         RsmallOpen(true);
//       }else if (data == "RsmallClose"){
//         RsmallOpen(false);
//       }
//     }
// }
