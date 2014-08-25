#include "ADE7880.h"
#include <SPI.h>

ADE7880 myADE(10);

void setup(){
  Serial.begin(9600);
  myADE.begin();
  
}

void loop(){
  Serial.println(myADE.read32bits(CHECKSUM),HEX);
  delay(1000);
}
