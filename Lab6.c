// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: Truc Do & Estela Rojas
// Date Created: 3/6/17 
// Last Modified: 10/22/19 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********


#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"
// Define the 4 notes that wanted to be used
#define C	1194	// PE3
#define A 1420	// PE2
#define F 1790	// PE1
#define D	2128	// PE
//const uint32_t Notes[9] = {1,1790,1594,1420,1420,1265,1265,1265,1265};			// Periods of 4 notes B, A, G, F
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// Debugging tools
void Heartbeat_Init(void);															
void Heartbeat_Capture(void);
//void Oscilliscope(void);
int main(void){      
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  Piano_Init(); 																				// Port E (inputs) initialization
  Sound_Init(); 																				// SysTick and Port B (output) initializations 
  // other initialization
  EnableInterrupts();
	Heartbeat_Init();
//	Oscilliscope();
  while(1){									
		switch (Piano_In()){																// Read inputs from Port E --> period (index of Notes array) for each key
			case 0x01:
				Sound_Play(C);
				break;
			case 0x02:
				Sound_Play(A);
				break;
			case 0x04:
				Sound_Play(F);
				break;
			case 0x08:
				Sound_Play(D);
				break;
			default:
				Sound_Play(1);
		}
//	Heartbeat_Capture();
/*	Another method for If - Else If
		uint8_t input = Piano_In();
		if(input==0x01){
			Sound_Play(F);
		}else if(input==0x02){
			Sound_Play(G);
		}else if(input==0x04){
			Sound_Play(A);
		}else if(input==0x08){
			Sound_Play(B);
		}else{
		Sound_Play(1);
		}*/
		
/* To test DAC module:
		#include "DAC.h"   
  unsigned long Data; // 0 to 15 DAC output
 // PLL_Init();         // like Program 4.6 in the book, 80 MHz
  DAC_Init();
  for(;;) {
    DAC_Out(Data);
    Data = 0x0F&(Data+1); // 0,1,2...,14,15,0,1,2,...  
}*/
		
  } 
}

void Heartbeat_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x00000020;								// Turn on clocks of port F
	while((SYSCTL_RCGCGPIO_R&0x00000020)==0){};
	GPIO_PORTF_DIR_R |= 0x0000000E;									// PF3-1 as outputs
	GPIO_PORTF_DEN_R |= 0x0000000E;									// Enable digital PF3-1
	}

void Heartbeat_Capture(void){
	GPIO_PORTF_DATA_R ^= 0x00000008;								// Toggle green LED at PF3
	uint32_t delay=16000000;
	while(delay>0){delay=delay-1;};									// Wait between toggles
	}

void Oscilliscope(void){
	SYSCTL_RCGCGPIO_R |= 0x00000008;								// Turn on clock of port D
	while((SYSCTL_RCGCGPIO_R&0x00000008)==0){};		
	GPIO_PORTD_AMSEL_R |= 0x00000008;							// No analog function on pins PB5-0
	GPIO_PORTD_PCTL_R |= 0x00000008;								// Regular function on pins PB5-0
	GPIO_PORTD_DIR_R &= ~0x00000008;									// PE5-0 are outputs from microcontroller
	GPIO_PORTD_AFSEL_R |= 0x00000008;							// Diable alternative functions on pins PB5-0
	//GPIO_PORTD_DEN_R |= 0x0000003F;									// Enable digital PB5-0
	}
