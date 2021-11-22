#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <ESP8266WebServer.h>
const char* ssid="Helmet";  // SSID of esp8266
const char* password="12345678";  
int i=0;
ESP8266WebServer server(80);    //Specify port for TCP connection

#define IRIN A0
#define IROUT D1

int readIR(){
  int in;
  digitalWrite(IROUT, HIGH);
  in = analogRead(IRIN);
  digitalWrite(IROUT, LOW);
  Serial.println(in);
  return in;
}

void handleRoot() {
  i=readIR();
  String s;
  if(i<1020){
    s = "on";
  }
  else{
    s = "off";
  }
  server.send(200,"text/html",s);      //Reply to the client
}

void setup() {
  delay(200);                          
  Serial.begin(9600);                 //Set Baud Rate
  WiFi.softAP(ssid,password);      //In Access Point Mode
  IPAddress myIP=WiFi.softAPIP();     //Check the IP assigned. Put this Ip in the client host.
  Serial.print("AP IP address: ");
  Serial.println(myIP);                 //Print the esp8266-01 IP(Client must also be on the save IP series)
  server.on("/",handleRoot);           //Checking client connection
  server.begin();                       // Start the server
  Serial.println("Server started");
  pinMode(IRIN, INPUT);
  pinMode(IROUT, OUTPUT);
  digitalWrite(IROUT, LOW);
}

void loop() {
  server.handleClient();
}
