/*
 ============================================================================
 Name        : LCD.h
 Author      : Youssef Nashaat
 Description :
 Date        : Oct 6, 2022
 ============================================================================
 */
#ifndef LCD_H_
#define LCD_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LCD_MODE_BITS	8

#if((LCD_MODE_BITS != 4) && (LCD_MODE_BITS != 8))
#error "Number of Data bits should be equal to 4 or 8"
#endif

/*LCD Hardware Configuration*/
/*RS Pin Configuration*/
#define LCD_RS_PORT_ID			PORTB_ID
#define LCD_RS_PIN_ID			PIN0_ID

/*RS Pin Configuration*/
#define LCD_RW_PORT_ID			PORTB_ID
#define LCD_RW_PIN_ID			PIN1_ID

/*Enable Pin Configuration*/
#define LCD_Enable_PORT_ID 		PORTB_ID
#define LCD_Enable_PIN_ID		PIN2_ID

/*8 Bit-Mode Data Port_ID*/
#define LCD_DATA_PORT_ID		PORTA_ID

#if(LCD_MODE_BITS == 4)

#define LCD_DB4_ID				PIN3_ID
#define LCD_DB5_ID				PIN4_ID
#define LCD_DB6_ID				PIN5_ID
#define LCD_DB7_ID				PIN6_ID

#endif


/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*Description:
 * Initialization function.
 * Argument Type: void.
 * Return void.
 */
void LCD_init(void);



/*Description:
 * Sending Command to LCD whether 8Bits mode or 4Bits mode.
 * Argument Type: uint8 (command value)
 * Return void
 */

void LCD_sendCommand(uint8 cmd);



/*Description:
 * Sending Character to LCD whether 8Bits mode or 4Bits mode.
 * Argument Type: uint8 (command value)
 * Return void
 */
void LCD_displayCharacter(uint8 character);



/*Description:
 * Sending Character to LCD whether 8Bits mode or 4Bits mode.
 * Argument Type: uint8 (command value)
 * Return void
 */
void LCD_displayString(const char *string);



/*Description:
 * Move the cursor to any direction within 2x16 LCD.
 * Argument Type: uint8: row location & uint8: column location
 * Return void
 */
void LCD_moveCursor(uint8 row, uint8 col);



/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);



/*Description :
 * Clear Screen Command Function
 */
void LCD_clearScreen(void);



/*Description :
 * Converting integer variable to string
 */
void LCD_intgerToString(int integer);


#endif /* LCD_H_ */
