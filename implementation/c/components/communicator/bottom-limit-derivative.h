/***********************************************************************************************************************
 * C Header: bottom-limit-derivative.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __BOTTOM_LIMIT_DERIVATIVE_INTERFCE__
#define __BOTTOM_LIMIT_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #endif

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/
typedef struct
{
	TOP_LIMIT_Limit bottom;
	TOP_LIMIT_Limit top;
}__bottom_limit_Limits;

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/
//General
#define __bottom_limit_getEvent()                                   ( BOTTOM_LIMIT_selfData.event )
#define __bottom_limit_getState()                                   ( BOTTOM_LIMIT_selfData.state )
//Limits
#define __bottom_limit_getTop() 									( BOTTOM_LIMIT_selfData.limit.top)

// Auxiliary

#define __bottom_limit_getAverage()									( ( __bottom_limit_getTop() + bottom_limit_getBottom() ) / 2 )

#define __bottom_limit_getAverageChar()								( BOTTOM_LIMIT_getGlossaryChar( __bottom_limit_getAverage() ) )
#define __bottom_limit_getTopChar()									( BOTTOM_LIMIT_getGlossaryChar( __bottom_limit_getTop()) )
#define bottom_limit_getBottomChar()								( BOTTOM_LIMIT_getGlossaryChar( bottom_limit_getBottom()) )

#define  __bottom_limit_areInnerLimitsAdjacent()					( ( bottom_limit_getBottom() - __bottom_limit_getTop() ) == 1 ? true : false )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
//General
#define __bottom_limit_setEvent(ev)                                 do{ BOTTOM_LIMIT_selfData.event = (ev);	                              		}while(0)
#define __bottom_limit_setState(st)                                 do{ BOTTOM_LIMIT_selfData.state = (st);	                              		}while(0)
// Set Event

#define __bottom_limit_setEventDo() 								do{__bottom_limit_setEvent( __bottom_limit_evDo );							}while(0)
#define __bottom_limit_setEventNone() 								do{__bottom_limit_setEvent( __bottom_limit_evNone );						}while(0)
#define __bottom_limit_setEventSearch() 							do{__bottom_limit_setEvent( __bottom_limit_evSearch );						}while(0)
// Set State
#define __bottom_limit_setStateIdle()		                		do{ __bottom_limit_setState( __bottom_limit_stIdle);			 			}while(0)
#define __bottom_limit_setStateRejected()		                		do{ __bottom_limit_setState( __bottom_limit_stRejected);			 			}while(0)
#define __bottom_limit_setStateCompareAverage()		                do{ __bottom_limit_setState( __bottom_limit_stCompareAverage ); 			}while(0)
#define __bottom_limit_setStatestMoveUpward()		                do{ __bottom_limit_setState( __bottom_limit_stMoveUpward ); 				}while(0)
#define __bottom_limit_setStateAdjacent()			                do{ __bottom_limit_setState( __bottom_limit_stAdjacent ); 					}while(0)
#define __bottom_limit_setStateFound()				                do{ __bottom_limit_setState( __bottom_limit_stFound ); 						}while(0)
#define __bottom_limit_setStateNotFound()			                do{ __bottom_limit_setState( __bottom_limit_stNotFound ); 					}while(0)

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
	BOTTOM_LIMIT_Event event;
	BOTTOM_LIMIT_State state;
	__bottom_limit_Limits limit;
}bottom_limit_SelfData;

/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/
#define bottom_limit_getBottom() 									( BOTTOM_LIMIT_selfData.limit.bottom )

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/
#define bottom_limit_indicateSearch()								do{ __bottom_limit_setEventSearch(); 										}while(0)

//Set Limits
#define bottom_limit_setBottom(position)							do{ BOTTOM_LIMIT_selfData.limit.bottom = ( position ); 						}while(0)
#define bottom_limit_setTop(position)								do{ BOTTOM_LIMIT_selfData.limit.top= ( position );							}while(0)


/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
void bottom_limit_init(void);
bool bottom_limit_dispatchEvents(void);

#endif //__BOTTOM_LIMIT_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
