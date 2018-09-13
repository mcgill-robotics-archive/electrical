#include <Wire.h>

  byte humidity_sensor_pin = A15;

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
}

void loop() {
    int humidity_value = analogRead(humidity_sensor_pin);
    Serial.print("Humidity Level (0-1023): ");
    Serial.println(1023-humidity_value);
    delay(250);
    }

