#include <DmtrPots.h>

pot pots[] = { pot(A0), pot(A1), pot(A2), pot(A3), pot(A4), pot(A5), pot(A6) };

void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (auto & p : pots) {
    p.update();
    Serial.println(p.valFloat);
  }
}
