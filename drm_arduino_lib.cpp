/*
  drm.cpp - Utility Library for drm
  Created by drm 20141214
*/

#include "Arduino.h"
#include "drm.h"


drm::bcd2dec_Byte(byte in_byte) {
  return (((in_byte & 0b11110000)>>4)*10 + (in_byte & 0b00001111));
}

drm::drm_Serialno() {
  return(EEPROM.read(5) << 8 | EEPROM.read(6)); // combine two bytes into in serial number (drm specific)
}

drm::drm_Start_print(); {
  Serial.print(version); 
  Serial.print(F(" SN#"));
  Serial.println(drm_Serialno());
  Serial.print(F("Compiled-> "));
  Serial.print(F(__DATE__)); 
  Serial.print(F(" "));
  Serial.println(F(__TIME__));
}

drm::s_Prt_lead0(long in, int places) {
  if(places>10 || places<2) return;
  in = abs(in); // only for positive numbers
  if(in < 1000000000) in = in + 1000000000; // extend smaller numbers
  char out_str[11];
  sprintf(out_str, "%ld", in);
  Serial.print((out_str+(10-places)));
}


