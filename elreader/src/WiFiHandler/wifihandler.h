/**
 ** @file wifihandler.h
 ** @class WiFiHandler
 ** @Description:
 **  This file is a wrapper around the ESP8266WiFi library.
 ** The goal of this class is to provide a connection to the wifi network
 ** using the NodeMCU and also format the HTTP POST method to send data to
 ** a webserver.
 **/

#ifndef _WIFIHANDLER_H
#define _WIFIHANDLER_H

#include "Arduino.h"
#include "ESP8266WiFi.h"

namespace EasyLab{
class WiFiHandler {
  private:
    // WiFi name, password and max number of attempts to connect
    const char* ssid;
    const char* pass;
    String apikey;
    uint nattempts = 5;
    
    // URL to send the temperatures
    const char* endpointTS = "api.thingspeak.com";
    int httpport = 80;

    // Method to convert an IP of the WiFi library to string
    String ipToString(IPAddress ip);

  public:
    //  Constructor and destructor methods for WiFiHandler
    // We need to receive
    WiFiHandler(const char* ssid, const char* pass, String apikey);
    virtual ~WiFiHandler();
    
    // Method to check if the device is connected to the wifi network
    // Return true if is connected and false otherwise
    bool isConnected();
    
    // Method to connect the device to a wifi network
    bool Connect();

    // Get the local IP of the device on the network
    String deviceIP();

    // Send the temperatures to the cloud
    void send(float intTemp, float extTemp);
};
}

#endif