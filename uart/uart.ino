#include <ESP8266WiFi.h>

const char* ssid = "";
const char* password = "";
String number;
float color;

#define blue_pin 14
#define green_pin 12 
#define red_pin 13

WiFiServer server(80);

void setup() {

pinMode(blue_pin,OUTPUT); 
 pinMode(green_pin,OUTPUT); 
 pinMode(red_pin,OUTPUT); 
  digitalWrite(blue_pin,HIGH);
 digitalWrite(green_pin,HIGH);
 digitalWrite(red_pin,HIGH);

 
  Serial.begin(115200);
  delay(10);


  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  number= request.substring(5, 10); 
    Serial.println(number);
    color=number.toFloat();
    Serial.println(color);


  if (request.indexOf("/off") > 0)  {
    analogWrite(blue_pin,0);
     analogWrite(green_pin,0);
     analogWrite(red_pin,0);
  }

  if (request.indexOf("/white") > 0)  {
    analogWrite(blue_pin,255);
     analogWrite(green_pin,255);
     analogWrite(red_pin,255);
  }
     if (color >= 1000 && color <=1255){
    int blue = color;
    blue = map(blue, 1000,1255,0,255);
    analogWrite(blue_pin,blue);
    Serial.println("modra");
    Serial.println(blue);
    delay(10);

    }
   
    if (color >=2000 && color <=2255){
      int green = color;
      green = map(green,2000,2255,0,255);
      analogWrite(green_pin,green);
      Serial.println("zelena");
      Serial.println(green);
      delay(10);
     
    }
   
    if (color >=3000 && color <= 3255){
      int red = color;
      red = map(red, 3000, 3255,0,255);
      analogWrite(red_pin,red);
      Serial.println("cervena");
      Serial.println(red);
      delay(10);
    }
    
}
