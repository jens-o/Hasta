

#include "Doorbell.h"

Doorbell::Doorbell(int pin) {
    _pin = pin;
}


void Doorbell::signal(int house, int unit) {
    sendMethod(house, unit, 1);
}
    
void Doorbell::sendMethod(int house, int unit, int method) {
    sendByte(house & 0xff);
    sendByte(unit & 0xff);
    sendByte(0);
	
    sendPulse(450, 14500);
}

void Doorbell::sendByte(unsigned char byte) {
    for(int i = 0; i < 8; ++i) {
		if (byte & 1) {
			sendPulse(1390, 490);
		} else {
			sendPulse(440, 1420);
		}
		byte >>= 1;
	}
}

void Doorbell::sendPulse(int lenH, int lenL) {
    digitalWrite(_pin, HIGH);
	delayMicroseconds(lenH);
    digitalWrite(_pin, LOW);
	delayMicroseconds(lenL);
    
    /*
    Serial.print(lenH);
    Serial.print("-");
    Serial.println(lenL);
    */
}
