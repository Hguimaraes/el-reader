#include "wifihandler.h"

namespace EasyLab{
  WiFiHandler::WiFiHandler(const char* ssid, const char* pass, String apikey)
  {
    this->ssid = ssid;
    this->pass = pass;
    this->apikey = apikey;
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

  void WiFiHandler::send(float intTemp, float extTemp){
    WiFiClient client;
  
    if (client.connect(endpointTS, httpport)) {
      String postStr = apikey;
      postStr += "&field1=";
      postStr += String(intTemp);
      postStr += "&field2=";
      postStr += String(extTemp);
      postStr += "\r\n\r\n";
       
      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apikey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);
    }

    client.stop();
  }
}