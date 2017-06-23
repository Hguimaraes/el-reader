/**
 ** @file I2CLCD16x2.h
 **
 **/

#include <LiquidCrystal_I2C.h>
namespace easylab{
class I2CLCD16x2 {
 public:
  //
  //
  //
  I2CLCD16x2(uint8_t lcd_address);
  ~I2CLCD16x2();
  
  //
  //
  //
  void WriteTemperature(double in, double ext);
  
  //
  //
  //
  void WriteAlert(String msg);

 private:
  /**
   *
   */
  byte degreeChar[8] = {0b00111, 0b00101, 0b00111, 0b00000,
                        0b00000, 0b00000, 0b00000, 0b00000};

  /**
   *
   */
  LiquidCrystal_I2C *lcd;
  
};
}