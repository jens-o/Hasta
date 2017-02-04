
#ifndef Doorbell_h
#define Doorbell_h

#include <Arduino.h>

class Doorbell {

  public:
    Doorbell(int pin);
    
    void signal(int house, int unit);
    
  private:
    int _pin;

    void sendMethod(int house, int unit, int method);
    void sendByte(unsigned char b);
    void sendPulse(int lenH, int lenL);
    
};

#endif
