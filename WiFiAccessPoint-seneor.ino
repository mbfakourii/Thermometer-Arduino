//Go to http://192.168.4.1 in a web browser

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>


const int LM_35 = A0;
int input_val = 0;
float temp = 0;
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading


const char *ssid = "Thermometer";
const char *password = "12341234";

ESP8266WebServer server(80);

//define sensor variables
String show;

void get_sensor() {
 int analogValue = analogRead(A0);
  tempc=analogValue/4;
  show = "Temperature : " + String(tempc) ;
        
  server.send(200, "text/html", show);
}

void setup() {
pinMode(A0, INPUT);
  
  WiFi.softAP(ssid, password);
  server.on("/on", get_sensor);
  
  server.begin();
}

void loop() {
  server.handleClient();
}
