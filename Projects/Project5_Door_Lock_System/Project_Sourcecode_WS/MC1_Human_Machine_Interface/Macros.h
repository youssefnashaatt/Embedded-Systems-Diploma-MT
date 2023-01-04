/*
 ============================================================================
 Name        : Macros.h
 Author      : Youssef Nashaat
 Description : Common Macros
 Date        : Oct 16, 2022
 ============================================================================
 */
#ifndef MACROS_H_
#define MACROS_H_

/*Macro used to set a specific bit in a register*/
#define SET_BIT(REG, BIT_NO)		(REG = REG | (1<<BIT_NO))

/*Macro used to clear a specific bit in a register*/
#define CLEAR_BIT(REG, BIT_NO)		(REG = REG & ~(1<<BIT_NO))

/*Macro used to toggle a specific bit in a register*/
#define TOGGLE_BIT(REG, BIT_NO)		(REG = REG ^ (1<<BIT_NO))

/*Macro used to check if bit is set*/
#define BIT_IS_SET(REG, BIT_NO)		(REG & (1<<BIT_NO))

/*Macro used to check if bit is clear*/
#define BIT_IS_CLEAR(REG, BIT_NO)	( !(REG & (1<<BIT_NO)) )

/*Macro used to return a specific bit in a register*/
#define GET_BIT(REG, BIT_NO)		((REG>>BIT_NO) & 1)

#endif /* MACROS_H_ */
