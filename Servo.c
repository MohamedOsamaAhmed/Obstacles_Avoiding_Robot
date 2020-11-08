#include "Servo.h"
#include "obstacles_avoiding_robot_cfg.h"
#include <intrins.h>
#include "Delays_Functions.h"
#include "UltraSonic_Sensor.h"


int lookLeft(void){
	int distance = 0;
	//Turn to 90 degree
	setServo_at_Neg90Angle();
  Delay_ms(500);
  distance = readPing();
	Delay_ms(100);
	//Turn to 0 degree
	setServo_at_ZeroAngle(); 
	Delay_ms(100);
  return distance;
 
}

int lookRight(void){  
  int distance = 0;
	
	//Turn to 90 degree
  setServo_at_90Angle();
  Delay_ms(500);
  distance = readPing();
  Delay_ms(100);
	
	//Turn to 0 degree
	setServo_at_ZeroAngle(); 

 
  return distance;
}


void setServo_at_ZeroAngle(void)
{
	Servo_pin = 1;
  Delay_ms_servo(50);
  Servo_pin = 0;
	 
}
void setServo_at_90Angle(void)
{
	
   Servo_pin=1;
   Delay_ms_servo(82);
   Servo_pin=0;
	 
}
void setServo_at_Neg90Angle(void)
{
	 Servo_pin=1;
   Delay_ms_servo(110);
   Servo_pin=0;
}

