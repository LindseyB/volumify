
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

#define MIC_PIN 0
#define RAW_DATA_LEN = 68;

IRsendRaw mySender;
int sample;
const int THRESHOLD_ON = 800;
const int THRESHOLD_OFF = 300;
bool acOn = false;

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting..."));
}

// Raw volume up data
uint16_t rawData[RAW_DATA_LEN]={
  4514, 4570, 526, 1762, 498, 1758, 502, 1758, 
  502, 626, 506, 626, 502, 626, 506, 622, 
  498, 634, 494, 1762, 498, 1762, 502, 1754, 
  506, 622, 506, 626, 506, 622, 506, 622, 
  498, 634, 498, 1758, 502, 1758, 502, 1754, 
  506, 626, 502, 626, 506, 622, 498, 630, 
  498, 634, 498, 630, 498, 630, 502, 630, 
  502, 1754, 506, 1750, 510, 1750, 498, 1758, 
  502, 1758, 502, 1000};


// Raw volume down data
uint16_t rawDataVolumeDown[RAW_DATA_LEN]={
  4510, 4602, 506, 1754, 506, 1754, 498, 1758, 
  502, 630, 502, 626, 502, 626, 506, 626, 
  502, 626, 506, 1754, 494, 1762, 502, 1758, 
  502, 626, 502, 630, 502, 626, 502, 626, 
  506, 626, 506, 1750, 510, 1750, 498, 630, 
  502, 1758, 502, 626, 506, 626, 502, 626, 
  506, 626, 502, 626, 506, 622, 506, 1754, 
  498, 630, 498, 1762, 502, 1758, 502, 1754, 
  506, 1754, 506, 1000};
};


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
    for(int i = 0; i <= 10; i++) {
      mySender.send(rawDataVolumeUp, RAW_DATA_LEN, 36);
      Serial.println(F("Sent signal."));
    }
  }
}

