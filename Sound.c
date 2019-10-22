// Sound.c
// This module contains the SysTick ISR that plays sound
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
#include "dac.h"
#include "../inc/tm4c123gh6pm.h"
// #define the DAC Output array of sound wave (in decimals from 0 to 63)
const unsigned short Flute[64] = {6,7,9,9,10,11,12,13,13,14,15,
																	15,15,15,15,14,13,13,12,11,10,9,
																	8,7,7,6,6,5,5,5,5,4,
																	4,4,4,4,4,3,3,3,3,3,
																	2,2,1,1,1,1,0,0,0,0,
																	0,0,1,1,1,2,2,3,3,4,4,5};

// **************Sound_Init*********************
// Initialize digital outputs and SysTick timer
// Called once, with sound/interrupts initially off
// Input: none
// Output: none																						// Index of DAC_Out digital values (Flute[64])
	uint32_t Index;
void Sound_Init(void){
  DAC_Init();							// Call to initialize port B as inputs of DAC
	Index = 0;
	NVIC_ST_CTRL_R = 0;																							// 1) Diasble SysTick during setup
	NVIC_ST_RELOAD_R = 0x00000000;																	// 2) Setup time between each interupt
	NVIC_ST_CURRENT_R = 0;																					// 3) Write any value to current to clear it
//	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x60000000;			// Set Priority 3
	NVIC_ST_CTRL_R = 0x00000007; 																		// Enable/run counter with core clock & enable interupts
}

// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period (SysTick_Handler)
// Sound continues until Sound_Play called again
// This function returns right away and sound is produced using a periodic interrupt
// Input: interrupt period
//           Units of period to be determined by YOU
//           Maximum period to be determined by YOU
//           Minimum period to be determined by YOU
//         if period equals zero, disable sound output
// Output: none
// period = 80000000/32/freg
void Sound_Play(uint32_t period){
	NVIC_ST_RELOAD_R = period-1;																			// Update new period/frequency based on input from keys
//	DAC_Out(Flute[Index]);
//	Index=(Index+1)%64; 
}
void SysTick_Handler(void){
	DAC_Out(Flute[Index]);											// Output digital values to DAC every period 
	Index=(Index+1)%64;
	GPIO_PORTF_DATA_R ^= 0x00000006;						// Toggle PF2-1 of Hearbeat
}
