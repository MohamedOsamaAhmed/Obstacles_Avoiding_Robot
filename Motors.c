#include "Motors.h"
#include <reg52.h>
#include "UltraSonic_Sensor.h"
#include "Delays_Functions.h"

/*
These are motor drivers to generate all possible motions 
*/
void moveStop(){ 
  P2 = 0x00;
}

void moveForward(){ 
  if (!goesForward)
	{
		goesForward = 1;
		P2 = 0x90;
	}
}
void moveBackward(){ 
  	goesForward = 0;
	P2 = 0x60;
}
void turnRight(){ 
	P2 = 0x50;
	Delay_ms(500);
	P2 = 0x50;
}
void turnLeft(){ 
	P2 = 0xA0;
	Delay_ms(500);
	P2 = 0xA0;
}