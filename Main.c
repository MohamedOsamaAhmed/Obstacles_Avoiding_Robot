/*

This Code for Obstacles Avoiding Robot using MC 80c51, 12MHz oscillator, Ultrasonic Sesnor HC-SR04 and 2 motors.
Author : Mohamed Osama Ahmed 
Date : 20/9/2020


*/


#include <reg52.h>
#include <stdio.h>
#include <intrins.h>
#include "obstacles_avoiding_robot_cfg.h"
#include "Servo.h"
#include "UltraSonic_Sensor.h"
#include "Delays_Functions.h"
#include "Motors.h"


void init_timer(void);

void init_timer(){
	TMOD=0x01;										/*initialize Timer*/
	TF0=0;
	TR0 = 0;
}




void main()
{
	
	
	int distanceRight = 0;
  int distanceLeft = 0;
	Delay_ms(50);  
	
	setServo_at_ZeroAngle();
	// only for testing ping of ultrasonic sensor where distance is the valid distance for the Robot
	Delay_ms(2000);
  distance = readPing();
  Delay_ms(100);
  distance = readPing();
  Delay_ms(100);
  distance = readPing();
  Delay_ms(100);
  distance = readPing();
  Delay_ms(100);
	

	
	
	init_timer();			/* Initialize Timer*/
	
	
	while (1)
	{
		
			distance = readPing();
		Delay_ms(100);
		
	
  if (distance <= 20 )
		{
    
			// this is a random steps to test robot 
				moveStop();
				Delay_ms(300);
				moveBackward();
				Delay_ms(400);
				moveStop();
				Delay_ms(300);
				// distanceRight is the right distance from the ultrasonic sensor 
				distanceRight = lookRight();
				Delay_ms(300);
			  // distanceLeft is the left distance from the ultrasonic sensor 
			
				distanceLeft = lookLeft();
				Delay_ms(300);

			 if (distance >= distanceLeft ){
					turnRight();
					moveStop();
				}
				else{
					turnLeft();
					moveStop();
				}
		}
		else{
    moveForward(); 
		}
	 
	 distance = readPing();
	
	}

}
