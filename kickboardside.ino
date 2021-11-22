#include <ESP8266WiFi.h>
#include <WiFiClient.h>
const char* host="192.168.4.1"; //Its the ip of the esp8266 as Access point
const char* ssid="Helmet";
const char* password="12345678"; 
const int httpPort=80;
String line="";

#define LED D4

void setup() {
  Serial.begin(9600);  
  WiFi.mode(WIFI_STA);    
  WiFi.begin(ssid, password);      //Connect to the server ESP8266
  while (WiFi.status() != WL_CONNECTED) {      
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());    

  pinMode(LED, OUTPUT);
}

void loop() {
   Serial.print("connecting to ");
   Serial.println(host);
   WiFiClient client; // Use WiFiClient class to create TCP connections
   if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
   }   
   client.print(String("GET ")+"/"+" HTTP/1.1\r\n"+"Host: "+host+"\r\n"+"Connection: close\r\n\r\n"); //Request to server   
   delay(10);
   while(client.available()){
      line = client.readStringUntil('\r'); // Read all the lines of the reply from server     
      Serial.println(line);
   }
   Serial.println("*");
   Serial.println(line);
   Serial.println("*");
   if(line == "\non"){
    digitalWrite(LED, LOW);
   }
   else if(line == "\noff"){
    digitalWrite(LED, HIGH);
   }
   Serial.println("closing connection");            
   delay(5000);
}
