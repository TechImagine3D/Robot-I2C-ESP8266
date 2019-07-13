#include <LiquidCrystal_I2C.h>

#include <Wire.h> 


LiquidCrystal_I2C lcd(0x3F,16,2);  // Configuración

void setup() 
{
   Wire.begin(2, 0);
  lcd.init();                      // Inicializa
  lcd.backlight();                 // Iluminación
}

void loop() 
{
  lcd.clear();
  lcd.print("TechImagine3D");       // Visualiza Texto
}
