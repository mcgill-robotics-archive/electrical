#include <Adafruit_NeoPixel.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit)) 

#define NUM_LEDS 6
#define VOLTAGE_HIGH 24.8f
#define VOLTAGE_LOW 20.5f
#define RESISTOR_HIGH  47000.0f
#define RESISTOR_LOW   10000.0f
#define VOLT_CONVERT 5.0 / 1024.0 /// (RESISTOR_LOW / (RESISTOR_HIGH + RESISTOR_LOW)) 

#define DATA_PIN 1

// Define the array of leds
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() { 
  leds.begin();
}

void loop() { 
  if(!digitalRead(2)){
    int adc_read = 0;
    for(int i = 0; i < 10 ; i++){
      adc_read += analogRead(A2);
    }
    adc_read /= 10;
    double voltage = adc_read * VOLT_CONVERT;
    char led_on = NUM_LEDS * voltage / 5.0 + 0.5;
    //(voltage - VOLTAGE_LOW) / (VOLTAGE_HIGH - VOLTAGE_LOW);
  
    for (int i = 0; i < NUM_LEDS; i++){
      if( i < led_on) {
        leds.setPixelColor(i,0x003F3F);
      } else {
        leds.setPixelColor(i,0x3F1500);  
      }
    }
    cli();
    leds.show();
    sei();
  } else {  
    for(int i = 0; i < NUM_LEDS; i++){
      leds.setPixelColor(i,0x000000);
    }
    cli();
    leds.show();
    sei();
  }
}
