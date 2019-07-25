#define OVER_THE_AIR_ACTIVATE 1
/*OTAA->1
 *ABP->0
 */
#define DutyCycle     1 // respect ou non des 1% de transmission du LoRa uniquement pour les teste (par défaut 1)
#define PublicNetwork 1 // 1 par défaut
#define DataRate      0// vitesse d'envoie 
/*faible vitesse d'envoie
 * => long portée et temps de transmission plus long 
 * donc moins de données envoyer pendant 1% du temps
 * et consommation importante
 * equivalent à 0
 * forte vtesse d'envoie 
 * => portée plus court et temps de transmission plus rapide donc   
 * plus facile de respecter le data rate 
 * et consommation plus faible
 * equivalent à 5
  */
#define ADR           1  //adaptative data rate(par défaut 1)
/*reglage capaciter max(mais interdit)
 * 0 0 0 0
 */
/*OTAA connection adresse*/
/*--------------------------------------------*/
#define APP_EUI ""
#define APP_KEY ""
/*------------------------------------------*/
/*ABP connection adresss
--------------------------------------------*/
#define DEVADDR ""
#define NWKSKEY ""
#define APPSKEY ""
/*-----------------------------------------*/
