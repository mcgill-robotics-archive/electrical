
#include <Wire.h>

const int wind_sensor_pin = A12;
int wind_sensor_value = 0;
float wind_sensor_voltage = 0, wind_speed = 0, voltage_constant = .004882814, voltage_min = .4, voltage_max = 2.0, wind_speed_max = 32;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
   wind_sensor_value = analogRead(wind_sensor_pin);
   wind_sensor_voltage = wind_sensor_value * voltage_constant;
   if (wind_sensor_voltage <= voltage_min){
      wind_speed = 0;
   }
   else {
      wind_speed = (wind_sensor_voltage - voltage_min)*wind_speed_max/(voltage_max - voltage_min);
   }
   Serial.print("Wind speed: ");
   Serial.print(wind_speed);
   Serial.println("m/s");
}
