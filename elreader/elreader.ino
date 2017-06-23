#include "src/I2CLCD16x2/i2clcd16x2.h"
#include "src/DS18B20/ds18b20.h"
#define LCD_I2C_ADDRESS 0x3f
#define TEMPSENSOR_INT_PORT 4
#define TEMPSENSOR_EXT_PORT 5

EasyLab::I2CLCD16x2 i2clcd(LCD_I2C_ADDRESS);
EasyLab::DS18B20 intTemp, extTemp;

void setup() {
  // Configure the temperature sensor
  intTemp.setPort(TEMPSENSOR_INT_PORT);
  extTemp.setPort(TEMPSENSOR_EXT_PORT);
}

void loop() {
  delay(1000);
  i2clcd.WriteTemperature(5.0, 25.0);
  delay(1000);
}
