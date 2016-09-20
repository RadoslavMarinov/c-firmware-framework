/***********************************************************************************************************************
 * C Header: reader-derivative.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __READER_DERIVATIVE_INTERFCE__
#define __READER_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/

#ifndef READER_getGlossaryTopRow
 	#error Missing required READER_getGlossaryTopRow
 #endif
 #ifndef READER_getGlossaryBottomRow
 	#error Missing required READER_getGlossaryBottomRow()
 #endif
// #ifndef
// 	#error Missing required
// #endif
// #ifndef
// 	#error Missing required
// #endif

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/
#define __reader_getEvent()											( READER_selfData.event )
#define __reader_getState()											( READER_selfData.state )

#define __reader_getColumn()										( READER_selfData.column )

#define __reader_getInputChar()										( READER_getInputChar( __reader_getColumn() ) )
#define __reader_getGlossaryChar(row)								( READER_getGlossaryChar( row, __reader_getColumn()) )

// Auxiliaries
#define __reader_hasNameChar()										( reader_getColumn() < READER_getNameSize()  ?  true : false )
#define __reader_isEndOfName()										( reader_getColumn() == READER_getNameSize() ? true : false )

#define __reader_isInSearchState()									( __reader_getState() == __reader_stSearch ? true : false  )



#define __reader_isInputEndCharReached()							( ( __reader_getInputWorkingColumn() >= READER_getInputEndColumn()) ? true : false )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
#define __reader_setEvent(ev)										do{ READER_selfData.event = (ev); 											}while(0)
#define __reader_setState(st)                                      	do{ READER_selfData.state = (st); 											}while(0)
//== Event Setters
#define __reader_clearEvents()                                     	do{ __reader_setEventNone(); 												}while(0)
#define __reader_setEventNone()                                     do{ __reader_setEvent( __reader_evNone ); 									}while(0)
#define __reader_setEventDo() 	                                    do{ __reader_setEvent( __reader_evDo ); 									}while(0)
#define __reader_setEventEntry() 									do{ __reader_setEvent( __reader_evEntry ); 									}while(0)
#define __reader_setEventSearch() 									do{ __reader_setEvent( __reader_evSearch ); 					 			}while(0)
#define __reader_setEventCharNotFound()								do{ __reader_setEvent( __reader_evCharNotFound );				 			}while(0)
#define __reader_setEventCharFound()								do{ __reader_setEvent( __reader_evCharFound );				 				}while(0)
#define __reader_setEventRangeReady()								do{ __reader_setEvent( __reader_evRangeReady );				 				}while(0)

//== State Setters
#define __reader_setStateCheckNameStatus()                         	do{ __reader_setState( __reader_stCheckNameStatus);                     	}while(0)
#define __reader_setStateFound()                         			do{ __reader_setState( __reader_stFound );                        			}while(0)
#define __reader_setStateIdle()                      			  	do{ __reader_setState( __reader_stIdle );           		             	}while(0)
#define __reader_setStateNotFound()      		                  	do{ __reader_setState( __reader_stNotFound );                        		}while(0)
#define __reader_setStateSearch() 		        	              	do{ __reader_setState( __reader_stSearch );                        			}while(0)
#define __reader_setStateResetRange() 		        	          	do{ __reader_setState( __reader_stResetRange );                        		}while(0)

//--
#define __reader_setColumn(value)									do{ READER_selfData.column = (value); 										}while(0)
#define __reader_initializeColumn()									do{ __reader_setColumn( 0 ); 												}while(0)
//--
#define __reader_initializeRangeTop()                        		do{ READER_initializeRangeLimits()( READER_getGlossaryTopRow() );					}while(0)
#define __reader_initializeRangeBottom()                        	do{ __reader_setInnerEnd( READER_getGlossaryBottomRow() );					}while(0)
//--
#define __reader_incrementColumn()									do{ __reader_setColumn(	__reader_getColumn() + 1 ); 						}while(0)
#define __reader_setStRowBoundarySearch()							do{ __reader_setState( __reader_stRowBoundarySearch ); 						}while(0)

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
	READER_Event event;
	READER_State state;
	READER_ColumnIndex column;
}reader_SelfData;


/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/
#define reader_getColumn() 											( __reader_getColumn() )

// Auxiliaries
#define reader_isRangeRunning() 									( 1 )

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

// Server methods
#define reader_indicateSearch()										do{ __reader_setEventSearch(); 												}while(0)
//
#define reader_confirmCharFound()									do{ __reader_setEventCharFound(); 											}while(0)
#define reader_confirmCharNotFound()								do{ __reader_setEventCharNotFound(); 										}while(0)
#define reader_confirmRangeReady()									do{ __reader_setEventRangeReady(); }while(0)

// Client methods

#define reader_responseNotFound()





/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
extern void reader_init(void);
extern bool reader_dispatchEvents(void);
#endif //__READER_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
