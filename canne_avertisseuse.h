#include "Lora_Module.h"
#include "Conversion.h"//library to convert data in uint8
#include "GPS.h"
#include <ArduinoLowPower.h>

Lora_Module lora;
Conversion conv;

//------------------------------------------
//gps
#include <timer.h>
Timer <1, micros> timer;  // GPS reader
int32_t latitude = conv.float_int32("43.619883", 5);
int32_t longitude = conv.float_int32("3.851704", 5);
int32_t altitude;
boolean GPS_ENABLE = true;
//------------------------------------------
//accélérometre
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
Adafruit_MMA8451 mma = Adafruit_MMA8451();
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
//#define coef_pont 3.8
#define coef_pont 2


int mesure;
#define alerte_INITIAL 0//initial send 
#define alerte_HEAR 0
#define alerte_WATER  1
#define alerte_MOV  2
#define alerte_BAT  3
int alerte;
enum {
  MONITORING,
  HEARBEAT,
  SEND,
  INITIAL,
};
int STATE = INITIAL;

#define tempo 60000 //en ms
int compteur = 60;
void sensor();
void Initial();
void send_hearbeat();
void send_all();
