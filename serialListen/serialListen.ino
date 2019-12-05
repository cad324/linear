#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init();
}

void loop() {
  if (Serial.available() >= 30) {
    for (int i = 0; i < 30; i++) {
      byte incoming = Serial.read();
      if (incoming == '1') {
        lcd.backlight();
        lcd.setCursor(0,0);
        lcd.print("receiving");
        lcd.setCursor(0,1);
        lcd.print(i);
        delay(1000);
      } 
   }
  }
}
