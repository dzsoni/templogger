
#include <Arduino.h>
#include <wifiTool.h>
#include <NTPtimeESP.h>
#include <TickerScheduler.h>
#include <ThingSpeak.h>
#include <SimpleJsonParser.h>

#define LED1 2
TickerScheduler tikersch(2);
WiFiClient  client;
strDateTime dateTime;
SimpleJsonParser jsp;

NTPtime ntp("/ntp.json", 1);
WifiTool wifiTool(dateTime,ntp);


#include <secTimer.h>
#include <writeTS.h>

void setup()
{
  Serial.begin(9600);
  Serial.println(F("\nSystem started."));

  if (!SPIFFS.begin())
  {
    // Serious problem
    Serial.println(F("SPIFFS Mount failed."));
  }

  Serial.print(F("NTP service started, connecting to:"));
  Serial.println(ntp.getNTPServer());

  wifiTool.begin();

  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  ntp.setSendInterval(30);
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  tikersch.add( 0, 1000, [&](void *) { secTimer(); }, nullptr, true);
  tikersch.add( 1, 20000,[&](void *) { writeTS();  }, nullptr, true);
  
}
void loop()
{
  wifiTool.process();
  tikersch.update();
}
