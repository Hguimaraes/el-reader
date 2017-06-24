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

  String WiFiHandler::deviceIP(){
    return ipToString(WiFi.localIP());
  }

  // Thanks to: http://www.esp8266.com/viewtopic.php?p=38315
  String WiFiHandler::ipToString(IPAddress ip){
    String s="";
    for (int i=0; i<4; i++)
      s += i  ? "." + String(ip[i]) : String(ip[i]);
    return s;
  }
}