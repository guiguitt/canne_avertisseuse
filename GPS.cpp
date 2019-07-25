#include "GPS.h"
#include <Adafruit_GPS.h>

#include "Adafruit_ZeroTimer.h"

#define GPSSerial Serial1

// Connect to the GPS on the hardware port
Adafruit_GPS GPS(&GPSSerial);

float lastPos[2]; // Last known position latitude & longitude

void startGPS(){
  
  GPS.begin(9600);

  // Mode GGA et RMC
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  // Set the update rate
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); 
  
  // Request updates on antenna status, comment out to keep quiet
  GPS.sendCommand(PGCMD_ANTENNA);
}

bool outputGPS(void*){
  char c = GPS.read();
  //Serial.write(c);
  return true;
}

void outputGPS(){
  GPS.read();
}

bool readGPS(bool verb){
  
  if(GPS.newNMEAreceived()){
     if (!GPS.parse(GPS.lastNMEA()))   // this also sets the newNMEAreceived() flag to false
      return false;
    if(verb){
      Serial.print("\nTime: ");
      Serial.print(GPS.hour, DEC); Serial.print(':');
      Serial.print(GPS.minute, DEC); Serial.print(':');
      Serial.print(GPS.seconds, DEC); Serial.print('.');
      Serial.println(GPS.milliseconds);
      Serial.print("Date: ");
      Serial.print(GPS.day, DEC); Serial.print('/');
      Serial.print(GPS.month, DEC); Serial.print("/20");
      Serial.println(GPS.year, DEC);
      Serial.print("Fix: "); Serial.print((int)GPS.fix);
      Serial.print(" quality: "); Serial.println((int)GPS.fixquality); 
      
      if (GPS.fix) {
        Serial.print("Location: ");
        Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
        Serial.print(", "); 
        Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
        Serial.print("Location (in degrees, works with Google Maps): ");
        Serial.print(GPS.latitudeDegrees, 4);
        Serial.print(", "); 
        Serial.println(GPS.longitudeDegrees, 4);
        
        Serial.print("Speed (knots): "); Serial.println(GPS.speed);
        Serial.print("Angle: "); Serial.println(GPS.angle);
        Serial.print("Altitude: "); Serial.println(GPS.altitude);
        Serial.print("Satellites: "); Serial.println((int)GPS.satellites);
      }
    }

      if(GPS.fix){
        lastPos[0] = GPS.latitudeDegrees;
        lastPos[1] = GPS.longitudeDegrees;
      }

  }

  return true;
}

String getCoord(){
  String str;
  
  //if(GPS.fix){
    str = String(GPS.latitudeDegrees) + "," + String(GPS.longitudeDegrees);
  //}
  return str;
}

float* updatePos(){
  lastPos[0] = GPS.latitudeDegrees;
  lastPos[1] = GPS.longitudeDegrees;

  return lastPos;
}

float getLat(){
  return GPS.latitudeDegrees;
}

float getLong(){
  return GPS.longitudeDegrees;
}
float getAlti(){
  return GPS.altitude;
}

bool checkFix(){
  return GPS.fix;
}

bool getPos(int32_t *pos){

  pos[0] = GPS.latitudeDegrees*100000;
  pos[1] = GPS.longitudeDegrees*100000;

  return true;
}
