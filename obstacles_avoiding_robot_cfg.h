/*
This File to configure your MC clock speed and wires connections 
*/
#ifndef __OBSTACLES_AVOIDING_ROBOT_CFG_H__
#define __OBSTACLES_AVOIDING_ROBOT_CFG_H__
#include <math.h>

#include <reg52.h>
#define sound_velocity 34300  	/* sound velocity in cm per second */
#define period_in_us pow(10,-6)
#define Clock_period period_in_us		/* period for clock cycle of 8051*/
#define maximum_distance 200

sbit Servo_pin = P1^7;
sbit Echo_pin= P2^0;		/* Echo pin */
sbit Trigger_pin=P1^1;        	/* Trigger pin */

#endif