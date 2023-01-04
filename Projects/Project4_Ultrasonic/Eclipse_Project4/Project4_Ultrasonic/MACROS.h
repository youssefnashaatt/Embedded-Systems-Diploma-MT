/*
 ============================================================================
 Name        : MACROS.h
 Author      : Youssef Nashaat
 Description : Common Macros Used
 Date        : 6/Oct./2022
 ============================================================================
 */

#ifndef MACROS_H_
#define MACROS_H_

/*Macro used to Set Bit in a Register*/
#define SET_BIT(REG,BIT_NO)			(REG = REG | (1<<BIT_NO))

/*Macro used to Clear Bit in a Register*/
#define CLEAR_BIT(REG,BIT_NO)		(REG = REG & ~(1<<BIT_NO))

/*Macro used to toggle bit in a register*/
#define TOGGLE_BIT(REG,BIT_NO)		(REG = REG ^ (1<<BIT_NO))

/*Macro used to check if Bit is set in a register*/
#define BIT_IS_SET(REG,BIT_NO)		(REG & (1<<BIT_NO))

/*Macro used to check if Bit is clear in a register*/
#define BIT_IS_CLEAR(REG,BIT_NO)	(!(REG & (1<<BIT_NO)))

/*Macro used to get bit in a register*/
#define GET_BIT(REG,BIT_NO)			((REG >> BIT_NO) & 1)


#endif /* MACROS_H_ */
