#ifndef __ULTRASONIC_SENSOR_H__
#define __ULTRASONIC_SENSOR_H__

extern char goesForward;
extern  float  distance_measurement;
extern int distance;

void send_trigger_pulse(void);
int readPing(void);	

#endif