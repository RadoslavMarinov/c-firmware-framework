/***********************************************************************************************************************
 * C Header: top-limit-derivative.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __TOP_LIMIT_DERIVATIVE_INTERFCE__
#define __TOP_LIMIT_DERIVATIVE_INTERFCE__

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
}__top_limit_Limits;
/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/
#define __top_limit_getEvent()										( TOP_LIMIT_selfData.event )
#define __top_limit_getState()        								( TOP_LIMIT_selfData.state )


#define __top_limit_getBottom()										( TOP_LIMIT_selfData.limit.bottom )
#define __top_limit_getAverage()									( ( top_limit_getTop() + __top_limit_getBottom() ) / 2 )

#define __top_limit_getAverageChar()								( TOP_LIMIT_getGlossaryChar( __top_limit_getAverage() ) )
#define __top_limit_getTopChar()									( TOP_LIMIT_getGlossaryChar( __top_limit_getTop()) )
#define __top_limit_getBottomChar()									( TOP_LIMIT_getGlossaryChar( __top_limit_getBottom() ) )

#define  __top_limit_areInnerLimitsAdjacent()						( ( __top_limit_getBottom() - top_limit_getTop() ) == 1 ? true : false )



/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
#define __top_limit_setEvent(ev)									do{ TOP_LIMIT_assertEventNone();  TOP_LIMIT_selfData.event = (ev);          }while(0)
#define __top_limit_setState(st)									do{ TOP_LIMIT_selfData.state= (st); 										}while(0)

//-- Set Event
#define __top_limit_setEventNone()									do{ __top_limit_setEvent(__top_limit_evNone ); 								}while(0)
#define __top_limit_setEventDo()									do{ __top_limit_setEvent(__top_limit_evDo); 								}while(0)
#define __top_limit_setEventSearch()								do{ __top_limit_setEvent(__top_limit_evSearch); 							}while(0)

//-- Set State
#define __top_limit_setStateCompareAverage()						do{ __top_limit_setState( __top_limit_stCompareAverage);					}while(0)
#define __top_limit_setStateSearchDownward()						do{ __top_limit_setState( __top_limit_stSearchDownward);					}while(0)
#define __top_limit_setStateSearchUpward()							do{ __top_limit_setState( __top_limit_stSearchUpward);						}while(0)
#define __top_limit_setStateCompareBottom()							do{ __top_limit_setState( __top_limit_stCompareBottom);						}while(0)
#define __top_limit_setStateFound()									do{ __top_limit_setState( __top_limit_stFound); 							}while(0)
#define __top_limit_setStateNotFound()								do{ __top_limit_setState( __top_limit_stNotFound); 							}while(0)
#define __top_limit_setStateRejected()								do{ __top_limit_setState( __top_limit_stRejected); 							}while(0)
#define __top_limit_setStateIdle()									do{ __top_limit_setState( __top_limit_stIdle); 								}while(0)

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
	TOP_LIMIT_Event event;
	TOP_LIMIT_State state;
	__top_limit_Limits limit;
}top_limit_SelfData;

/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/
#define top_limit_getTop()										( TOP_LIMIT_selfData.limit.top )

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/
#define top_limit_setTop(possotion)								do{ TOP_LIMIT_selfData.limit.top = ( possotion ); 								}while(0)
#define top_limit_setBottom(possotion)							do{ TOP_LIMIT_selfData.limit.bottom = ( possotion ); 							}while(0)

#define top_limit_indicateReset()								do{ __top_limit_setEventReset(); 												}while(0)
#define top_limit_indicateSearch()								do{ __top_limit_setEventSearch(); 												}while(0)
/**********************************************************************************************************************
* Public function declarations( extern )
**********************************************************************************************************************/
void top_limit_init(void);
bool top_limit_dispatchEvents(void);


#endif //__TOP_LIMIT_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
