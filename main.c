/*
 * main.c
 *
 *  This software is distributed under the GPL.
 *  Software has been tested under real circumstances. Use this software on your on risk.
 *  Any source code resemblance to the any property of the third party's is purely coincidental.
 *
 *                       		  MSP430G2553
 *                     		       -----------------
 *                		   /|\|              XIN|-
 *                 		    | |                 |
 *                 		    --|RST          XOUT|-
 *                   		      |                 |
 *                   		      |             P1.6|-> LED(GREEN)
 *              	              |                 |
 *        		   LED(RED) <-|P1.0             |
 *				      |                 |
 *		 Data In (UCA0SOMI) ->|P1.1		|
 *				      |	                |
 *	     Data Out (UCA0SIMO)    <-|P1.2		|
 *				      |			|
 *	Serial Clock Out (UCA0CLK) <- |P1.4	    P2.4|-> Command/Data
 *				      |			|
 *		       Cable Select <-|P1.5         P2.3|-> Slave Reset
 *			              |			|
 *				       -----------------
 *
 *  SHORT DESCRIPTION:
 *  This source code (program) runs color LCD over the SPI protocol.
 *  Dedicated LCD drivers are ILI3940C, ILI3941.
 *
 *
 *  Created on: 10. 3. 2014.
 *      Author: Sruk
 */

#include <msp430.h>		/*Texas Instruments Inc. CCS5 library*/
#include "LCD_incl.h" 		/*includes all project header's*/

//Basic COMMANDS
#define DSPLY_OFF 	0x28
#define DSPLY_ON 	0x29

//Basic Colors
#define RED 		0xF800
#define GREEN 		0x07E0
#define BLUE 		0x001F
#define BLACK 		0x0000
#define YELLOW 		0xFFE0
#define WHITE 		0xFFFF

//Other Colors
#define CYAN		0x07FF
#define BRIGHT_RED	0xF810
#define GRAY1 		0x8410
#define GRAY2 		0x4208

typedef unsigned int uint16;

/*Declaring all external functions*/

extern void sys_init();
extern void timer_init();
extern void timer_wait(uint16);
extern void reset_lcd();
extern void write_data_lcd(char);
extern void write_cmd_lcd(char);
extern void write_16bdata_lcd(int);
extern void init_ILI9340C(void);
extern void lcd_test_color_adv(int, int, int, int, int);
extern void RGB_test_lcd(void);

/*Main program*/

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;		// Stop watchdog

	sys_init();						// See 'sys_init.c'

	timer_init();					// See 'timer_init.c'

	reset_lcd();					// See 'lcd_driver.c'

	timer_wait(100);				// See 'timer_init.c'

	init_ILI9340C();				// See 'lcd_config.c'

	RGB_test_lcd();					// See 'lcd_driver.c'

	P1OUT &= ~BIT6;					// Turn off green LED
	P1OUT |= BIT0;					// Turn on green LED
	_BIS_SR(CPUOFF);				// MSP430 shutdown

}
