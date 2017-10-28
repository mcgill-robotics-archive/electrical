#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humidity = 0;
float tempf = 0;

//Need to change pins based on Arduino chosen    !!!!
//SCL & SDA plug into respective pins
int power = A3;
int GND = A2;

//Create Instance of Si7021 temp and humidity sensor
Weather sensor;

//---------------------------------------------------------------
void setup()
{
    Serial.begin(9600);   // open serial over USB at 9600 baud

    pinMode(power, OUTPUT);
    pinMode(GND, OUTPUT);

    digitalWrite(power, HIGH);
    digitalWrite(GND, LOW);

    //Initialize the I2C sensors and ping them
    sensor.begin();

}
//---------------------------------------------------------------
void loop()
{
    //Get readings from all sensors
    getWeather();
    printInfo();
    delay(1000);

}
//---------------------------------------------------------------
void getWeather()
{
  // Measure Relative Humidity from the Si7021
  humidity = sensor.getRH();

  // Measure Temperature from the Si7021 in Fahrenheit
  tempf = sensor.getTempF();
  // Temperature is measured every time RH is requested.
  // It is faster, therefore, to read it from previous RH
  // measurement with getTemp() instead with readTemp()
}
//---------------------------------------------------------------
void printInfo()
{
//This function prints the weather data out to the default Serial Port

  Serial.print("Temp:");
  Serial.print(tempf);
  Serial.print("F, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println("%");
}
