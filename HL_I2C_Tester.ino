/**
*
* Sample Multi Master I2C implementation.  Sends a button state over I2C to another
* Arduino, which flashes an LED correspinding to button state.
*
* Connections: Arduino analog pins 4 and 5 are connected between the two Arduinos,
* with a 1k pullup resistor connected to each line.  Connect a push button between
* digital pin 10 and ground, and an LED (with a resistor) to digital pin 9.
*
*/

#include <Wire.h>

#define LED 13
#define BUTTON 10

#define THIS_ADDRESS 0x8
#define OTHER_ADDRESS 0x20

boolean last_state = HIGH;
uint8_t incomingByte = 0;

void setup() {
 pinMode(LED, OUTPUT);
 digitalWrite(LED, LOW);
 
 pinMode(BUTTON, INPUT);
 digitalWrite(BUTTON, HIGH);

 digitalWrite(A4, HIGH);
 digitalWrite(A5, HIGH);
 
 Wire.begin(THIS_ADDRESS);
 Wire.onReceive(receiveEvent);
 Serial.begin(9600);
 Serial.println("Arduino Hermes-Lite I2C tester");
 Serial.println("copyright (c) Graeme Jury ZL2APV");
 Serial.println();
}

void loop() {
 if (Serial.available() > 0){
   incomingByte = Serial.read();
   Serial.print("Data received = 0b");
   Serial.println(incomingByte, BIN);
   Wire.beginTransmission(OTHER_ADDRESS);
   Wire.write(incomingByte);
   Wire.endTransmission();
   setOutputPins(incomingByte);
 }
}

void receiveEvent(int howMany){
 while (Wire.available() > 0){
   boolean b = Wire.read();
   Serial.print(b, DEC);
   digitalWrite(LED, !b);
 }
 Serial.println();
}


void setOutputPins(uint8_t cmd)
{
  uint8_t rxValue;
  uint8_t cmdValue;
  uint8_t txValue;
  uint8_t moxValue;

  rxValue = cmd & 0b00000111;
  cmdValue = ((cmd & 0b00001000) >> 3);
  txValue = ((cmd & 0b01110000) >> 4);
  moxValue = ((cmd & 0b10000000) >> 7);
}

