#include "MKL46Z4.h" // Device header
void InitLED(void)
{ //This function enables the red LED on the FRDM-KL46Z development board
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK; //0x1000 = 1<<12
; //This enables the clock to PORTD
	PORTD->PCR[5] = (1 << 8);
; //This sets the Mux control of PTD5 to 001, or GPIO
	GPIOD->PDDR |= (1 << 5);
; //This sets PTD5 as an output. There are no masks defined for each pin so we have to do it by hand.
}

void BlinkLED1(void)
{ //This method turns the LED off, then back on using two separate commands.
uint32_t i = 0; //Create a loop variable
; PTD->PDOR |= (1u<<5); //Change PTD5 to 1, turns LED OFF
for(i=0; i < 5000000; i++){}; //Burn some time
; PTD->PDOR &= ~((uint32_t)(1u<<5)); //Change PTD5 to 0, turns LED ON. .
for(i=0; i < 5000000; i++){}; //Burn some time
}

void InitLED2(void)
{ //This function enables the red LED on the FRDM-KL46Z development board
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //0x1000 = 1<<12
; //This enables the clock to PORTD
	PORTE->PCR[29] = (1 << 8);
; //This sets the Mux control of PTD5 to 001, or GPIO
	GPIOE->PDDR |= (1 << 29);
; //This sets PTD5 as an output. There are no masks defined for each pin so we have to do it by hand.
}

void BlinkLED2 (void) 
{
//This method turns the LED off, then back on using two separate commands.
uint32_t i = 0; //Create a loop variable
; PTD->PDOR |= (1u<<5); //Change PTD5 to 1, turns LED OFF
	PTE->PDOR &= ~((uint32_t)(1u<<29));
for(i=0; i < 5000000; i++){}; //Burn some time
; PTD->PDOR &= ~((uint32_t)(1u<<5)); //Change PTD5 to 0, turns LED ON. .
	PTE->PDOR |= (1u<<29);
for(i=0; i < 5000000; i++){}; //Burn some time
}
