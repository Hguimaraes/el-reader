#include "i2clcd16x2.h"

namespace EasyLab{
  I2CLCD16x2::I2CLCD16x2(uint8_t lcd_address){
    setLCDAddress(lcd_address);
  }

  I2CLCD16x2::~I2CLCD16x2(){
    delete[] lcd;
  }

  void I2CLCD16x2::WriteTemperature(float in, float ext){
    // @TO-DO
    String first_line = "Hello I2CLCD16x2";
    String second_line = "World Wrapper";
    
    // Clear the screen and print
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(first_line);
    lcd->setCursor(0, 1);      
    lcd->print(second_line);
  }

  void I2CLCD16x2::setLCDAddress(uint8_t lcd_address){
    this->lcd_address = lcd_address;

    // Initialize and set LCD configuration
    lcd = new LiquidCrystal_I2C(this->lcd_address, 16, 2);
    lcd->begin(16,2);
    lcd->init();
    lcd->backlight();
  }

  uint8_t I2CLCD16x2::getLCDAddress(){
    return lcd_address;
  }
}