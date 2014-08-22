//voor als de library per ongeluk twee keer wordt geimporteerd
#ifndef ADE7880_h
#define ADE7880_h
#include "Arduino.h"    

#define READ 0x01 //0x01 = b00000001 LSB moet een zijn. Zie datasheet p 76
#define CHECKSUM 0xE51F //Checksum register default value 0xAFFA63B9


class ADE7880{
  public:
    ADE7880(int _CS);
    
    //Later in private te plaatsen
    unsigned char read8bits(char reg);
    unsigned int read16bits(char reg);
    unsigned long read24bits(char reg);
    unsigned long read32bits(char reg);
    
    //write methodes, later ook in private plaatsen
    //void write8(char reg, unsigned char data);
    //void write16(char reg, unsigned int data);
    //void write24(char reg, unsigned long data);
    //void write32(char reg, unsigned long data);
	
  private:
    int CS;

    void enable();
    void disable();
};


#endif


