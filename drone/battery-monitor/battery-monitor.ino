#include <Adafruit_NeoPixel.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit)) 

#define NUM_LEDS 25
#define VOLTAGE_HIGH 24.8f
#define VOLTAGE_LOW 20.5f
#define RESISTOR_HIGH  47000.0f
#define RESISTOR_LOW   10000.0f
#define VOLT_CONVERT 5.0 / 1024.0 / (RESISTOR_LOW / (RESISTOR_HIGH + RESISTOR_LOW)) 

#define DATA_PIN 3

// Define the array of leds
Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() { 
  leds.begin();
  cli();
  
  sbi(MCUCR, ISC01);    // Set interrupt for INT0 to be fallling edge
  cbi(MCUCR, ISC00);
 
  sbi(GIMSK, INTF0);    // Enable INT0 interrupt
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
}

void loop() { 
  cli();
  sleep_enable();
  sei();
  sleep_cpu();
  sleep_disable();
}

ISR(INT0_vect) {
  cli();                        // Disble interrupt
  int adc_read = 0;
  for(int i = 0; i < 10 ; i++){
  adc_read = analogRead(A2);
  }
  adc_read /= 10;
  double voltage = adc_read * VOLT_CONVERT;
  char led_on = NUM_LEDS * (voltage - VOLTAGE_LOW) / (VOLTAGE_HIGH - VOLTAGE_LOW);
  
  for (int i = 0; i < NUM_LEDS; i++){
    if( i < led_on) {
      leds.setPixelColor(i,0x00FFFF);
    } else {
      leds.setPixelColor(i,0xFFA500);  
    }
  }
  leds.show();
  delayMicroseconds(5000000);
  sei();
}
