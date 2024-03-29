/*
Receiver Code
*                 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
* 
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    char message[100];
    radio.read(&message, sizeof(message));
    Serial.println(message);
  }
}
