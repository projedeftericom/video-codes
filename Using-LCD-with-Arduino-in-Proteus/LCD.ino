// Author: projedefteri.com
// Using LCD with Arduino in Proteus

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Merhaba, Dunya!");
  delay(1000);
  lcd.clear();
  lcd.print("projedefteri.com");
  delay(1000);
}
