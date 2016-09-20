/***********************************************************************************************************************
 * C Header: range-derivative.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __RANGE_DERIVATIVE_INTERFCE__
#define __RANGE_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * DepBottomency check
 **********************************************************************************************************************/
// #ifndef
// 	#error Missing required
// #Bottomif

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

typedef struct
{
	RANGE_RowIndex top;
	RANGE_RowIndex bottom;
}__range_RowLimits;


/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/
#define __range_selfData RANGE_selfData
/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/

#define __range_getState()											( RANGE_selfData.state )
#define __range_getEvent()                                          ( RANGE_selfData.event )
#define __range_isIn(st)                                            ( st == __range_getState() )
#define __range_isInSetTop()                                        ( __range_isIn( __range_stSetTop ) )
#define __range_isInSetBottom()                                     ( __range_isIn( __range_stSetBottom ) )
#define __range_isCharOutOfRnage(ch)								( ( (ch) < RANGE_getGlossaryChar( range_getTop() ) ) ||\
																	( (ch) > RANGE_getGlossaryChar( range_getBottom() ) ) ? true : false )
#define __range_doCharactersMatch()									( ( RANGE_getGlossaryChar( range_getTop() ) == range_getChar() ) ? true: false )
#define __range_doLimitsMatch()										( ( range_getTop() == range_getBottom() ) ? true : false )
/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
#define __range_setEvent(ev)										do{ RANGE_selfData.event = (ev); 											}while(0)
#define __range_setState(st)										do{ RANGE_selfData.state = (st); 											}while(0)

//event setters
#define __range_setEventEntry()										do{ RANGE_selfData.event = ( __range_evEntry );								}while(0)
#define __range_setEventDo()										do{ __range_setEvent( __range_evDo );                                    	}while(0)
#define __range_setEventDone()										do{ __range_setEvent( __range_evDone );                                    	}while(0)
#define __range_setEventFail()										do{ __range_setEvent( __range_evFail );                                    	}while(0)
#define __range_setEventNone()										do{ __range_setEvent( __range_evNone );                                    	}while(0)
#define __range_setEventReset()										do{ __range_setEvent( __range_evReset );                                   	}while(0)
#define __range_setEventSelect()									do{ __range_setEvent( __range_evSelect );                                 	}while(0)

//state setters
#define __range_setStateCompareCharacters()                         do{ __range_setState( __range_stCompareCharacters );                    	}while(0)
#define __range_setStateIdle()                                      do{ __range_setState( __range_stIdle );                                     }while(0)
#define __range_setStateNotFound()                                  do{ __range_setState( __range_stNotFound );                                 }while(0)
#define __range_setStateSelected()                                  do{ __range_setState( __range_stSelected );                                 }while(0)
#define __range_setStateSetBottom()                                 do{ __range_setState( __range_stSetBottom );                                }while(0)
#define __range_setStateSetTop()                                    do{ __range_setState( __range_stSetTop );                                   }while(0)

// auxiliary



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
	RANGE_Event event;
	RANGE_State state;
	uint8_t character;
	__range_RowLimits limit;
}range_SelfData;
/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/
#define range_getTop()  											( RANGE_selfData.limit.top  )
#define range_getBottom() 											( RANGE_selfData.limit.bottom  )
#define range_getChar() 											( RANGE_selfData.character )
#define range_isTopLimitRunning()                                   ( __range_isInSetTop() )
#define range_isBottomLimitRunning()                                ( __range_isInSetBottom() )
/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

//== Property setters
#define range_setBottom(lim)										do{ RANGE_selfData.limit.bottom = (lim); 									}while(0)
#define range_setTop(lim)											do{ RANGE_selfData.limit.top = (lim); 										}while(0)
#define range_setCharacter(ch)			                            do{ RANGE_selfData.character = (ch);						               	}while(0)

// Auxiliary
#define range_indicateSelect()										do{ __range_setEventSelect(); 												}while(0)
#define range_indicateReset()										do{ __range_setEventReset(); 												}while(0)

#define range_response

#define range_confirmFound()										do{ __range_setEventDone(); 												}while(0)
#define range_confirmNotFound()										do{ __range_setEventFail(); 												}while(0)


/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
extern void range_init(void);
extern bool range_dispatchEvents(void);
#endif// __RANGE_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* Bottom of File
***********************************************************************************************************************/
