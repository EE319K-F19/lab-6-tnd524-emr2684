// dac.h
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on LM4F120 or TM4C123
// Program written by: Truc Do & Estela Rojas
// Date Created: 3/6/17 
// Last Modified: 10/22/19 
// Lab number: 6
// Hardware connections
/* This subroutine implementation use binary-weighted circuit with 6 inputs from the microcontroller 
to output one analog signal (in voltage) to external devices, such as speakers or headphones
DAC_Init initializes and sets up Port B from pins 5 to 0 as five inputs to the DAC
DAC_Out set digital amplitudes of the sound wave to Port B pins 5 to 0, 
which actually performs inputing action to the DAC
DAC_Out is also implemented with a LED of Heartbeat to detect the occurence of the ISR SysTick_Handler
*/

#ifndef DAC_H
#define DAC_H
#include <stdint.h>
// Header files contain the prototypes for public functions
// this file explains what the module does

// **************DAC_Init*********************
// Initialize 6-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void);


// **************DAC_Out*********************
// output to DAC
// Input: 6-bit data, 0 to 15 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint8_t data);

#endif
