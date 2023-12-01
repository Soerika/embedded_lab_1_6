#include "MKL46Z4.h"                    // NXP::Device:Startup

void init_sw() { 
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; /* Enable clock for port C */
	
	PORTC->PCR[3] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PTC->PDDR &= ~((uint32_t)(1u<<3));
	
	PORTC->PCR[12] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PTC->PDDR &= ~((uint32_t)(1u<<12));
}

void init_led() {
	//This function enables the red LED on the FRDM-KL46Z development board
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //0x1000 = 1<<12
; //This enables the clock to PORTD
	PORTE->PCR[29] = (1 << 8);
; //This sets the Mux control of PTD5 to 001, or GPIO
	GPIOE->PDDR |= (1 << 29);
; //This sets PTD5 as an output. There are no masks defined for each pin so we have to do it by hand.
	
	
	//This function enables the green LED on the FRDM-KL46Z development board
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK; //0x1000 = 1<<12
; //This enables the clock to PORTD
	PORTD->PCR[5] = (1 << 8);
; //This sets the Mux control of PTD5 to 001, or GPIO
	GPIOD->PDDR |= (1 << 5);
; //This sets PTD5 as an output. There are no masks defined for each pin so we have to do it by hand.
}

void led_toggle() {
	if ((PTC -> PDIR & (1<<3))==0) /* Pressed SW1 */
	{
		/* do something */ 
		PTE->PDOR &= ~((uint32_t)(1u<<29));
		
	}
	else /* unPressed SW1 */
	{
		/* do something */
		PTE->PDOR |= (1u<<29); 
	}
	
	if ((PTC -> PDIR & (1<<12))==0) /* Pressed SW1 */
	{
		/* do something */ 
		PTD->PDOR &= ~((uint32_t)(1u<<5));
	}
	else /* unPressed SW1 */
	{
		/* do something */
		PTD->PDOR |= (1u<<5);
	}
}

int main() {
	init_led(); 
	init_sw();
	while (1) {
		
		led_toggle(); 
	}
}