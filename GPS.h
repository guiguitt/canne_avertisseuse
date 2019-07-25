
#ifndef GPS_H
#define GPS_H
#include <Arduino.h>
void startGPS();
bool readGPS(bool);

bool outputGPS(void*);
void outputGPS();
bool checkFix();

String getCoord();

float* updatePos();
float getLat();
float getLong();
float getAlti();

bool getPos(int32_t *pos);
#endif //GPS_H
