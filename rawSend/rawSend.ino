
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

#define RAW_DATA_LEN 100
#define MIC_PIN 0

IRsendRaw mySender;
int sample;
const int THRESHOLD_ON = 800;
const int THRESHOLD_OFF = 300;
bool acOn = false;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting..."));
}

// RAW volume up data
uint16_t rawDataVolumeUp[RAW_DATA_LEN] = {
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
  65502, 86, 65506, 1000
};

// TODO: Get raw data for volume down


void loop() {
  sample = analogRead(MIC_PIN);
  if (sample > 0) {
    Serial.println(sample);
  }
  if (sample > THRESHOLD_ON && !acOn) {
    acOn = true;
      for(int i = 0; i <= 10; i++) {
        mySender.send(rawDataVolumeUp, RAW_DATA_LEN, 36);
        Serial.println(F("Sent signal."));
      }
  } else if (sample <= THRESHOLD_OFF && acOn) {
    acOn = false;
    // send volume down signal
  }
}

