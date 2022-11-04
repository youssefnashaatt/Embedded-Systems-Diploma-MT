/*
 ============================================================================
 Name        : LCD.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 24, 2022
 ============================================================================
 */

#include "Standard_Types.h"

#ifndef LCD_H_
#define LCD_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*LCD operating Number of Bits for Data*/
#define LCD_MODE_BITS	8


/*Define of LCD RS PIN (Port and Pin) on MC*/
#define LCD_RS_PORT_ID			PORTC_ID
#define LCD_RS_PIN_ID			PIN0_ID


/*Define of LCD ENABLE PIN (Port and Pin) on MC*/
#define LCD_ENABLE_PORT_ID		PORTC_ID
#define LCD_ENABLE_PIN_ID		PIN2_ID


#define LCD_DATA_PORT_ID		PORTD_ID


#if(LCD_MODE_BITS == 4)

#define LCD_DB4_PIN_ID			PIN0_ID
#define LCD_DB5_PIN_ID			PIN1_ID
#define LCD_DB6_PIN_ID			PIN2_ID
#define LCD_DB7_PIN_ID			PIN3_ID

#endif



/*Define Commands Value*/
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1  (0x33)
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2  (0x32)
#define LCD_TWO_LINES_FOUR_BITS_MODE		(0x28)
#define LCD_TWO_LINES_EIGHT_BITS_MODE		(0x38)
#define LCD_ENTRY_MODE						(0x06)
#define LCD_DISPLAY_OFF_CURSOR_OFF			(0x08)
#define	LCD_DISPLAY_ON_CURSOR_ON			(0x0E)
#define LCD_DISPLAY_ON_CURSOR_OFF			(0x0C)
#define LCD_DISPLAY_ON_CURSOR_BLINK			(0x0F)
#define LCD_SHIFT_DISPLAY_LEFT				(0x18)
#define LCD_SHIFT_DISPLAY_RIGHT				(0x1C)
#define LCD_MOVE_CURSOR_LEFT_ONE_STEP		(0x10)
#define LCD_MOVE_CURSOR_RIGHT_ONE_STEP		(0x14)
#define LCD_CLEAR_DISPLAY					(0x01)
#define LCD_SET_CURSOR_POSITION				(0x80)


/*******************************************************************************
 *                           Function Proto-types                              *
 *******************************************************************************/

void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_intgerToString(int data);
void LCD_clearScreen(void);

#endif /* LCD_H_ */
