#include "UltraSonic_Sensor.h"
#include "Delays_Functions.h"
#include "Obstacles_Avoiding_Robot_cfg.h"

/*
These are ultrasonic dreivers 
*/
char goesForward = 0;
float  distance_measurement = 0;
int distance = 100;

void send_trigger_pulse(){
	Trigger_pin= 1;           	/* pull trigger pin HIGH */
	Delay_us();               	/* provide 10uS Delay*/
	Trigger_pin = 0;          	/* pull trigger pin LOW*/
}

int readPing(){
	int cm = 0;
	float  value;
  Delay_ms(70);
	send_trigger_pulse();			/* send trigger pulse of 10us */
  	while(!Echo_pin)
		 {
			
		 }			/* Waiting for Echo */
		 
		 TR0 = 1;  /* Timer Starts */
   
		 while(Echo_pin && !TF0)
		{
		
		}			/* Waiting for Echo goes LOW */
    TR0 = 0;                    		/* Stop the timer */
	  
		/* calculate distance  timer */
		value = Clock_period * sound_velocity; 
		
	  	distance_measurement = (TL0|(TH0<<8));	/* read timer  for time count */
		  distance_measurement = (distance_measurement*value)/2.0;  /* find distance(in cm) */
	  
  cm = distance_measurement;
 if (cm==0){
    cm=250;
  }
 else if (cm > maximum_distance)
	 cm = maximum_distance;
  return cm;
}
