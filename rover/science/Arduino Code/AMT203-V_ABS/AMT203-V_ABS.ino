#include "AMT203-V_ABS.h"

int CSB = 10; //Chip or Slave select
float deg = 0.00;

AMT_ABS * encoder;

void setup() {
  Serial.begin(115200);
  
  encoder = new AMT_ABS(CSB);
  delay(300);
  Serial.print("Ready");
}

void loop() {
  deg = encoder->DEG();
  Serial.println(deg);

  delay(3);
}
