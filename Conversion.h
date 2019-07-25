/*Bibliotèque qui permet la conversion des flotant vers des int qui sont plus simple à gérer lors de l'envoie par le LoRa
 *La valeur est arrrondie au nombre de chiffre aprés la virgule souhaiter, resolution= nombre de chiffre après la virgule
 *puis on la multiplie par 1/résolution pour obtenir un entier 
 *sur le serveur on procédera à un décodage en multipliant par la résolution
 * Entrée: chaine de caractère ou float/double
 * sortie: int8 int16 int32 int64 si nombre positif ou negatif 
 *         uint8 uint16 uint32 uint64 si nombre positif ou nul
 */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <cstdlib>
#include <stdint.h>
#include <math.h>
using namespace std;
#define MAX 32
class Conversion
{
  public:
    Conversion() {}
    uint8_t float_uint8(const char mesure[MAX], int resolution);
    /*Pour une valeur entre 0 et 255 et une resolution de 0
     *Pour une valeur entre 0 et 25.5 et une résolution de 1
     *Pour une valeur entre 0 et 2.55 et une résolution de 2
     *Pour une valeur entre 0 et 0.255 et une résolution de 3
     *etc...
     */
    
    uint16_t float_uint16(const char mesure[MAX], int resolution);
    /*Pour une valeur entre 0 et 65536 et une resolution de 0
     *Pour une valeur entre 0 et 6553.6 et une résolution de 1
     *Pour une valeur entre 0 et 655.36 et une résolution de 2
     *etc...
     */
    uint32_t float_uint32(const char mesure[MAX], int resolution);
     /*Pour une valeur entre 0 et 4294967296 et une resolution de 0
     *Pour une valeur entre 0 et 429496729.6 et une résolution de 1
     *Pour une valeur entre 0 et 42949672.96 et une résolution de 2
     *etc...
     */
    uint64_t double_uint64(const char mesure[MAX], int resolution);
    int8_t float_int8(const char mesure[MAX], int resolution);
    int16_t float_int16(const char mesure[MAX], int resolution);
    int32_t float_int32(const char mesure[MAX], int resolution);
    int64_t double_int64(const char mesure[MAX], int resolution);

    uint8_t float_uint8(float mesure, int resolution);
    uint16_t float_uint16(float mesure, int resolution);
    uint32_t float_uint32(float mesure, int resolution);
    uint64_t double_uint64(double mesure, int resolution);

    int8_t float_int8(float mesure, int resolution);
    int16_t float_int16(float mesure, int resolution);
    int32_t float_int32(float mesure, int resolution);
    int64_t double_int64(double mesure, int resolution);
};

#endif //CONVERSION_H
