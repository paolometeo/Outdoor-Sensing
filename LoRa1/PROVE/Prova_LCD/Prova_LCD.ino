#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address per CigarBox
//LiquidCrystal_I2C lcd(0x22,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);  // valido per i display con interfaccia comprata a parte (cascinet)


void setup() {
  // put your setup code here, to run once:
  while (!Serial);  
  Serial.begin(57600);
  delay(100);
  Serial.println("ProMicroLora_RX_ESP.ino");

   //  inizializza display LCD
  lcd.init();      
  delay(1000);

  // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  lcd.print("ProMicroLoRa RX");
  lcd.setCursor(0, 1);
  lcd.print("RX and WiFi");
}

void loop() {
  // put your main code here, to run repeatedly:

}
