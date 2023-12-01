/*------------------------------------------------------------------------
* File LED.c
*----------------------------------------------------------------------*/
#include "MKL46Z4.h" // Device header
#include "cmsis_os.h" // RTOS:Keil RTX header
void blink_LED (void const *argument); // Prototype function
osThreadDef (blink_LED, osPriorityNormal, 1, 0); // Define blinky thread
void LED_Initialize (void) {
	//This function enables the red LED on the FRDM-KL46Z development board
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK; //0x1000 = 1<<12
; //This enables the clock to PORTD
	PORTD->PCR[5] = (1 << 8);
; //This sets the Mux control of PTD5 to 001, or GPIO
	GPIOD->PDDR |= (1 << 5);
; //This sets PTD5 as an output. There are no masks defined for each pin so we have to do it by hand.
	
}
/* Turn LED OFF */
void LED_Off (void) {
PTD->PSOR = (1u<<5); //Set PTD5 = 1, turns LED OFF (Cathode connected to PTD5)
}
/* Turn LED On */
void LED_On (void) {
PTD->PCOR = (1u<<5); //Clear PTD5 = 0, turns LED ON
} 


// Blink LED function
void blink_LED(void const *argument) {
for (;;) {
LED_On (); // Switch LED on
osDelay (500); // Delay 500 ms
LED_Off (); // Switch off
osDelay (500); // Delay 500 ms
}
}
void Init_BlinkyThread (void) {
osThreadCreate (osThread(blink_LED), NULL); // Create thread
}