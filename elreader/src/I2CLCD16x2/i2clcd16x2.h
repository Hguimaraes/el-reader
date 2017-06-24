/**
 ** @file i2clcd16x2.h
 ** @class I2CLCD16x2
 ** @Description:
 **  This file contains a specific implementation to use the
 ** LCD 16x2 with I2C on NodeMCU. It's a simple wrapper of the
 ** LiquidCrystal_I2C library with functions useful for our application.
 **/

#ifndef _I2CLCD16X2_H
#define _I2CLCD16X2_H

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"

namespace EasyLab{
class I2CLCD16x2 {
  private:
    // Custom character to print the degree symbol in the LCD 
    byte degreeChar[8] = {0b00111, 0b00101, 0b00111, 0b00000,
                          0b00000, 0b00000, 0b00000, 0b00000};

    // Create an object of LiquidCrystal_I2C library to manipulate
    // the LCD. This is the original library to manipulate LCD with I2C
    // I2CLCD16x2 is only a wrapper around this class, for a specific domain problem
    LiquidCrystal_I2C *lcd;

    // I2C Address of the display
    uint8_t lcd_address;

  public:
    //  Constructor and destructor of the Class. To instatiate an I2CLCD16x2
    // object we only need the I2C address in uint8_t. For NodeMCU is likely to
    // be 0x3F. To discover your port you can follow these steps of [1].
    // @Reference:  
    // [1] - http://playground.arduino.cc/Main/I2cScanner
    I2CLCD16x2(uint8_t lcd_address);
    virtual ~I2CLCD16x2();
  
    //  Public method to write the temperature (internal and external) values
    // in the LCD.
    void WriteTemperature(float in, float ext);

    // Public method to write the IP of the device on the display
    void WriteIPAddress(String IP);
      
    // Getter and setter for lcd_address
    void setLCDAddress(uint8_t lcd_address);
    uint8_t getLCDAddress();

};
}

#endif