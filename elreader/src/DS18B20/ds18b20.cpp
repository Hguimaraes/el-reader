#include "ds18b20.h"

namespace EasyLab{
DS18B20::DS18B20(){
  data = new byte [12];
  addr = new byte [8];
}

DS18B20::~DS18B20(){
  delete[] data;
  delete[] addr;
  delete onewire;
}

void DS18B20::setPort(const unsigned &value){
  pin = value;
  onewire = new OneWire(pin);
}
  
float DS18B20::readTemperature(){
  getDataOfSensor();
  return (float)rawData / 16.0;
}
  
void DS18B20::searchSensor(){
  // Check if the sensor is available. If not should left the function.
  // TODO: Add a handle-exception here
  if (!onewire->search(addr)){
      onewire->reset_search();
      return;
    }
}

void DS18B20::setParasitePower(){
  // Reset the sensor to initialize it again.
  onewire->reset();
  // Select the sensor address
  onewire->select(addr);
  // Write a Hex value on the port to set the power ON
  onewire->write(0x44, 1);
}

void DS18B20::getDataOfSensor(){
  searchSensor();
  setParasitePower();
  
  // Re-select the sensor and write on him
  onewire->reset();
  onewire->select(addr);    
  onewire->write(0xBE);
    
  // Reading the data associated with each position of the data array.
  // 9-bits data
  for (int i = 0; i < 9; i++) 
    data[i] = onewire->read();
    
  // Get a raw data and the configuration parameter
  rawData = (data[1] << 8) | data[0];
  cfg = (data[4] & 0x60);

  // Preparing the raw data to be returned to the readTemperature function
  if (cfg == 0x00)    rawData = rawData & ~7;
  else if (cfg == 0x20)   rawData = rawData & ~3;
  else if (cfg == 0x40)   rawData = rawData & ~1;
}
}