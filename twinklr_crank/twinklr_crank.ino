// Twinklr encoder. For reference, our encoder is wired:
//
// Blue wire (0V) to G
// Black wire (A) to pin 5
// White wire (B) to pin 6
// Brown wire (+V) to vIn

#include <Encoder.h>

Encoder myEnc(5,6);

long oldPosition  = -999;
int squashFactor = 20;

void setup() {
  Serial.begin(9600);
  Serial.println("off we go");
}



void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    if(newPosition > (oldPosition+squashFactor)) {
      Mouse.move(0,0,2);
      oldPosition = newPosition;
    }
    
    if(newPosition < (oldPosition-squashFactor)) {
      Mouse.move(0,0,-2);
      oldPosition = newPosition;
    }
    
    Serial.println(newPosition);
    

  }
}