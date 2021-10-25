void writeTS()
{
  if(WiFi.isConnected())
  {
    int a;
    a=ThingSpeak.writeField(strtoul(jsp.getJSONValueByKeyFromFile("/thingspeak.json","ChannelID").c_str(),nullptr,10),
                          1,
                          125,
                          jsp.getJSONValueByKeyFromFile("/thingspeak.json","WriteAPIKey").c_str());
    Serial.print(F("Thingspeak server response: "));
    Serial.println(a);
    Serial.print(F("Channel id:"));
    Serial.println(jsp.getJSONValueByKeyFromFile("/thingspeak.json","ChannelID"));
  }
}