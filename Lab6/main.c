 #include "MKL46Z4.h"

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

void init_SysTick(void) {
    SysTick->CTRL = 0; // Disable SysTick
    SysTick->LOAD = 999; // Count down from 999 to 0
    SysTick->VAL = 0; // Clear current value to 0
    SysTick->CTRL = 0x7; // Enable SysTick, enable SysTick
    // exception and use processor clock
}

int32_t volatile msTicks = 0; // Interval counter in ms
void init_SysTick_interrupt()
{
    SysTick->LOAD = SystemCoreClock / 1000; //configured the SysTick to count in 1ms
    /* Select Core Clock & Enable SysTick & Enable Interrupt */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |SysTick_CTRL_TICKINT_Msk|SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Handler (void) { // SysTick interrupt Handler
msTicks++; // Increment counter
}

void Delay (uint32_t TICK) {
    while (msTicks < TICK){}; // Wait 500ms
        msTicks = 0; // Reset counter
}

void main(void)
{
    /* Configure LED pin as GPIO output*/
    init_LED();
    init_SysTick_interrupt();
    /* Configure SysTick to count down to zero in 5 ms */
    while (1)
    {
    /* Call delay_using_SysTick function to wait 0.5 second */
    Delay(999);
    /* Toggle Red LED*/
    PTE->PTOR |= RED_LED_PIN; 
    PTD->PTOR |= GREEN_LED_PIN; 
    }
}