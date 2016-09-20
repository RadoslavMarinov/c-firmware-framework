/***********************************************************************************************************************
 * C Header: receiver-derivative.h
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include guard
 **********************************************************************************************************************/
#ifndef __PHRASE_RECEIVER_DERIVATIVE_INTERFCE__
#define __PHRASE_RECEIVER_DERIVATIVE_INTERFCE__

 /**********************************************************************************************************************
 * Dependency check
 **********************************************************************************************************************/



#ifndef PHRASE_RECEIVER_isSingleTranslationUnit
	#error Missing required PHRASE_RECEIVER_isSingleTranslationUnit()
#endif

#ifndef PHRASE_RECEIVER_selfData
	#error Missing required PHRASE_RECEIVER_selfData
#endif

#ifndef PHRASE_RECEIVER_PhraseSelfData
	#error Missing required PHRASE_RECEIVER_PhraseSelfData
#endif

#ifndef PHRASE_RECEIVER_WordSelfData
	#error Missing required PHRASE_RECEIVER_WordSelfData
#endif

#ifndef PHRASE_RECEIVER_onInvalid
	#error Missing required PHRASE_RECEIVER_onInvalid()
#endif

#ifndef PHRASE_RECEIVER_resetDma
	#error Missing required PHRASE_RECEIVER_resetDma()
#endif

#ifndef PHRASE_RECEIVER_requestRead
	#error Missing required PHRASE_RECEIVER_requestRead()
#endif

#ifndef PHRASE_RECEIVER_requestWrite
	#error Missing required PHRASE_RECEIVER_requestWrite()
#endif

#ifndef PHRASE_RECEIVER_onBufferOverflow
	#error Missing required PHRASE_RECEIVER_onBufferOverflow()
#endif

#ifndef PHRASE_RECEIVER_initPhrase
	#error Missing required PHRASE_RECEIVER_initPhrase()
#endif

#ifndef PHRASE_RECEIVER_getBufferSize
	#error Missing required PHRASE_RECEIVER_getBufferSize()
#endif

/**********************************************************************************************************************
* Include the derivative headers of the INTERNAL (owned) classes
**********************************************************************************************************************/
#include "phrase-derivative.h"
#include "word-derivative.h"


/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private object-like macros   (__xxx)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Private function-like macros that DO return value  (__xxx)
 **********************************************************************************************************************/
#define __phrase_receiver_getState()                               	( PHRASE_RECEIVER_selfData.state )
#define __phrase_receiver_getEvent()                               	( PHRASE_RECEIVER_selfData.event )


#define __phrase_receiver_getBufferChar(element)					( (uint8_t)( phrase_receiver_getBufferElement(element) ) )
#define __phrase_receiver_getNextBufferCharacter()					( __phrase_receiver_getBufferChar( phrase_receiver_getToAnalyzeNext() ))

#define __phrase_receiver_isNewDataAvailable()						( \
																	PHRASE_RECEIVER_getAmountOfReceivedCharacters() > phrase_receiver_getToAnalyzeNext()\
																	? true : false )

 /**********************************************************************************************************************
 * Private function-like macros that DO NOT return value (__xxx)
 **********************************************************************************************************************/
//-- states
#define __phrase_receiver_setStateComplete()                      	do{ __phrase_receiver_setState( __phrase_receiver_stComplete );     		}while(0)
#define __phrase_receiver_setState(st)                      		do{ PHRASE_RECEIVER_selfData.state = (st);                					}while(0)
#define __phrase_receiver_setStateSpace()							do{ __phrase_receiver_setState( __phrase_receiver_stSpace );         		}while(0)
#define __phrase_receiver_setStateName()                            do{ __phrase_receiver_setState( __phrase_receiver_stName );          		}while(0)
#define __phrase_receiver_setStateNameDelimiter()                   do{ __phrase_receiver_setState( __phrase_receiver_stNameDelimiter ); 		}while(0)
#define __phrase_receiver_setStateValue()                           do{ __phrase_receiver_setState( __phrase_receiver_stValue );         		}while(0)
#define __phrase_receiver_setStateValueDelimiter()                  do{ __phrase_receiver_setState( __phrase_receiver_stValueDelimiter ); 		}while(0)

//-- events
#define __phrase_receiver_setEvent(constant)                        do{ PHRASE_RECEIVER_selfData.event = constant;                				}while(0)
#define __phrase_receiver_clearEvent()                             	do{ __phrase_receiver_setEvent( __phrase_receiver_evNone );          		}while(0)
#define __phrase_receiver_setEventBufferOverflow()					do{ __phrase_receiver_setEvent(__phrase_receiver_evBufferOverflow); 		}while(0)
#define __phrase_receiver_setEventInvalidCharacter()				do{ __phrase_receiver_setEvent( __phrase_receiver_evInvalidCharacter );		}while(0)
#define __phrase_receiver_setEventEndOfFrame()						do{ __phrase_receiver_setEvent(__phrase_receiver_evEndOfFrame);  			}while(0)
#define __phrase_receiver_setEventNonSpace()						do{ __phrase_receiver_setEvent(__phrase_receiver_evNonSpace );				}while(0)
#define __phrase_receiver_setEventSpace()							do{ __phrase_receiver_setEvent(__phrase_receiver_evSpace);  				}while(0)
#define __phrase_receiver_setEventReset()							do{ __phrase_receiver_setEvent(__phrase_receiver_evReset);  				}while(0)

//--toAnalyze
#define __phrase_receiver_setToAnalyzeNext(value)					do{ PHRASE_RECEIVER_selfData.toAnalyzeNext = (value); 						}while(0)
#define __phrase_receiver_incrementToAnalyzeNext()					do{ \
																		__phrase_receiver_setToAnalyzeNext( \
																		phrase_receiver_getToAnalyzeNext() + 1 ); \
																	}while(0)
//-- Auxiliary
#define __phrase_receiver_initSelfData()							do{ \
																		__phrase_receiver_setStateSpace();\
																		__phrase_receiver_clearEvent();\
																		__phrase_receiver_setToAnalyzeNext(0);\
																	}while(0)


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
	PHRASE_RECEIVER_State state;
	PHRASE_RECEIVER_Event event;
	uint32_t toAnalyzeNext;
	uint8_t buffer[PHRASE_RECEIVER_getBufferSize()];
//-- Phrase
	PHRASE_RECEIVER_PhraseSelfData phrase;
	PHRASE_RECEIVER_WordSelfData word;
} phrase_receiver_SelfData;

 /**********************************************************************************************************************
 * Public object-like macros  (xxx)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function-like macros that DO return value (xxx)
 **********************************************************************************************************************/
#define phrase_receiver_getBufferElement(element)					( PHRASE_RECEIVER_selfData.buffer[element] )
#define phrase_receiver_getToAnalyzeNext()							( PHRASE_RECEIVER_selfData.toAnalyzeNext )
/**********************************************************************************************************************
 * Public function-like macros that DO NOT return value (xxx)
 **********************************************************************************************************************/
#define phrase_receiver_indicateReset()									do{ __phrase_receiver_setEventReset(); 											}while(0)

/**********************************************************************************************************************
 * Public function declarations(extern)
 **********************************************************************************************************************/
extern void phrase_receiver_init(void);
extern bool phrase_receiver_dispatchEvents(void);

#endif //__PHRASE_RECEIVER_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
