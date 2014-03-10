/*
 * timer_init.c
 *
 *  This software is distributed under the GPL.
 *  Software has been tested under real circumstances. Use this software on your on risk.
 *  Any source code resemblance to the any property of the third party's is purely coincidental.
 *
 *  Created on: 10. 3. 2014.
 *      Author: Sruk
 */

#include <msp430.h>
#include "timer_init.h"


/* TimerA init., clock, counting, clock divider*/

void timer_init(){

	TA0CTL = TASSEL_2 + MC_1 + ID_3; 	// SMCLK, count to CCR0, CLK/8

	TA0R = 0;							// reset TA0 register

}

/*WAIT time lapse function, maximal time 1000 ms*/

void timer_wait(unsigned int t){

	TA0R = 0;						// reset TA0 register

	if(t > 1000)					// check if interval is greater than max
		t = 1000;					// if true, use max value

	t = 65 * t;						// scale time value to counter value by multiply
	TA0CCR0 = t; 					// START, wait until CCR0 = t;

	while( TA0R < t ){}				// time lapses, waits for counter to finish


}
