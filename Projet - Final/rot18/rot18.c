#include "rot18.h"
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  int c = Serial.write(c);

  Rot18(c);
  Serial.print(c);

}
