#include "MKL46Z4.h"                    // NXP::Device:Startup
#include <stdio.h>
void init_sw() { 
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; /* Enable clock for port C */
	
	PORTC->PCR[3] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PTC->PDDR &= ~((uint32_t)(1u<<3)); 
	
	PORTC->PCR[3] |= PORT_PCR_IRQC(0xA);
	
	NVIC_ClearPendingIRQ(31);
	NVIC_EnableIRQ(31);
}

void init_led() {
	//This function enables the red LED on the FRDM-KL46Z development board
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //0x1000 = 1<<12
; //This enables the clock to PORTD
	PORTE->PCR[29] = (1 << 8);
; //This sets the Mux control of PTD5 to 001, or GPIO
	GPIOE->PDDR |= (1 << 29);
; //This sets PTD5 as an output. There are no masks defined for each pin so we have to do it by hand.
}

void PORTC_PORTD_IRQHandler(void) {
/* Put a proper name of PORTC_PORTD Interrupt service routine ISR. See startup_MKL46Z4.s file for function name */
/*do anything you want here*/
	uint32_t i = 0; 
	for (i =0; i < 5000; i++); 
	if ((PTC -> PDIR & (1<<3))==0) {
		PTE->PTOR = (1u<<29); 
	}
	PORTC->PCR[3] |= PORT_PCR_ISF_MASK;
	
/* Clear interrupt service flag in port control register otherwise int. remains active */
}

int main() {
	init_led(); 
	init_sw();
	while (1) {
		
	}
	return 0; 
}