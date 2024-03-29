// Sound.h
// This module contains the SysTick ISR that plays sound
// Runs on LM4F120 or TM4C123
// Program written by: Truc Do & Estela Rojas
// Date Created: 3/6/17 
// Last Modified: 10/22/19 
// Lab number: 6
// Hardware connections
/* This implementation is reserved for ISR of the SysTick
Sound_Init will prepare the SysTick clock and enable functions as of the SysTick_Init subroutine
Sound_Play is used to update the Reload (Counter) value of SysTick with the current period 
depending on the inputs from piano keys (switches)
Interrupt will be triggered every period, meaning every time the SysTick counts from period value to 1 to 0 and then rolls over
SysTick_Handler performs desired actions when everytime interrupt occurs,
which output the next digital amplitude of the sound wave array within one period
It toggles the LED of the Heartbeat every period as well
*/

#ifndef SOUND_H
#define SOUND_H
#include <stdint.h>
// Header files contain the prototypes for public functions
// this file explains what the module does

// **************Sound_Init*********************
// Initialize digital outputs and SysTick timer
// Called once, with sound/interrupts initially off
// Input: none
// Output: none
void Sound_Init(void);


// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period 
// Sound continues until Sound_Play called again
// This function returns right away and sound is produced using a periodic interrupt
// Input: interrupt period
//           Units of period to be determined by YOU
//           Maximum period to be determined by YOU
//           Minimum period to be determined by YOU
//         if period equals zero, disable sound output
// Output: none
void Sound_Play(uint32_t period);

void SysTick_Handler(void);

#endif

