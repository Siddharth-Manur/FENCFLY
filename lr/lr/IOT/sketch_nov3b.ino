#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Same address as the sender
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char gpsData;
    radio.read(&gpsData, sizeof(gpsData));
    Serial.write(gpsData);
  }
}








