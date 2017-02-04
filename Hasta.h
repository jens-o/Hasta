
#ifndef Hasta_h
#define Hasta_h

#include <Arduino.h>

#define HASTA_UP 12
#define HASTA_DOWN 1
#define HASTA_STOP 10


class Hasta {

  public:
    Hasta(int pin);
    
    void up(int house, int unit);
    void down(int house, int unit);
    void stop(int house, int unit);
  
  private:
    int _pin;

    void sendMethod(int house, int unit, int method);
    void sendByte(unsigned char b);
    void sendPulse(int lenH, int lenL);
    
};

#endif
