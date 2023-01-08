// Author: projedefteri.com
// Using I2C and LCD with Arduino in Proteus

#include <Wire.h> // This library allows you to communicate with I2C/TWI devices.
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 20, 4); // Set the LCD address to 0x20 for a 20 chars and 4 line display

void setup() {
  lcd.init(); // initialize the lcd
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("Merhaba, Dunya!");
}
