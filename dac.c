// dac.c
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on LM4F120 or TM4C123
// Program written by: Truc Do & Estela Rojas
// Date Created: 3/6/17 
// Last Modified: 10/22/19
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x00000002;								// Turn on clocks of ports B //(and F)
	while((SYSCTL_RCGCGPIO_R&0x00000002)==0){};			// Wait for clock
	GPIO_PORTB_AMSEL_R &= ~0x0000003F;							// No analog function on pins PB5-0
	GPIO_PORTB_PCTL_R &= ~0x0000003F;								// Regular function on pins PB5-0
	GPIO_PORTB_DIR_R |= 0x0000003F;									// PE5-0 are outputs from microcontroller
	GPIO_PORTB_AFSEL_R &= ~0x0000003F;							// Diable alternative functions on pins PB5-0
	GPIO_PORTB_DEN_R |= 0x0000003F;									// Enable digital PB5-0
	
//	GPIO_PORTF_DIR_R |= 0x0000000E;									// PF2-1 as outputs
//	GPIO_PORTF_DEN_R |= 0x0000000E;									// Enable digital PF2-1
}

// **************DAC_Out*********************
// output to DAC
// Input: 6-bit data, 0 to 63 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint32_t data){
	GPIO_PORTB_DATA_R = data;											// Output to PB5-0 
 }

