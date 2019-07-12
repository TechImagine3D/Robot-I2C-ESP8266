/*--------------------------------------------------------------
  Program:      two_wire_knigh_rider

  Description:  Uses a PCF8574 IO Expander IC on the Arduino
                TWI bus to interface 8 LEDs. A "knight
                rider" display is shown on the LEDs.

  Date:         25 April 2012
 
  Author:       W.A. Smith, http://startingelectronics.org
--------------------------------------------------------------*/
#include <Wire.h>
#include <pcf8574_esp.h>

PCF857x pcf8574(0b00111000, &Wire);
#define PIN_INT 5
#define PIN_SDA 2
#define PIN_SCL 0

// address of PCF8574 IC on TWI bus
#define IO_ADDR (0x23 >> 1)

void setup() {
    Wire.pins(PIN_SDA, PIN_SCL);//SDA - D1, SCL - D2
  Wire.begin();        // initialize the I2C/TWI interface
   pcf8574.begin( 0xF0 ); //4 pin input "F", 4 pin output "0"
  Serial.begin(9600);
}

void loop() {
  static unsigned char data = 0x01;  // data to display on LEDs
  static unsigned char direc = 1;    // direction of knight rider display
  
  // send the data to the LEDs
  Wire.beginTransmission(IO_ADDR);
  Wire.write(~data);
  Wire.endTransmission();
  delay(1);  // speed of display
  
  
  
  Serial.print("data: ");
  Serial.print(data);
  Serial.println();
  
  
  // shift the on LED in the specified direction
  if (direc) {
    data <<= 1;
  }
  else {
    data >>= 1;
  }
  // see if a direction change is needed
  if (data == 0x80) {
    direc = 0;
  }
  if (data == 0x01) {
    direc = 1;
  }
}
