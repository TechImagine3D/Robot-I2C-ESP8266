

// I2C Keypad for Arduino

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad_I2C.h>
#include <Keypad.h>
#define I2CADDR 0x20 //DIRECCION PCF8574 PARA EL TECLADO 4X4
LiquidCrystal_I2C lcd(0x3F,16,2);  // set I2C address ke 0x27

const byte ROWS = 4; //CUATRO FILAS
const byte COLS = 3; //TRES COLUMNAS
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Digitran keypad, bit numbers of PCF8574 i/o port
byte rowPins[ROWS] = {0, 1, 2, 3}; //PINES DE FILA
byte colPins[COLS] = {4, 5, 6}; //PINES DE COLUMNA

Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574 );

void setup() {
  Wire.begin(2, 0);
  lcd.init();                      // INICIALIZA LCD
  lcd.backlight();                 // ACTIVA ILUMINACIÓN
  kpd.begin( makeKeymap(keys) );
 // Serial.begin(9600);
  //Serial.println( "start" );
   lcd.clear();
  lcd.print("TECLADO_3X4");       // VISUALIZA_TEXTO
  delay(50);
  
  
}

void loop() {
  char key = kpd.getKey();

  if (key) {
    lcd.clear();
  lcd.print(key);       // VISUALIZA_TEXTO
  delay(50);
   // Serial.println(key);
   //send the data
  
  }
}
