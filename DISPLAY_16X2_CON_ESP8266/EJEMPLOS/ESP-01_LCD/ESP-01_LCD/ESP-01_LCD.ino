#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); 

void setup()
{
 Wire.begin(2, 0);

 lcd.init(); // initializing the LCD
 lcd.display(); //Enable or turn on the text
 lcd.backlight(); // Enable or Turn On the backlight 
}

void loop()
{
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("LCD_I2C_ESP8266"); // Start Print text to Line 1
 lcd.setCursor(0, 1);
 lcd.print("TechImagine3D"); // Start Print text to Line 2
 delay(5000);
 lcd.clear();
 lcd.setCursor(1, 0);
 lcd.print("Hola Mundo"); // Start Print text to Line 1
 lcd.setCursor(3, 1);
 lcd.print("Robot por I2C"); // Start Print text to Line 2
 delay(5000);
}
