#ifndef MYTHINGSPEAK_H
#define MYTHINGSPEAK_H

#include    <ThingSpeak.h>

class MyThingSpeak : public ThingSpeakClass 
{
private:
    /* data */
public:
    MyThingSpeak();
    MyThingSpeak(String jsonfilename);
    ~MyThingSpeak();
};

MyThingSpeak::MyThingSpeak(/* args */)
{
}

MyThingSpeak::~MyThingSpeak()
{
}














#endif