// Piano.c
// This software configures the off-board piano keys
// Lab 6 requires a minimum of 4 keys, but you could have more
// Runs on LM4F120 or TM4C123
// Program written by: Truc Do & Estela Rojas
// Date Created: 3/6/17 
// Last Modified: 10/22/19 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// **************Piano_Init*********************
// Initialize four piano key inputs, called once to initialize the digital ports
// Input: none 
// Output: none
void Piano_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x00000010;								// Turn on clock of port E
	while((SYSCTL_RCGCGPIO_R&0x00000010)==0){};			// Wait for clock
	GPIO_PORTE_AMSEL_R &= ~0x0000000F;							// No analog function on pins PE3-0
	GPIO_PORTE_PCTL_R &= ~0x0000000F;								// Regular function on pins PE3-0
	GPIO_PORTE_DIR_R &= ~0x0000000F;								// PE3-0 are inputs from piano key
	GPIO_PORTE_AFSEL_R &= ~0x0000000F;							// Diable alternative functions on pins PE3-0
	GPIO_PORTE_DEN_R |= 0x0000000F;									// Enable digital PE3-0
}

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 15 depending on keys
//   0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2, 0x08 is just Key3
//   bit n is set if key n is pressed
//	 Only 1 key is pressed at the same time
uint32_t Piano_In(void){
	uint32_t note;
	note = GPIO_PORTE_DATA_R&0x0000000F;						// Read inputs from PE3-0
  return (note); // Replace with your code
}
