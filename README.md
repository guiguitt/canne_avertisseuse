# Canne-avertisseuse
## Hardware
<img src=https://user-images.githubusercontent.com/32598441/61876867-1e945d80-aeee-11e9-9c76-71c7ecac0d3f.png width="500" />

### Compenent
* Arduino MKR WAN 1300 - 28€(25/07/2019) https://bit.ly/2GuevrS
* Antenne for 868 MHZ - ~5€ https://bit.ly/2SDVVCL
* GPS Adafruit 745 - 41€  https://bit.ly/2LHuB5R
* IMU Adafruit MMA8451 - 9€ https://bit.ly/2Mcii0F

* 2× Female connector 14 in line -3,41€ https://fr.rs-online.com/web/p/fiches-femelles-pour-ci/7679347/ 
* Females connector 8 and 9 
* 2× terminal block connector https://fr.rs-online.com/web/p/products/1814377/
* regulateur DC/DC 4,6-32V ->3,3V https://fr.rs-online.com/web/p/regulateurs-a-decoupage/7553429/
* potentiometer resistance
## setting
to start compiling the program and uploading it. By reading the serial port you can get the ```DEV_ID``` to configure the device on The Things network. 
### Commissioning.h
```
#define APP_EUI "123456789ABCDEF"
#define APP_KEY "123456789ABCDEF"
```


