#include "Adafruit_NeoPixel.h"

#define VOLTAGE_HIGH 24.8f
#define VOLTAGE_LOW 20.5f
#define RESISTOR_HIGH  47000.0f
#define RESISTOR_LOW   10000.0f
#define VOLT_CONVERT 5.0 / 1024.0 / (RESISTOR_LOW / (RESISTOR_HIGH + RESISTOR_LOW)) 

#define NUM_LEDS 6
#define PIN_LED 1
#define PIN_BUTTON 2
#define PIN_ANALOG A2

// Define the array of leds
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);

int timeout_count = 0;

double alpha = 0.8;
double adc_avg_value = 0;


void setup() { 
  leds.begin();
}


void loop() {   
  adc_avg_value = alpha * adc_avg_value + (1 - alpha) * analogRead(PIN_ANALOG);

  if (!digitalRead(PIN_BUTTON)) {
    timeout_count = 10;
  }
  
  if (timeout_count > 0) {
    timeout_count--;
    double voltage = adc_avg_value * VOLT_CONVERT;

    int led_on = NUM_LEDS * (voltage - VOLTAGE_LOW) / (VOLTAGE_HIGH - VOLTAGE_LOW) + 0.5;
    for (int i = 0; i < NUM_LEDS; i++) {
      if (led_on <= 0) {
        leds.setPixelColor(i, 0x4F0000);
      } else if (i < led_on) {
        leds.setPixelColor(i, 0x1F4F00);
      } else {
        leds.setPixelColor(i, 0x000000);  
      }
    }
  } else {  
    for (int i = 0; i < NUM_LEDS; i++) {
      leds.setPixelColor(i, 0x000000);
    }
  }

  leds.show();
  delay(100); 
}
