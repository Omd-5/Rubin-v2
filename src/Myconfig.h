//------------------Config------------------

//#######Other-CONFIG##############
#define metal 13

#define pspT 12 //Plastic Sensor TX
#define pspR 11 //---------------RX
int plSens = 923; //Plastic Sensor Value


//ULTRA SONIC CONFIG
//---------outside-------------
#define trig1 12 //Front door Sensor
#define echo1 3
//---------inside-------------
#define trig2 11 //check element Sensor
#define echo2 10
int checkElementDistance = 7; //to callbrate distance between 
                              //the sensor and the element when throw it.


//#######Servo-CONFIG##############
//======Fornt-Door========
#define fsbp 1 //Front door ServoP
int minF = 0; //Minmum angle to close the door
int maxF = 180; //Maxmum angle to open the door

//-----------Big Doors-------------
//-- Left door
int  minBL = 100; //Minmum angle to close the door
int maxBL= 29; //Maxmum angle to open the door
#define LbigS1pin 4
#define LbigS2pin 5

//--Right door
#define minBR 0
#define maxBR 100
#define RbigS1pin 8
#define RbigS2pin 9
//##################################


//Small Doors Config

#define RsmallPin 2

int minSR = 0; //--Right door
int maxSR = 0; //------------------------

#define LsmallPin 4

int minSL = 0; //--Right door
int maxSL = 0; //------------------------