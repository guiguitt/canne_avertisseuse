#include "Conversion.h"

uint8_t Conversion::float_uint8(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod((double)num, (double)reso) >= reso * 0.5) num = num - fmod(num, reso) + reso;
  else num = num - (fmod(num, reso));
  num = num * (1 / reso);
  return (uint8_t)num;
}

uint16_t Conversion::float_uint16(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod((double)num, (double)reso) >= reso * 0.5) num = num - fmod(num, reso) + reso;
  else num = num - (fmod(num, reso));
  num = num * (1 / reso);

  return (uint16_t)num;
}

uint32_t Conversion::float_uint32(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod((double)num, (double)reso) >= reso * 0.5) num = num - fmod(num, reso) + reso;
  else num = num - (fmod(num, reso));
  num = num * (1 / reso);
  return (uint32_t)num;
}
uint64_t Conversion::double_uint64(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod((double)num, (double)reso) >= reso * 0.5) num = num - fmod(num, reso) + reso;
  else num = num - (fmod(num, reso));
  num = num * (1 / reso);
  return (uint64_t)num;
}

/*-----------------------------------------------------------------------------------------*/
uint8_t Conversion::float_uint8(float mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod((double)mesure, (double)reso) >= reso * 0.5) mesure = mesure - fmod(mesure, reso) + reso;
  else mesure = mesure - (fmod(mesure, reso));
  mesure = mesure * (1 / reso);
  return (uint8_t)mesure;
}

uint16_t Conversion::float_uint16(float mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod((double)mesure, (double)reso) >= reso * 0.5) mesure = mesure - fmod(mesure, reso) + reso;
  else mesure = mesure - (fmod(mesure, reso));
  mesure = mesure * (1 / reso);

  return (uint16_t)mesure;
}

uint32_t Conversion::float_uint32(float mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod((double)mesure, (double)reso) >= reso * 0.5) mesure = mesure - fmod(mesure, reso) + reso;
  else mesure = mesure - (fmod(mesure, reso));
  mesure = mesure * (1 / reso);
  return (uint32_t)mesure;
}
uint64_t Conversion::double_uint64(double mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod((double)mesure, (double)reso) >= reso * 0.5) mesure = mesure - fmod(mesure, reso) + reso;
  else mesure = mesure - (fmod(mesure, reso));
  mesure = mesure * (1 / reso);
  return (uint64_t)mesure;
}


/*--------------------------------------------------------------------------------------*/

int8_t Conversion::float_int8(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod(num, reso) >= reso * 0.5 && num > 0) num = num - fmod(num, reso) + reso;
  else if (fmod(num, reso) >= reso * 0.5 && num < 0) num = num + fmod(num, reso) - reso;
  else if (num > 0) num = num - (fmod(num, reso));
  else if (num < 0) num = num + (fmod(num, reso));
  num = num * (1 / reso);
  return (int8_t)num;
}

int16_t Conversion::float_int16(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod(num, reso) >= reso * 0.5 && num > 0) num = num - fmod(num, reso) + reso;
  else if (fmod(num, reso) >= reso * 0.5 && num < 0) num = num + fmod(num, reso) - reso;
  else if (num > 0) num = num - (fmod(num, reso));
  else if (num < 0) num = num + (fmod(num, reso));
  num = num * (1 / reso);
  return (int16_t)num;
}

int32_t Conversion::float_int32(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod(num, reso) >= reso * 0.5 && num > 0) num = num - fmod(num, reso) + reso;
  else if (fmod(num, reso) >= reso * 0.5 && num < 0) num = num + fmod(num, reso) - reso;
  else if (num > 0) num = num - (fmod(num, reso));
  else if (num < 0) num = num + (fmod(num, reso));
  num = num * (1 / reso);
  return (int32_t)num;
}
int64_t Conversion::double_int64(const char mesure[MAX], int resolution)
{
  double reso = pow(10, -resolution);
  double num;
  num = atof(mesure);
  if (fmod(num, reso) >= reso * 0.5 && num > 0) num = num - fmod(num, reso) + reso;
  else if (fmod(num, reso) >= reso * 0.5 && num < 0) num = num + fmod(num, reso) - reso;
  else if (num > 0) num = num - (fmod(num, reso));
  else if (num < 0) num = num + (fmod(num, reso));
  num = num * (1 / reso);
  return (int64_t)num;
}

/*--------------------------------------------------------------------------------------------------*/

int8_t Conversion::float_int8(float mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod(mesure, reso) >= reso * 0.5 && mesure > 0) mesure = mesure - fmod(mesure, reso) + reso;
  else if (fmod(mesure, reso) >= reso * 0.5 && mesure < 0) mesure = mesure + fmod(mesure, reso) - reso;
  else if (mesure > 0) mesure = mesure - (fmod(mesure, reso));
  else if (mesure < 0) mesure = mesure + (fmod(mesure, reso));
  return (int8_t)mesure;
}

int16_t Conversion::float_int16(float mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod(mesure, reso) >= reso * 0.5 && mesure > 0) mesure = mesure - fmod(mesure, reso) + reso;
  else if (fmod(mesure, reso) >= reso * 0.5 && mesure < 0) mesure = mesure + fmod(mesure, reso) - reso;
  else if (mesure > 0) mesure = mesure - (fmod(mesure, reso));
  else if (mesure < 0) mesure = mesure + (fmod(mesure, reso));
  mesure = mesure * (1 / reso);
  return (int16_t)mesure;
}

int32_t Conversion::float_int32(float mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod(mesure, reso) >= reso * 0.5 && mesure > 0) mesure = mesure - fmod(mesure, reso) + reso;
  else if (fmod(mesure, reso) >= reso * 0.5 && mesure < 0) mesure = mesure + fmod(mesure, reso) - reso;
  else if (mesure > 0) mesure = mesure - (fmod(mesure, reso));
  else if (mesure < 0) mesure = mesure + (fmod(mesure, reso));
  mesure = mesure * (1 / reso);
  return (int32_t)mesure;
}
int64_t Conversion::double_int64(double mesure, int resolution)
{
  double reso = pow(10, -resolution);
  if (fmod(mesure, reso) >= reso * 0.5 && mesure > 0) mesure = mesure - fmod(mesure, reso) + reso;
  else if (fmod(mesure, reso) >= reso * 0.5 && mesure < 0) mesure = mesure + fmod(mesure, reso) - reso;
  else if (mesure > 0) mesure = mesure - (fmod(mesure, reso));
  else if (mesure < 0) mesure = mesure + (fmod(mesure, reso));
  mesure = mesure * (1 / reso);
  return (uint64_t)mesure;
}
