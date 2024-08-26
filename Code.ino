#include <Arduino.h>
#include <IRremote.hpp>

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(3);
  pinMode(4, OUTPUT);
}

void loop(){
  if (IrReceiver.decode()) 
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    
    if (IrReceiver.decodedIRData.decodedRawData ==  0xBA45FF00)
    {
        digitalWrite(4, !digitalRead(4));
    }
    IrReceiver.resume(); // Enable receiving of the next value
  }
}
