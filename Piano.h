// Piano.h
// This software configures the off-board piano keys
// Lab 6 requires a minimum of 4 keys, but you could have more
// Runs on LM4F120 or TM4C123
// Program written by: Truc Do & Estela Rojas
// Date Created: 3/6/17 
// Last Modified: 10/22/19 
// Lab number: 6
// Hardware connections
/* This subroutine implementation interfaces with the input hardware, 4 key boards in this case,
Piano_Int initializes Port E pins from 3 to 0 as the inputs from the four piano key boards
Piano_In reads inputs that the keys provided
Four pull-up resistors are connected to four switches, represented the key boards, for positive logic
*/

#ifndef PIANO_H
#define PIANO_H
#include <stdint.h>
// Header files contain the prototypes for public functions
// this file explains what the module does

// **************Piano_Init*********************
// Initialize four piano key inputs, called once to initialize the digital ports
// Input: none 
// Output: none
void Piano_Init(void);

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 15 depending on keys
//   0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2, 0x08 is just Key3
//   bit n is set if key n is pressed
uint32_t Piano_In(void);

#endif

