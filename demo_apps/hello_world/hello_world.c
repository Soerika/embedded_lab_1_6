/*
 * The Clear BSD License
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"

#include <stdio.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
 
/*
int a(void);
int a(void)
{
    static int i = 10;
    i++;
    return (i);
}
*/ 



int main(void)
{
    char ch;

    /* Init board hardware. */
		/* NOT EDITING !! */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
		
		/*
    PRINTF("hello world.\r\n");

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
    }
	*/ 
	
	/*
		int p, n;
    for (n = 1; n < 10; n++)
    {
        p = a();
        PRINTF("Invocation %i, return value %i\n", n, p);
    }
		while(1) {
		}
	*/
	
	
	int x[8];
	int i;
	int *p; 
	for (i = 0; i < 8; i++)
		x[i] = i;
	for (i = 0; i < 8; i++)
    PRINTF("\r\nelement %i = %i\r\n", i, x[i]);
	for (i = 0; i < 8; i++)
	{
			p = x + i;
			*p = 8 - i;
	}
	for (i = 0; i < 8; i++)
    PRINTF("\r\nelement %i = %i\r\n", i, x[i]);
	
	/*
	int a, b, s;
    PRINTF("Add two integers\r\n");
    PRINTF(" Enter first number:");
    SCANF("%i", &a); PRINTF("%i", a);
    PRINTF("\r\n Enter second number:");
    SCANF("%i", &b); PRINTF("%i", b);
    s = a + b;
    PRINTF("\r\n Sum of two integers is: %i\r\n", s); 
	*/ 
		while(1) {
		}
}
