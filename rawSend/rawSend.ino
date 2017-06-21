
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

IRsendRaw mySender;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Every time you press a key is a serial monitor we will send."));
}

// RAW volume up data
#define RAW_DATA_LEN 100
uint16_t rawData[RAW_DATA_LEN]={
  65506, 66, 65502, 78, 65502, 86, 65502, 90, 
  65502, 86, 65502, 86, 65506, 86, 65502, 86, 
  65502, 86, 65502, 90, 65502, 1762, 65502, 2290, 
  65502, 190, 65502, 90, 65502, 86, 65502, 90, 
  65502, 86, 65502, 86, 65502, 90, 65502, 86, 
  65502, 1762, 65502, 190, 65502, 86, 65502, 90, 
  65502, 86, 65502, 86, 65506, 86, 65502, 86, 
  65502, 86, 65506, 630, 65502, 86, 65502, 86, 
  65502, 86, 65506, 86, 65502, 86, 65502, 86, 
  65506, 86, 65502, 86, 65502, 86, 65506, 86, 
  65502, 630, 65502, 94, 65502, 78, 65506, 86, 
  65502, 86, 65502, 86, 65506, 86, 65502, 86, 
  65502, 86, 65506, 1000};

   
void loop() {
  if (Serial.read() != -1) {
    //send a code every time a character is received from the 
    // serial port. You could modify this sketch to send when you
    // push a button connected to an digital input pin.
    mySender.send(rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("Sent signal."));
  }
}

