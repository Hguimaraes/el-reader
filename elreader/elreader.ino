#include "src/I2CLCD16x2/i2clcd16x2.h"
#define LCD_I2C_ADDRESS 0x3f

EasyLab::I2CLCD16x2 i2clcd(0x3f);

void setup() {
  
}

void loop() {
  delay(1000);
  i2clcd.WriteTemperature(5.0, 25.0);
  delay(1000);
}
