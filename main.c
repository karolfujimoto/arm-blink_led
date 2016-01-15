#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"	//Header file to registers address masks
/*
 * main.c
 */
void wait(void);
int main(void) {
	//System Control General Purpose I/O Run Mode Gating Control - Pag. 430
	//Enable the GPIO PORTF's clock
	SYSCTL_RCGCGPIO_R |= 0x20;
	//General Purpose PORTF Data Direction - Pag. 26
	//Set Pins 0, 1 and 2 to output
	GPIO_PORTF_DIR_R |= 0x07;
	//General Purpose PORTF Alternate Function Select - Pag. 602
	//Set the default pin operation
	GPIO_PORTF_AFSEL_R &= 0x00;
	//General Purpose PORTF Digital Circuits Enable - Pag. 682
	GPIO_PORTF_DEN_R |= 0x07;
	while(1) {
		//PORTF Data Register
		GPIO_PORTF_DATA_R &= ~0x0E;
		wait();
		GPIO_PORTF_DATA_R |= 0x0E;
		wait();
	}
}
void wait(void)
{
	int i;
	for(i=0;i<1000000;i++);
}
