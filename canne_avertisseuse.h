#include "Lora_Module.h"
#include "Conversion.h"//library to convert data in uint8
#include "GPS.h"
#include <ArduinoLowPower.h>
#


Lora_Module lora;
Conversion conv;

//------------------------------------------
//GPS
#include <timer.h>
Timer <1, micros> timer;  // GPS reader
int32_t latitude = conv.float_int32("43.619883", 5);
int32_t longitude = conv.float_int32("3.851704", 5);
int32_t altitude;
boolean GPS_ENABLE = true;
boolean GPS_ON= false;
unsigned long GPS_timestart;
void start_fix();


//------------------------------------------
//accélérometre
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
Adafruit_MMA8451 mma = Adafruit_MMA8451();
#define mov_level 200 //valeur à partir de la quelle la différence d'accélération sera pris en compte. entre -4048 et 4048  
int X[2] = {0, 0};
int Y[2] = {0, 0};
int Z[2] = {0, 0};
int diff[3];


//******************************************
//Pin
#define GPS_EN 5 // Pin GPS enable
#define SENSOR_PIN A6 // Water sensor pin(D-)
#define BAT_PIN A2 // output of voltage divider bridge


//******************************************
uint8_t batterie;
#define coef_pont 3.8
//#define coef_pont 2


int mesure;



#define alerte_INITIAL 0//initial send 
#define alerte_HEAR 1
#define alerte_WATER  2
#define alerte_MOV  3
#define alerte_BAT  4
int alerte;
enum {
  MONITORING,
  HEARBEAT,
  INITIAL,
};
int STATE = INITIAL;

#define tempo 60000 //en ms
#define nbr_monitoring 60
int compteur = nbr_monitoring;
void sensor();
void Initial();
void send_hearbeat();
void send_all();
