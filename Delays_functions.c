#include <reg52.h>
#include "Delays_Functions.h"
#include <intrins.h>

void Delay_ms_servo(unsigned int us)
{
  while(us--)
  {
    _nop_();
  }
}


void Delay_ms(unsigned int ms)
{
  unsigned long int us = ms*1000;
  while(us--)
  {
    _nop_();
  }
}



void Delay_us()
{
	TL0=0xF5;
	TH0=0xFF;
	TR0=1;
	while (TF0==0);
	TR0=0;
	TF0=0;
}
