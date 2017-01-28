

#include "Hasta.h"

Hasta::Hasta(int pin) {
    _pin = pin;
}


void Hasta::up(int house, int unit) {
    sendMethod(house, unit, HASTA_UP);
}
    
void Hasta::down(int house, int unit) {
    sendMethod(house, unit, HASTA_DOWN);
}
    
void Hasta::stop(int house, int unit) {
    sendMethod(house, unit, HASTA_STOP);
}

void Hasta::sendMethod(int house, int unit, int method) {
    int sum = 0;
    
    sendPulse(2450, 10);
    sendPulse(2450, 2450);
    sendPulse(630, 10);
    sendPulse(630, 10);
    sendPulse(350, 350);

    sendByte( (house>>8) & 0xff );
    sum = ((house>>8)&0xFF);
    sendByte( house & 0xff );
    sum += (house & 0xFF);

    int byte = unit & 0x0F;

	if (method == HASTA_UP) {
		byte |= 0xC0;

	} else if (method == HASTA_DOWN) {
		byte |= 0x10;

	} else if (method == HASTA_STOP) {
		byte |= 0x50;

	} 

	sendByte(byte);
	sum += byte;

    sendByte(192);
    sum += 192;

    int checksum = ((static_cast<int>(sum/256)+1)*256+1) - sum;
	sendByte(checksum);
    
    sendPulse(630, 50);
}

void Hasta::sendByte(unsigned char byte) {
    for(int i = 0; i < 8; ++i) {
		if (byte & 1) {
			sendPulse(670, 270);
		} else {
			sendPulse(270, 670);
		}
		byte >>= 1;
	}
}

void Hasta::sendPulse(int lenH, int lenL) {
    
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
