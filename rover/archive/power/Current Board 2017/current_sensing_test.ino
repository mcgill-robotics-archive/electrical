#include <LiquidCrystal.h>

float voltage = 0;
float current = 0;

int voltagePin = 0;
int currentPin = 1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  analogReadResolution(12);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  voltage = analogRead(voltagePin);
  current = analogRead(currentPin);

  // TODO map voltage and current from 0-4095 to their real values
  voltage = map(voltage, 0, 3871, 0, 5000) / 100.0;
  current = current / 7.4 / 4;

  String out = "Voltage: ";
  out += voltage;
  out += "V\t\tCurrent: ";
  out += current;
  out += "A";

  Serial.println(out);

  lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(voltage);
  lcd.setCursor(0, 1);
  lcd.print(current);

  // Print the units:
  lcd.setCursor(6, 0);
  lcd.print("V");
  lcd.setCursor(6, 1);
  lcd.print("A");

  delay(100);
}
