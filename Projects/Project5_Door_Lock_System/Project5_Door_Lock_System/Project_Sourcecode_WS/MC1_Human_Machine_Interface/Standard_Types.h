/*
 ============================================================================
 Name        : Standard_Types.h
 Author      : Youssef Nashaat
 Description : Frequently used Data-types
 Date        : Oct 16, 2022
 ============================================================================
 */

#ifndef STANDARD_TYPES_H_
#define STANDARD_TYPES_H_

#define NULL_PTR ((void*)0)

/*Typedef Boolean data-type*/
typedef unsigned char bool;

/*Defining Boolean Values*/
/*Define FALSE value in Boolean*/
#ifndef FALSE
#define FALSE (0u)
#endif

/*Define TRUE value in Boolean*/
#ifndef TRUE
#define TRUE (1u)
#endif

/*Logic Values*/
#define LOGIC_HIGH	(1u)
#define LOGIC_LOW	(0u)


/*Frequently used data-types independent on compiler*/
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;
typedef float float32;
typedef double float64;


#endif /* STANDARD_TYPES_H_ */
