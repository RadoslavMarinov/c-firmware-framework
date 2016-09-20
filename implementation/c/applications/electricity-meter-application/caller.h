/**********************************************************************************************************************
 * C Header: caller.h
 * Component: Electricity Meter Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __CALLER_INTERFACE__
#define __CALLER_INTERFACE__

//Include the component's configuration file
#include "electricity-meter-application-configuration.h"

/**********************************************************************************************************************
 * Class: Caller
 **********************************************************************************************************************/

//Dependency check
#ifndef _STDBOOL_H
	#error Missing required _STDBOOL_H
#endif

#ifndef CALLER_isBitRaised
	#error Missing required CALLER_isBitRaised(b)
#endif

#ifndef CALLER_raiseBit
	#error Missing required CALLER_raiseBit(b)
#endif

#ifndef CALLER_clearBit
	#error Missing required CALLER_clearBit(b)
#endif

#ifndef CALLER_toggleBit
	#error Missing required CALLER_toggleBit(b)
#endif

#ifndef CALLER_setBit
	#error Missing required CALLER_setBit(b,v)
#endif

#ifndef CALLER_confirmMeterInitializationBit
	#error Missing required CALLER_confirmMeterInitializationBit
#endif

#ifndef CALLER_confimMeterReadingsBit
	#error Missing required CALLER_confimMeterReadingsBit
#endif

#ifndef CALLER_selfData
	#error Missing required CALLER_selfData
#endif

#ifndef CALLER_requestMeterInitialization
	#error Missing required CALLER_requestMeterInitialization()
#endif

//Private object-like macros
#define __caller_state				CALLER_selfData.state

//Private function-like macros that DO return value

//Private function-like macros that DO NOT return value
#define caller_setStateState1()		do{CALLER_selfData.state = __caller_stState1;}while(0)

//Public typedefs
typedef struct caller_SelfData
{
	uint_fast8_t state;
}caller_SelfData;

//Public object-like macros

//Public function-like macros that DO return value

//Public function-like macros that DO NOT return value

//Public function declarations (extern)
///extern void caller_init(void);
///extern void caller_confirmMeterInitialization(bool result);
///extern void caller_confirmMeterReadings(bool result);
///extern bool caller_dispatcher(void);

#endif /*__CALLER_INTERFACE__*/

/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/
