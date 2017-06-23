#include "src/I2CLCD16x2/i2clcd16x2.h"
#include "src/DS18B20/ds18b20.h"

#define LCD_I2C_ADDRESS 0x3f
#define TEMPSENSOR_INT_PORT D3
#define TEMPSENSOR_EXT_PORT D4

EasyLab::I2CLCD16x2 i2clcd(LCD_I2C_ADDRESS);
EasyLab::DS18B20 intTemp, extTemp;

void setup() {
  // Configure the temperature sensor
  intTemp.setPort(TEMPSENSOR_INT_PORT);
  extTemp.setPort(TEMPSENSOR_EXT_PORT);
}

void loop() {
  float int_temp = intTemp.readTemperature();
  i2clcd.WriteTemperature(int_temp, 25.0);
}
