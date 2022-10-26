#include <Arduino.h>

class tuer
{
private:
    bool status;
    String topic;
    unsigned int pinnumber;
public:
    tuer(String topic, unsigned int pin);
    void loop();

};


tuer::tuer(String topic, unsigned int pin){
    this->topic = topic;
    this->pinnumber = pin;

    pinMode(this->pinnumber,INPUT);
    this->loop();

};

void tuer::loop(){
    this->status = digitalRead(this->pinnumber);
}