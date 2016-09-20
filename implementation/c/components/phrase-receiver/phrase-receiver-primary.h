/**********************************************************************************************************************
 * C Header: receiver-primary.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __PHRASE_RECEIVER_PRIMARY_INTERFACE__
#define __PHRASE_RECEIVER_PRIMARY_INTERFACE__

 /**********************************************************************************************************************
 * Include the primary headers of the INTERNAL (owned) classes
 **********************************************************************************************************************/
#include "phrase-primary.h"
#include "word-primary.h"


/**********************************************************************************************************************
* Private  constants  (__xxx_)
**********************************************************************************************************************/
//-- events
enum
{
	__phrase_receiver_evNone,
	__phrase_receiver_evReset,
	__phrase_receiver_evBufferOverflow,
	__phrase_receiver_evInvalidCharacter,
	__phrase_receiver_evNonSpace,
	__phrase_receiver_evSpace,
	__phrase_receiver_evEndOfFrame,
};

//-- states
enum
{
__phrase_receiver_stComplete,
__phrase_receiver_stSpace,
__phrase_receiver_stName,
__phrase_receiver_stNameDelimiter,
__phrase_receiver_stValue,
__phrase_receiver_stValueDelimiter,
};

 /**********************************************************************************************************************
 * Private  typedefs  (__xxx_)
 **********************************************************************************************************************/


 /**********************************************************************************************************************
 * Private  Object-like macro definitions  (__xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private Function-like macro definitions  (__xxx_)  that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private Function-like macro definitions  (__xxx_) that DON'T RETURN VALUE
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected typedefs  (__xxx_)
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Protected Object-like macro definitions  (__xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected Function-like macro definitions  (__xxx_)  that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Protected Function-like macro definitions  (__xxx_) that DON'T RETURN VALUE
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public  typedefs  (xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public  Object-like macro definitions  (xxx_)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public Function-like macro definitions  (xxx_)  that DO return value
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public Function-like macro definitions  (xxx_) that DON'T RETURN VALUE
 **********************************************************************************************************************/


#endif //__PHRASE_RECEIVER_PRIMARY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
