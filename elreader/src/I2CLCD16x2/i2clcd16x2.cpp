#include "i2clcd16x2.h"

namespace EasyLab{
  I2CLCD16x2::I2CLCD16x2(uint8_t lcd_address){
    setLCDAddress(lcd_address);
    lcd->createChar(0, degreeChar);
  }

  I2CLCD16x2::~I2CLCD16x2(){
    delete[] lcd;
  }

  void I2CLCD16x2::WriteTemperature(float in, float ext){
    // Clear the screen and print
    lcd->setCursor(0, 0);
    lcd->print("Interna:" + String(in));
    lcd->write((byte)0);
    lcd->print("C");
    lcd->setCursor(0, 1);
    lcd->print("Externa:" + String(ext));
    lcd->write((byte)0);
    lcd->print("C");     
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