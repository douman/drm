/*
  drm.h - Utility Library for drm 
  Created by drm 20141214
*/
#ifndef drm_h
#define drm_h

#include "Arduino.h"

class drm
{
  public:
    byte bcd2dec_Byte(byte in_byte);
    unsigned short drm_Serialno();
    void drm_Start_print();
    void s_Prt_lead0(long in, int places);
  private:
};

#endif
