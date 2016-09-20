/***********************************************************************************************************************
 * C Header: communicator-derivative.h
 * Component: Electricity Meter Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __COMMUNICATOR_DERIVATIVE_INTERFCE__
#define __COMMUNICATOR_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #endif

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/
#define COMMUNICATOR_selfData						ELECTRICITY_METER_APPLICATION_selfData.communicator
/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/

#define __communicator_getEvent()										COMMUNICATOR_selfData.event
#define __communicator_getState()                 					COMMUNICATOR_selfData.state

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
// Event setters
#define __communicator_clearEvents()									do{ __communicator_setEvent(__communicator_evNone); 							}while(0)
#define __communicator_setEvent(ev)									do{ COMMUNICATOR_selfData.event = (ev);	 									}while(0)
#define __communicator_setEventDone()									do{ __communicator_setEvent(__communicator_evDone); 							}while(0)
#define __communicator_setEventCommand()								do{ __communicator_setEvent(__communicator_evCommand); 							}while(0)
#define __communicator_setEventEntry()								do{ __communicator_setEvent(__communicator_evEntry); 							}while(0)

// State setters
#define __communicator_setState(st)									do{ COMMUNICATOR_selfData.state = (st);			 							}while(0)
#define __communicator_setStateRead()									do{ __communicator_setState(__communicator_stRead); 							}while(0)
#define __communicator_setStateWrite()								do{ __communicator_setState(__communicator_stWrite); 							}while(0)
#define __communicator_setStateWaitReceiver()						 	do{ __communicator_setState(__communicator_stWaitReceiver); 					}while(0)
#define __communicator_setStateRequestTransmitter()					do{ __communicator_setState(__communicator_stRequestTransmitter); 				}while(0)
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
typedef struct
{
	uint8_t event;
	uint8_t state;
}communicator_SelfData;
/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

//-- Client-like macros
#define communicator_requestCommand() 								do{ __communicator_setEventCommand(); 										}while(0)

//-- Server-like macros
#define communicator_confirm()										do{ __communicator_setEventDone(); 											}while(0)

/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
extern void communicator_init(void);
bool communicator_dispatchEvents(void);


#endif //__COMMUNICATOR_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
