
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

#define RAW_DATA_LEN 100
#define MIC_PIN A0

IRsendRaw mySender;
int sample;
const int threshold = 800;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting..."));
}

// RAW volume up data
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
  sample = analogRead(MIC_PIN);
  if (sample > 0) { Serial.println(sample); }
  if (sample > threshold) {
    mySender.send(rawData,RAW_DATA_LEN,36);
    Serial.println(F("Sent signal."));
  }
}

