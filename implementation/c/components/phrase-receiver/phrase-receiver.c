/**********************************************************************************************************************
 * C Source File: phrase_receiver.c
 * Component: Communicator
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Include application header
 **********************************************************************************************************************/
 #include "application.h"

/**********************************************************************************************************************
* Conditionally include internal (owned) source files
**********************************************************************************************************************/
#if PHRASE_RECEIVER_isSingleTranslationUnit()
	#include "phrase.c"
	#include "word.c"
#endif


 /**********************************************************************************************************************
 * Private function definitions (static)
 **********************************************************************************************************************/

 /**********************************************************************************************************************
 * Public function definitions.
 **********************************************************************************************************************/
//-- init
void phrase_receiver_init(void)
{
	__phrase_receiver_initSelfData();
	PHRASE_RECEIVER_initDma();
	PHRASE_RECEIVER_initPhrase();
	PHRASE_RECEIVER_startDma();
}
//-- dispatch events

bool phrase_receiver_dispatchEvents(void)
{
	uint8_t c;
	PHRASE_RECEIVER_State state;
	PHRASE_RECEIVER_Event event;
//--
	state = __phrase_receiver_getState(); event = __phrase_receiver_getEvent(); __phrase_receiver_clearEvent();

	if( PHRASE_RECEIVER_isBufferOverflown() )
	{
		goto phrase_receiver_onBufferOverflow;
	}

	if( __phrase_receiver_isNewDataAvailable() )
	{
		c = __phrase_receiver_getNextBufferCharacter();
		__phrase_receiver_incrementToAnalyzeNext();
		switch( c )
		{
			case 8:							//backspace
			case 13:						//carriage return (enter key)
			case 32:						//space
				goto phrase_receiver_onSpace;
			case 10:						//new line, line feed
				goto phrase_receiver_onEndOfFrame;
		}
		if( (c > ',') && (c < ':') )		 // '-./0123456789'
		{
			goto phrase_receiver_onNonSpace;
		}
		if( (c > '`') && (c < '{') )		// 'a-z'
		{
			goto phrase_receiver_onNonSpace;
		}
		goto phrase_receiver_toInvalid;
	}

//-- detect event -------------------------------------------------------------
	switch( event )
	{
		case __phrase_receiver_evReset:
			goto phrase_receiver_onReset;
	}
	return false;

//-- handle events ------------------------------------------------------------
	phrase_receiver_onReset:
	{
		switch( state )
		{
			case __phrase_receiver_stComplete:
				goto phrase_receiver_toSpace;
		}
	}
	return true;
//--
	phrase_receiver_onNonSpace:
	{
		switch( state )
		{
			case __phrase_receiver_stSpace:
				goto phrase_receiver_toName;
			case __phrase_receiver_stNameDelimiter:
				goto phrase_receiver_toValue;
			case __phrase_receiver_stValueDelimiter:
				goto phrase_receiver_toInvalid;
		}
	}
	return true;
//--
	phrase_receiver_onSpace:
	{
		switch( state )
		{
			case __phrase_receiver_stName:
				goto phrase_receiver_toNameDelimiter;
			case __phrase_receiver_stValue:
				goto phrase_receiver_toValueDelimiter;
		}
	}
	return true;
//--
	phrase_receiver_onEndOfFrame:
	{
		switch( state )
		{
			case __phrase_receiver_stName:
			case __phrase_receiver_stNameDelimiter:
				goto phrase_receiver_toRead;
			case __phrase_receiver_stValue:
			case __phrase_receiver_stValueDelimiter:
				goto phrase_receiver_toWrite;
		}
	}
	return true;
//--
	phrase_receiver_onBufferOverflow:
	{
		switch(state)
		{
			case __phrase_receiver_stSpace:
			case __phrase_receiver_stName:
			case __phrase_receiver_stNameDelimiter:
			case __phrase_receiver_stValue:
			case __phrase_receiver_stValueDelimiter:
				goto phrase_receiver_toBufferOverflow;
		}
	}
	return true;
//-- actions -----------------------------------------------------------------------------

//--
	phrase_receiver_toSpace:
	{
		__phrase_receiver_setToAnalyzeNext(0);
		PHRASE_RECEIVER_resetDma();
		__phrase_receiver_setStateSpace();
	}
	return true;
//--
	phrase_receiver_toInvalid:
	{
		PHRASE_RECEIVER_onInvalid();
		__phrase_receiver_setStateComplete();
	}
	return true;
//--
	phrase_receiver_toName:
	{
		PHRASE_RECEIVER_setWordNameStart();
		__phrase_receiver_setStateName();
	}
	return true;
//--
	phrase_receiver_toNameDelimiter:
	{
		PHRASE_RECEIVER_setWordNameEnd();
		__phrase_receiver_setStateNameDelimiter();
	}
	return true;
//--
	phrase_receiver_toValue:
	{
		PHRASE_RECEIVER_setWordValueStart();
		__phrase_receiver_setStateValue();
	}
	return true;
//--
	phrase_receiver_toValueDelimiter:
	{
		PHRASE_RECEIVER_setWordValueEnd();
		__phrase_receiver_setStateValueDelimiter();
	}
	return true;
//--
	phrase_receiver_toRead:
	{

		PHRASE_RECEIVER_setPhraseCommandRead();
		PHRASE_RECEIVER_stopDma();
		__phrase_receiver_setStateComplete();
		PHRASE_RECEIVER_requestRead();
	}
	return true;
//--
	phrase_receiver_toWrite:
	{

		PHRASE_RECEIVER_setPhraseCommandWrite();
		PHRASE_RECEIVER_stopDma();
		__phrase_receiver_setStateComplete();
		PHRASE_RECEIVER_requestWrite();
	}
	return true;
//--
	phrase_receiver_toBufferOverflow:
	{
		PHRASE_RECEIVER_onBufferOverflow();	// Not implemented yet
		__phrase_receiver_setStateComplete();
	}
	return true;
}
/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
