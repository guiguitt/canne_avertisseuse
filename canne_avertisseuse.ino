#include "canne_avertisseuse.h"
void setup() {
  Serial.begin(115200);

  //********GPS initialization********************************************
  pinMode(GPS_EN, OUTPUT);
  digitalWrite(GPS_EN, GPS_ENABLE);
  startGPS();
  if (GPS_ENABLE) start_fix();

  timer.every(1, outputGPS);
  //********LoRa initialization********************************************
  Serial.println("-------------------------------LoRa------------------------------");
  Serial.println("initialisation...");
  lora.Init();
  lora.info_connect();

  //********Sensor initialization********************************************

  pinMode(SENSOR_PIN, INPUT);
  digitalWrite(SENSOR_PIN, LOW);
  pinMode(BAT_PIN, INPUT);
  if (!mma.begin()) {
    Serial.println("Accelerometre not found");
  }
  mma.setRange(MMA8451_RANGE_2_G);
  sensor();
}

void loop() {


  //********GPS read********************************************

  if (GPS_ENABLE == true && (millis() - GPS_timestart < 300000)) {
    digitalWrite(GPS_EN, GPS_ENABLE);
    outputGPS();
    if (readGPS(false)) {
      timer.tick();
      if (checkFix()) {
        Serial.println("fix...");
        Serial.print("Lat:");
        Serial.println(getLat(), 5);
        Serial.print("Long:");
        Serial.println(getLong(), 5);
        Serial.print("Alti :");
        Serial.println(getAlti(), 5);
        latitude = conv.float_int32(getLat(), 5);
        longitude = conv.float_int32(getLong(), 5);
        altitude = conv.float_int16(getAlti(), 1);
        GPS_ENABLE = false;
        digitalWrite(GPS_EN, GPS_ENABLE);
      }
    }
  }
  else {
    digitalWrite(LED_BUILTIN, HIGH);
    switch (STATE) {
      //********INITIAL STATE********************************************
      case INITIAL:
        Serial.println("state:initial");
        sensor();
        alerte = alerte_INITIAL;
        send_all();
        STATE = MONITORING;
        break;
      //********INITIAL MONITORING********************************************
      case MONITORING:
        Serial.println("state:monitoring");
        sensor();
        diff[0] = abs(X[0] - X[1]);
        diff[1] = abs(Y[0] - Y[1]);
        diff[2] = abs(Z[0] - Z[1]);
        Serial.println("---------------");
        if ((diff[0] > mov_level) || (diff[1] > mov_level) || (diff[1] > mov_level)) {
          alerte =  alerte_MOV;
          send_all();
          start_fix();
          Serial.println("ALERTE 2 ");
        }
        else if (mesure > 1000) {
          alerte = alerte_WATER;
          send_all();
          start_fix();
          Serial.println("ALERTE 1 ");

        }
        else if ((batterie / 32) * 1, 7 < 1 ) {
          alerte = alerte_BAT;
          send_all();
          start_fix();
          Serial.println("ALERTE 3");
        }
        else {
          if (compteur == 0) {
            Serial.print("hearbeat");
            alerte = alerte_HEAR;
            Serial.print(alerte);
            STATE = MONITORING;
            send_hearbeat();
            start_fix();
            compteur = nbr_monitoring;
          }
          compteur--;
          Serial.println("compteur:" + String(compteur));
        }
        break;
    }
    //LowPower.deepSleep(tempo - 3000); // veille profonde seul la RTC reste allumer, temps de reveille long
    //LowPower.sleep(tempo);//veille mode
    //LowPower.idle(tempo);// stanby mode,temps de reveille rapide
    delay(tempo);// mise en pause classique, consommation important, pas de temps de reveille
  }

}
void sensor() {
  analogReference(AR_DEFAULT);
 float mem = ((analogRead(BAT_PIN) / 1023 ) * 3.3 * coef_pont) - 11;
  if (batterie < 0) {
  batterie = 0;
}
else {
  batterie = conv.float_uint8((mem / 1.7) * 32,1);
}

Serial.println("Batterie:" + String(batterie));
  mesure = analogRead(SENSOR_PIN);
  Serial.println("sensor:" + String(mesure));
  mma.read();
  X[1] = X[0];
  Y[1] = Y[0];
  Z[1] = Z[0];
  X[0] = mma.x;
  Serial.println("X:" + String(X[0]));
  Y[0] = mma.y;
  Serial.println("Y:" + String(Y[0]));
  Z[0] = mma.z;
  Serial.println("Z:" + String(Z[0]));
}
void send_all() {
  Serial.println("envoie totale");
  uint8_t buffer[9];
  buffer[0] = (uint8_t)(alerte << 5) + (uint8_t)batterie & 0b11111;
  buffer[1] = (uint8_t)(longitude >> 24);
  buffer[2] = (uint8_t)(longitude >> 16);
  buffer[3] = (uint8_t)(longitude >> 8);
  buffer[4] = (uint8_t)longitude;
  buffer[5] = (uint8_t)(latitude >> 24);
  buffer[6] = (uint8_t)(latitude >> 16);
  buffer[7] = (uint8_t)(latitude >> 8);
  buffer[8] = (uint8_t)latitude;
  lora.send(buffer, 9);
}
void send_hearbeat() {
  uint8_t buffer[1];
  buffer[0] = (uint8_t)(alerte << 5) + (uint8_t)batterie;
  lora.send(buffer, 1);
}
void start_fix() {
  GPS_ENABLE = GPS_ON;
  GPS_timestart = millis();
}
