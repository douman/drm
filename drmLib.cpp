/*
  drmLib.cpp - Utility Library for drm
  Created by drm 20151213
*/

#include "drmLib.h"

// return the the byte BCD encoded value as a byte
byte drmBcd2Dec(byte inbyte) 
{
  return (((inbyte & 0b11110000)>>4)*10 + (inbyte & 0b00001111));
}

// return the serial number from Arduino EEPROM (drm specific)
unsigned short drmSerialNo() 
{
  return(EEPROM.read(5) << 8 | EEPROM.read(6)); // combine two bytes into in serial number (drm specific)
}

// Printout the standard drm Arduino start message
void drmStartPrint(const char *drmversion) 
{
  Serial.print(drmversion); 
  Serial.print(F(" SN#"));
  Serial.println(drmSerialNo());
  Serial.print(F("Compiled-> "));
  Serial.print(F(__DATE__)); 
  Serial.print(F(" "));
  Serial.println(F(__TIME__));
}

// Print a long integer with leading zero and a specific number of places (up to 9 digits)
void drmPrtLead0(long in, int places) 
{
  if(places>10 || places<2) return;
  in = abs(in); // only for positive numbers
  if(in < 1000000000) in = in + 1000000000; // extend smaller numbers
  char out_str[11];
  sprintf(out_str, "%ld", in);
  Serial.print((out_str+(10-places)));
}


