#include <IRremote.h>
#include <IRremoteInt.h>

#define PIN_SENSOR 3

IRrecv irreceiver(PIN_SENSOR);
decode_results results;

void setup() {
  Serial.begin(9600);
  irreceiver.enableIRIn();
}

void loop() {
  if (irreceiver.decode(&results)) {
    Serial.print("Type: ");
    Serial.print(results.decode_type, HEX);
    Serial.print(" Value: ");
    Serial.print(results.value, HEX);
    Serial.print(" Bits: ");
    Serial.println(results.bits, HEX);
    irreceiver.resume();
  }
  delay(3000);
}

// Remote
/*
OFF       Type: FFFFFFFF Value: E318261B Bits: 20
          Type: 1 Value: FFA25D Bits: 20
MODE      Type: FFFFFFFF Value: 511DBB Bits: 20
          
MUTE      
          Type: 1 Value: FFE21D Bits: 20
PLAY      
          Type: 1 Value: FF22DD Bits: 20
BACKWARD  Type: FFFFFFFF Value: D7E84B1B Bits: 20
          
FORWARD   Type: FFFFFFFF Value: 20FE4DBB Bits: 20
          
EQ        
MINUS     
PLUS      
ZERO      
LOOP      
USD       
ONE       Type: FFFFFFFF Value: 9716BE3F Bits: 20
          Type: 1 Value: FF30CF Bits: 20
TWO       Type: FFFFFFFF Value: 3D9AE3F7 Bits: 20
          Type: 1 Value: FF18E7 Bits: 20
THREE     Type: FFFFFFFF Value: 6182021B Bits: 20
          Type: 1 Value: FF7A85 Bits: 20
FOUR      
FIVE  
SIX  
SEVEN  
EIGHT  
NINE  
*/
