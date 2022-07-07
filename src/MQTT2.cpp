/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/darwinwang/Documents/IoT/MQTT2/src/MQTT2.ino"
void displaySetup();
void setup();
void loop();
#line 1 "/Users/darwinwang/Documents/IoT/MQTT2/src/MQTT2.ino"
SYSTEM_THREAD(ENABLED)

#include "MQTT.h"
#include "oled-wing-adafruit.h"
OledWingAdafruit display;

void callback(char *topic, byte *payload, unsigned int length);

MQTT client("lab.thewcl.com", 1883, callback);

void callback(char *topic, byte *payload, unsigned int length)
{
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;

  displaySetup();
  display.println(p);
  display.display();
  delay(2000);
  displaySetup();
  display.display();
}

void displaySetup()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
}

void setup()
{
  display.setup();
  displaySetup();
  display.setTextColor(WHITE);
  display.println("DISPLAY CONNECTED");
  display.display();
  delay(2000);
  display.display();
  displaySetup();
  display.display();
}

void loop()
{
  if (client.isConnected())
  {
    client.subscribe("newnewtopic");
    display.loop(); 
    client.loop();
    
  }
  else
  {
    client.connect(System.deviceID());
    client.publish("newnewtopic", "Argon 2 Connected");
  }
}