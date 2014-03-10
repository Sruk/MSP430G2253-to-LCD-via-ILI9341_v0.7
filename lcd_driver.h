/*
 * lcd_driver.h
 *
 *  This software is distributed under the GPL.
 *  Software has been tested under real circumstances. Use this software on your on risk.
 *  Any source code resemblance to the any property of the third party's is purely coincidental.
 *
 *  Created on: 10. 3. 2014.
 *      Author: Sruk
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

void reset_lcd(void);
void write_data_lcd(char);
void write_cmd_lcd(char);
void write_16bdata_lcd(int);
void write_SPI(char);
void lcd_address_set(unsigned int ,unsigned int ,unsigned int ,unsigned int );
void lcd_test_color_adv(int, int, int, int, int);
void RGB_test(void);


#endif /* LCD_DRIVER_H_ */
