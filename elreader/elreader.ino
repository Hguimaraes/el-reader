#include "src/I2CLCD16x2/i2clcd16x2.h"
#include "src/DS18B20/ds18b20.h"
#include "src/WiFiHandler/wifihandler.h"

#define LCD_I2C_ADDRESS 0x3f
#define TEMPSENSOR_INT_PORT D3
#define TEMPSENSOR_EXT_PORT D4
#define RPIN D5
#define GPIN D6
#define BPIN D7

// Constants variables
const char *ssid = "Hguimaraes";
const char *pass = "@123aBc321@";

EasyLab::I2CLCD16x2 i2clcd(LCD_I2C_ADDRESS);
EasyLab::DS18B20 intTemp, extTemp;
EasyLab::WiFiHandler conn(ssid, pass);

void setup() {
  // Configure the temperature sensor
  intTemp.setPort(TEMPSENSOR_INT_PORT);
  extTemp.setPort(TEMPSENSOR_EXT_PORT);

  // Configure the Led
  pinMode(RPIN, OUTPUT);
  pinMode(GPIN, OUTPUT);
  pinMode(BPIN, OUTPUT);
  configPhaseLed();
  
  // Config the WiFi connection
  conn.Connect();
  i2clcd.WriteIPAddress(conn.deviceIP());
  delay(5000);
}

void loop() {
  float int_temp = intTemp.readTemperature();
  i2clcd.WriteTemperature(int_temp, 25.0);
  
  // If is connected
  if(conn.isConnected()){
    connectedPhaseLed();
  } else {
    disconnectedPhaseLed();
  }
}

//  Turn on the Led with an Yellow light to represent
// that we are in setup phase on the board
void configPhaseLed(){
  clearLed();
  digitalWrite(RPIN, LOW);
  digitalWrite(GPIN, LOW);
  digitalWrite(BPIN, HIGH);
}

//  Turn on the Led with an Green light to represent
// that we are connected to the wifi network
void connectedPhaseLed(){
  clearLed();
  digitalWrite(RPIN, HIGH);
  digitalWrite(GPIN, LOW);
  digitalWrite(BPIN, HIGH);
}

//  Turn on the Led with an Red light to represent
// that we are disconnected to the wifi network
void disconnectedPhaseLed(){
  clearLed();
  digitalWrite(RPIN, LOW);
  digitalWrite(GPIN, HIGH);
  digitalWrite(BPIN, HIGH);
}

// Set to off all the ports of the RGB led
void clearLed(){
  digitalWrite(RPIN, HIGH);
  digitalWrite(GPIN, HIGH);
  digitalWrite(BPIN, HIGH);
}
