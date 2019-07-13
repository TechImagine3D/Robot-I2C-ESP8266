

#include <LiquidCrystal_I2C.h>

#include <Wire.h> 


//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3F,16,2);  //

void setup() {
  // Inicializar el LCD
   Wire.begin(2, 0);
  lcd.init();
  lcd.display(); //Enable or turn on the text
   //Encender la luz de fondo.
  lcd.backlight();
  
  // Escribimos el Mensaje en el LCD.
   lcd.clear();
 lcd.setCursor(0, 0);
  lcd.print("Hola Mundo");
   delay(2000);
}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
    lcd.clear();
  lcd.setCursor(0, 1);
   // Escribimos el número de segundos trascurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}
