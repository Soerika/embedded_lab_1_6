#include "MKL46Z4.h"
#include <stdbool.h>
/* The application starts with Core clock = 41.94MHz, BusClock = 13.98MHz */
#define BUSCLOCK_HZ (13.98 * 1000000)
#define BUSCLOCK_PERIOD_SEC ( 1 / BUSCLOCK_HZ )
#define EXPECT_TIMER1_MS (1000)
#define RED_LED_PIN (1<<29)
#define GREEN_LED_PIN (1<<5)

void init_LED(void) {
    SIM->SCGC5 |= ( SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK);
    
    // init red led
    PORTE->PCR[29] = PORT_PCR_MUX(1);
    PORTD->PCR[5] = PORT_PCR_MUX(1);
    
    PTE->PDDR |= RED_LED_PIN;
    
    PTD->PDDR |= GREEN_LED_PIN;
    
}

void PIT_enable(uint32_t ldval)
{
    SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; /* SIM_SCGC6: PIT=1 : Enable PIT Clock gate control*/
    PIT->MCR = 0x00U; //PIT_MCR: MDIS=0,FRZ=0 : Enable device clock
    PIT->CHANNEL[0].TCTRL = 0x00U; /* PIT_TCTRL0: CHN=0,TIE=0,TEN=0 : Clear control register */
    PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK; /* PIT_TFLG0: TIF=1: Clear timer flag register*/
    PIT->CHANNEL[0].LDVAL = PIT_LDVAL_TSV(ldval); /* PIT_LDVAL0: TSV=0xD1B6: Set up load register */
    NVIC_SetPriority(22, 2); /* Set priority for PIT IRQ22 */
    NVIC_EnableIRQ(22); /* Enable IRQ for PIT IRQ22 */
    /* PIT_TCTRL0: CHN=0,TIE=1,TEN=1 */
    PIT->CHANNEL[0].TCTRL = (PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK); /* Set up control register */
}

void PIT_IRQHandler()
{
PIT->CHANNEL[0].TFLG |= 1; // Clear timer interrupt flag
FPTE->PTOR |= RED_LED_PIN; //Control LEDs for debugging
}

int main(void)
{
// Initialize LEDs
    init_LED();
    //Configure PIT timer
    PIT_enable(0x4165124);
    while (1) {
    }
}