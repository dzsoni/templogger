
void secTimer ()
{
  digitalWrite  (LED1, !digitalRead(LED1));
  strDateTime prevtime = dateTime;
  if (WiFi.isConnected())
  {
    dateTime = ntp.getNTPtime();
    if (dateTime.valid)
    {
      ntp.printDateTime(dateTime);
      return;
    }
  }
  if(prevtime.epochTime!=0)
  {
  prevtime.epochTime++;
  dateTime = ntp.ConvertUnixTimestamp(prevtime.epochTime);
  dateTime.valid = true;
  Serial.print("+");
  ntp.printDateTime(dateTime);
  }
}
