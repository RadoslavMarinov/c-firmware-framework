/**********************************************************************************************************************
 * C Header: bits.h
 * Component: Bits
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __BITS_INTERFACE__
#define __BITS_INTERFACE__

//Include component configuration file
#include "bits-configuration.h"


/**********************************************************************************************************************
* Class: Bits
**********************************************************************************************************************/

//Dependencies check
#ifndef _STDINT_H
	#error Missing required _STDINT_H
#endif

#ifndef BITS_count
	#error Missing required BITS_count
#endif

#ifndef BITS_selfData
	#error Missing required BITS_selfData
#endif

#ifndef BITS_isSingleTranslationUnit
	#error Missing required BITS_isSingleTranslationUnit()
#endif


//Private object-like macros

//Private function-like macros that DO return value
#define	__bits_getBytesInElement()					(sizeof(uint_fast8_t))
#define __bits_getBitsInElements()					(__bits_getBytesInElement() * 8)
#define __bits_getCountOfFullElements()				(BITS_count / __bits_getBitsInElements())
#define __bits_getPossitionOfRemainingBits()		(BITS_count	% __bits_getBitsInElements())
#define __bits_getCountOfElements()					( __bits_getCountOfFullElements() + (__bits_getPossitionOfRemainingBits() ? 1 : 0) )
#define __bits_getElementIndex(b)					((b) /__bits_getBitsInElements())
#define __bits_getBitPosition(b)					(1 << ((b) % __bits_getBitsInElements()))

//Private function-like macros that DO NOT return value

//Public typedefs, that DO NOT depend on external declarations

//Public object-like macros that DO NOT depend on external declarations

//Public function-like macros that DO return value and DO NOT depend on external declarations

//Public function-like macros that DO NOT return value and DO NOT depend on external declarations

//Public function declarations(extern), that DO NOT depend on external declarations

//Include header files of all(own) INTERNAL classes




//Public typedefs, that DO depend on external declarations
typedef struct
{
	uint_fast8_t elements[__bits_getCountOfElements()];
}bits_SelfData;

//Public object-like macros that DO depend on external declarations



//Public function-like macros that DO return value and DO depend on external declarations
#define bits_isBitRaised(b)						(BITS_selfData.elements[__bits_getElementIndex(b)] & __bits_getBitPosition(b))

//Public function-like macros that DO NOT RETURN value and DO depend on external declarations


#define bits_raiseBit(b)						do{BITS_selfData.elements[__bits_getElementIndex(b)] |= __bits_getBitPosition(b);}						while(0)
#define bits_clearBit(b)						do{BITS_selfData.elements[__bits_getElementIndex(b)] &= (~__bits_getBitPosition(b));}					while(0)
#define bits_toggleBit(b)						do{BITS_selfData.elements[__bits_getElementIndex(b)] ^= __bits_getBitPosition(b);}						while(0)
#define bits_setBit(b,v)						do{								\
													if(v)						\
														bits_raiseBit(b);		\
													else						\
														bits_clearBit(b);		\
												}while(0)

//Public function declarations(extern), that DO depend on external declarations


#endif //__BITS_INTERFACE__
/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/
