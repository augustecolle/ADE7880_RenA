#include "Arduino.h"
#include <SPI.h>
#include "ADE7758.h"
#include <avr/wdt.h>
#include <math.h>

ADE7880::ADE7880(int _CS){
	CS = _CS;
}

void ADE7880::begin(){
	pinMode(CS,OUTPUT);
	digitalWrite (CS,HIGH);
	SPI.setDataMode(SPI_MODE2);
	SPI.setClockDivider(SPI_CLOCK_DIV32);
	SPI.setBitOrder(MSBFIRST); //zie datasheet p76
	SPI.begin();
	delay(10);
}

void ADE7880::enable(){
	digitalWrite(CS,LOW);
}

void ADE7880::disable(){
	digitalWrite(CS,HIGH);
}


unsigned char ADE7880::read8bits(char reg){
	enable();
    unsigned char b0;
	delayMicroseconds(50);
	SPI.transfer(reg);
	delayMicroseconds(50);
	b0=SPI.transfer(READ);
	delayMicroseconds(50);
    disable();
	return b0;
}

unsigned int ADE7880::read16bits(char reg){
    enable();
    unsigned char b1,b0;
    delayMicroseconds(50);
    SPI.transfer(reg);
    delayMicroseconds(50);
    b1=SPI.transfer(READ);
    delayMicroseconds(50);
    b0=SPI.transfer(READ);
    delayMicroseconds(50);
    disable();
    return (unsigned int)b1<<8 | (unsigned int)b0;
}

unsigned long ADE7880::read24bits(char reg){
    enable();
    unsigned char b2,b1,b0;
    delayMicroseconds(50);
    SPI.transfer(reg);
    delayMicroseconds(50);
    b2=SPI.transfer(READ);
    delayMicroseconds(50);
    b1=SPI.transfer(READ);
    delayMicroseconds(50);
    b0=SPI.transfer(READ);
    delayMicroseconds(50);
    disable();
    return (unsigned long)b2<<16 | (unsigned long)b1<<8 | (unsigned long)b0;
}

unsigned long ADE7880::read32bits(char reg){
    enable();
    unsigned char b3,b2,b1,b0;
    delayMicroseconds(50);
    SPI.transfer(reg);
    delayMicroseconds(50);
    b3=SPI.transfer(READ);
    delayMicroseconds(50);
    b2=SPI.transfer(READ);
    delayMicroseconds(50);
    b1=SPI.transfer(READ);
    delayMicroseconds(50);
    b0=SPI.transfer(READ);
    delayMicroseconds(50);
    disable();
    return (unsigned long)b3<<24 | (unsigned long)b2<<16 | (unsigned long)b1<<8 | (unsigned long)b0;
}
