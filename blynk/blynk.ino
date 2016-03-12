//#define BLYNK_DEBUG

//#define BLYNK_PRINT Serial  // Comment this out to disable prints and save space

#include <ESP8266.h>

#include <BlynkSimpleShieldEsp8266.h>

// Set ESP8266 Serial object

#define EspSerial Serial

ESP8266 wifi(EspSerial);

// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "";

void setup()

{

   Serial.begin(115200);  // Set console baud rate

  delay(10);

   EspSerial.begin(115200);  // Set ESP8266 baud rate

  delay(10);

  Blynk.begin(auth, wifi, "wi-fi name",
"pass");

}

void loop()

{

  Blynk.run();

}
