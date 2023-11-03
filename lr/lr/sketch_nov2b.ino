// Sender (Master)
#include "SPI.h"
#include "RF24.h"
#include "nRF24L01.h"

#define CE_PIN 9
#define CSN_PIN 10
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

struct Payload {
  unsigned long timestamp;
};
void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setAutoAck(true);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(address);
  radio.stopListening();
  Serial.println("Sender started");
}
void loop() {
  Payload payload;
  payload.timestamp = micros();
  if (radio.write(&payload, sizeof(payload))) {
    unsigned long end_time = micros();
    unsigned long round_trip_time = end_time - payload.timestamp;
    Serial.print("Sent Timestamp: ");
    Serial.println(payload.timestamp);
    Serial.print("Round-trip time: ");
    Serial.print(round_trip_time);
    Serial.println(" us");
  } else {
    Serial.println("Sending failed");
  }
  delay(1000);
}
