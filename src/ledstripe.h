#include <Arduino.h>

class ledstripe
{
private:
    bool status;
    unsigned int brigthness;
    String topic;
    unsigned int pinnumber;
    static int pwmFrequency;
    static int pwmResolution;
    static int usedPWMChannels;
    unsigned int pwmChannel;

public:
    ledstripe(String topic, unsigned int pin);
    void setBrigthness(unsigned int brightness);
    static void setPWMFrequency(unsigned int freq = 5000);
    static void setPWMResolution(unsigned int res = 8);


};


ledstripe::ledstripe(String topic, unsigned int pin){
    this->topic = topic;
    this->pinnumber = pin;
    this->brigthness = 0;
    this->pwmChannel = this->usedPWMChannels;
    this->usedPWMChannels++;
    this->setPWMFrequency();
    this->setPWMResolution();


    ledcSetup(this->pwmChannel,this->pwmFrequency, this->pwmResolution);
    ledcAttachPin(this->pinnumber,this->pwmChannel);


};

void ledstripe::setPWMFrequency(unsigned int freq = 5000){
    if (freq > 100 & freq < 10000)
    {
        pwmFrequency = freq;
    }
};


void ledstripe::setPWMResolution(unsigned int res = 8){
    if (res > 0 & res < 10)
    {
        pwmResolution = res;
    }
};

void ledstripe::setBrigthness(unsigned int brigthness){
    if (brigthness < 0) 
    {
        brigthness = 0;
    }
    else if (brigthness > 255)
    {
        brigthness = 255;
    }

    this->brigthness =brigthness;
    ledcWrite(this->pwmChannel, this->brigthness);

};



