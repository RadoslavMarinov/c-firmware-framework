/***********************************************************************************************************************
* C Header: xxx-yyy-derivative.h
* Component:
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include guard
**********************************************************************************************************************/
#ifndef __ELECTRICITY_METER_M90E32AS_DERIVATIVE_INTERFCE__
#define __ELECTRICITY_METER_M90E32AS_DERIVATIVE_INTERFCE__


/**********************************************************************************************************************
* Dependency check
**********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #endif

#ifndef ELECTRICITY_METER_M90E32AS_requestSpiExchangerRead
#error Missing required ELECTRICITY_METER_M90E32AS_requestSpiExchangerRead()
#endif

#ifndef ELECTRICITY_METER_M90E32AS_requestSpiExchangerWrite
#error Missing required ELECTRICITY_METER_M90E32AS_requestSpiExchangerWrite()
#endif

#ifndef ELECTRICITY_METER_M90E32AS_responseDoneRead
#error Missing required ELECTRICITY_METER_M90E32AS_responseDoneRead()
#endif

#ifndef ELECTRICITY_METER_M90E32AS_responseDoneWrite
#error Missing required ELECTRICITY_METER_M90E32AS_responseDoneWrite()
#endif

#ifndef ELECTRICITY_METER_M90E32AS_frameGetValue
#error Missing required ELECTRICITY_METER_M90E32AS_frameGetValue()
#endif



/**********************************************************************************************************************
* Include the derivative headers of the INTERNAL (owned) classes
**********************************************************************************************************************/
#include "frame-derivative.h"

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/
#define __electricity_meter_m90e32as_getState()						( ELECTRICITY_METER_M90E32AS_selfData.state )
#define __electricity_meter_m90e32as_getEvent()						( ELECTRICITY_METER_M90E32AS_selfData.event )

//== Auxiliaries

// Temporary
#ifdef MY_DEBUG
#define __electricity_meter_m90e32as_obtainRegister()				( ELECTRICITY_METER_M90E32AS_register[ __electricity_meter_m90e32as_getAddres() ] )
#endif
/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/



// Event setters
#define __electricity_meter_m90e32as_setEvent(ev)     do{ ELECTRICITY_METER_M90E32AS_selfData.event = (ev); 									}while(0)
#define __electricity_meter_m90e32as_clearEvents() 	  do{ __electricity_meter_m90e32as_setEvent( __electricity_meter_m90e32as_evNone ); 		}while(0)
#define __electricity_meter_m90e32as_setEventDone()   do{ __electricity_meter_m90e32as_setEvent( __electricity_meter_m90e32as_evDone ); 		}while(0)
#define __electricity_meter_m90e32as_setEventEntry()  do{ __electricity_meter_m90e32as_setEvent( __electricity_meter_m90e32as_evEntry ); 		}while(0)
#define __electricity_meter_m90e32as_setEventRead()   do{ __electricity_meter_m90e32as_setEvent( __electricity_meter_m90e32as_evRead ); 		}while(0)
#define __electricity_meter_m90e32as_setEventWrite()  do{ __electricity_meter_m90e32as_setEvent( __electricity_meter_m90e32as_evWrite ); 		}while(0)

// State setters
#define __electricity_meter_m90e32as_setState(st)	  do{ ELECTRICITY_METER_M90E32AS_selfData.state = (st); 									}while(0)
#define __electricity_meter_m90e32as_setStateFail()   do{ __electricity_meter_m90e32as_setState( __electricity_meter_m90e32as_stFail); 			}while(0)
#define __electricity_meter_m90e32as_setStateIdle()   do{ __electricity_meter_m90e32as_setState( __electricity_meter_m90e32as_stIdle ); 		}while(0)
#define __electricity_meter_m90e32as_setStateRead()   do{ __electricity_meter_m90e32as_setState( __electricity_meter_m90e32as_stRead ); 		}while(0)
#define __electricity_meter_m90e32as_setStateWrite()  do{ __electricity_meter_m90e32as_setState( __electricity_meter_m90e32as_stWrite ); 		}while(0)


// Other setters

// Temporary
#ifdef MY_DEBUG
#define __electricity_meter_m90e32as_setRegisterElement(element, value) do{ ELECTRICITY_METER_M90E32AS_selfData.registers[element] = (value); }while(0)
#endif
/**********************************************************************************************************************
* Protected typedefs (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected object-like macros  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected function-like macros that DO return value  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected function-like macros that DO NOT return value  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public typedefs  (xxx)
**********************************************************************************************************************/
typedef uint16_t electricity_meter_m90e32as_Register[ELECTRICITY_METER_M90E32AS_getRegisterCount()];

typedef struct
{
	ELECTRICITY_METER_M90E32AS_Event event;
	ELECTRICITY_METER_M90E32AS_State state;
	ELECTRICITY_METER_M90E32AS_FrameSelfData frame;
	electricity_meter_m90e32as_Register registers;
}electricity_meter_m90e32as_SelfData;

/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/



// Temporary
#ifdef MY_DEBUG
#define electricity_meter_m90e32as_getRegister()					( ELECTRICITY_METER_M90E32AS_selfData.registers )
#endif //MY_DEBUG


/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/


#define electricity_meter_m90e32as_isBusy()				( __electricity_meter_m90e32as_getState() != __electricity_meter_m90e32as_stIdle ? \
																	true : false )
#define electricity_meter_m90e32as_getValue()						( ELECTRICITY_METER_M90E32AS_frameGetValue() )
#define electricity_meter_m90e32as_getAddress()						( ELECTRICITY_METER_M90E32AS_frameGetAddress() )


/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

//== Server-like methods
#define electricity_meter_m90e32as_indicateRead(address)			do{ \
																		ELECTRICITY_METER_M90E32AS_frameRead(address);\
																		__electricity_meter_m90e32as_setEventRead();\
																	}while(0)

#define electricity_meter_m90e32as_indicateWrite(address, value)	do{ \
																		ELECTRICITY_METER_M90E32AS_frameWrite(address, value);\
																		__electricity_meter_m90e32as_setEventWrite();\
																	}while(0)
//== Client-like methods
#define electricity_meter_m90e32as_confirmDone()				do{ __electricity_meter_m90e32as_setEventDone(); 	}while(0)

// Temporary
#ifdef MY_DEBUG
#define electricity_meter_m90e32as_obtainRegister()					do{ __electricity_meter_m90e32as_setValue( \
																		__electricity_meter_m90e32as_obtainRegister() );\
																	}while(0)

#define electricity_meter_m90e32as_writeRegister()					do{ ELECTRICITY_METER_M90E32AS_register[ __electricity_meter_m90e32as_getAddres() ]\
	    																= (__electricity_meter_m90e32as_getValue());\
																	}while(0)
#endif //MY_DEBUG
/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
extern void electricity_meter_m90e32as_init(void);
extern bool electricity_meter_m90e32as_dispatchEvents(void);
/**********************************************************************************************************************
* Public Objects declaration
**********************************************************************************************************************/
	//extern ccc_SelfData ccc_selfData;


#endif //__ELECTRICITY_METER_M90E32AS_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
