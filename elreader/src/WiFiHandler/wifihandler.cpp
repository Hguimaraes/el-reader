#include "wifihandler.h"

namespace EasyLab{
  WiFiHandler::WiFiHandler(const char* ssid, const char* pass){
    this->ssid = ssid;
    this->pass = pass;
    WiFi.mode(WIFI_STA);
  }

  WiFiHandler::~WiFiHandler(){
    delete[] ssid;
    delete[] pass;
  }
    
  bool WiFiHandler::isConnected(){
    return WiFi.status() == WL_CONNECTED;
  }

  bool WiFiHandler::Connect(){
    uint attempt = 0;
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED || attempt < nattempts) {
      attempt++;
      delay(1000);
    }

    return WiFi.status() == WL_CONNECTED;
  }

  IPAddress WiFiHandler::deviceIP(){
    return WiFi.localIP();
  }
}