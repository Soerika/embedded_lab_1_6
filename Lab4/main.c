#include "LED.h" //
int main(void)
{
/* Configure RED LED pin as GPIO output*/
	InitLED(); 
	InitLED2(); 
while (1)
{
/* Delay */
	BlinkLED2();
/* Toggle LED */
}
}