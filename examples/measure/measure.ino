#include <IDMS.h>

IDMS sensor;

void setup() {
  Serial.begin(9600);
  sensor.attach(1);
}

void loop() {
  Serial.println(sensor.read());
  delay(50);
}
