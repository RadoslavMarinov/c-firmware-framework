/**********************************************************************************************************************
* C Source File: range.c
* Component: Communicator
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include application header
**********************************************************************************************************************/
#include "application.h"


/**********************************************************************************************************************
* Private function definitions (static)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function definitions.
**********************************************************************************************************************/

void range_init(void)
{
	__range_setEventNone();
	__range_setStateIdle();
}

bool range_dispatchEvents(void)
{
	RANGE_Event event;
	RANGE_State state;

	state = __range_getState(); event = __range_getEvent(); __range_setEventNone();

	//-- detect event -------------------------------------------------------------

	switch(event)
	{
		case __range_evDo:
			goto range_onDo;
		case __range_evSelect:
			goto range_onSelect;
		case __range_evEntry:
			goto range_onEntry;
		case __range_evFail:
			goto range_onFail;
		case __range_evDone:
			goto range_onDone;
		case __range_evReset:
			goto range_onReset;
	}
	return false;

//-- handle events ------------------------------------------------------------

	range_onSelect:
	{
		switch(state)
		{
			case __range_stIdle:
				goto range_SelectIdle;
		}
	}
	return true;

	range_onEntry:
	{
		switch(state)
		{
			case __range_stSetTop:
				goto range_EntrySetTop;
			case __range_stSetBottom:
				goto range_EntrySetBottom;
		}
	}
	return true;

	range_onFail:
	{
		switch(state)
		{
			case __range_stSetTop:
				goto range_toNotFound;
			case __range_stSetBottom:
				goto range_toNotFound;
		}
	}
	return true;

	range_onDone:
	{
		switch(state)
		{
			case __range_stSetTop:
				goto range_fromSetTop2SetBottom;
			case __range_stSetBottom:
				goto range_fromSetBottom2Selected;
		}
	}
	return true;

	range_onReset:
	{
		switch(state)
		{
			case __range_stSelected:
				goto range_toIdle;
		}
	}
	return true;

	range_onDo:
	{
		switch(state)
		{
			case __range_stCompareCharacters:
				goto reader_doCompareCharacters;
		}
	}
	return true;
//-- actions -----------------------------------------------------------------------------

//== Event-State handler
	range_SelectIdle:
	{
		if( __range_isCharOutOfRnage( range_getChar() ) )
			goto range_toNotFound;
		if ( __range_doLimitsMatch() )
			goto range_toCompareCharacters;
		goto range_toSetTop;
	}

	range_EntrySetTop:
	{
		RANGE_requestTopLimit();
	}
	return true;

	range_EntrySetBottom:
	{
		RANGE_requestBottomLimit();
	}
	return true;

	reader_doCompareCharacters:
	{
		if( __range_doCharactersMatch() )
			goto range_toSelected;
		goto range_toNotFound;
	}

//== Transition
	range_fromSetTop2SetBottom:
	{
		range_setTop( RANGE_getTop() );
		goto range_toSetBottom;
	}

	range_fromSetBottom2Selected:
	{
		range_setBottom( RANGE_getBottom() );
		goto range_toSelected;
	}

//== Departure
	range_toNotFound:
	{
		__range_setStateNotFound();
		RANGE_responseNotFound();
	}
	return true;

	range_toSetTop:
	{
		__range_setStateSetTop();
		__range_setEventEntry();
	}
	return true;

	range_toSetBottom:
	{
		__range_setStateSetBottom();
		__range_setEventEntry();
	}
	return true;

	range_toSelected:
	{
		__range_setStateSelected();
		RANGE_responseFound();
	}
	return true;

	range_toIdle:
	{
		__range_setStateIdle();
		RANGE_responseReady();
	}
	return true;

	range_toCompareCharacters:
	{
		__range_setStateCompareCharacters();
		__range_setEventDo();
	}
	return true;
}


/**********************************************************************************************************************
* Bottom of File
***********************************************************************************************************************/
