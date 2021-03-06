/**********************************************************************************************************************
 * C Header: lock.h
 * Component: CMU
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __LOCK_INTERFACE__
#define __LOCK_INTERFACE__

//Include the component's configuration file
#include "cmu-configuration.h"

/**********************************************************************************************************************
 * Class: Oscillator Enable/Disable Command Register
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Dependency check
 **********************************************************************************************************************/

#ifndef LOCK_selfData
	#error Missing required LOCK_selfData
#endif

#ifndef LOCK_getPropertyValue
	#error Missing required LOCK_getPropertyValue(value, offset)
#endif

/**********************************************************************************************************************
 *Private typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private function-like macros that DO return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private function-like macros that DO NOT return value
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public object-like macros
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Public function-like macros that DO return value
 **********************************************************************************************************************/
	// LOCKKEY
#define lock_isLockkeyRaised()			( LOCK_selfData )


/**********************************************************************************************************************
 *Public function-like macros that DO NOT return value
 **********************************************************************************************************************/
	// Common methods
#define lock_setLockey(value)		do{ LOCK_setProperty(LOCK_selfData, lock_getLockeyMask(), value);									} while(0) 																		} while(0)

	// LOCKKEY
#define lock_raiseLockkey()			do{ LOCK_selfData = 0; 																				} while(0)
#define lock_clearLockkey()			do{ LOCK_selfData = 0x580E; 																		} while(0)


/**********************************************************************************************************************
 *Public function declarations (extern)
 **********************************************************************************************************************/


#endif //__LOCK_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
