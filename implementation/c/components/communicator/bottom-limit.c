/**********************************************************************************************************************
* C Source File: bottom-limit.c
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

void bottom_limit_init(void)
{
	__bottom_limit_setEventNone();
	__bottom_limit_setStateIdle();
}
bool bottom_limit_dispatchEvents(void)
{
	BOTTOM_LIMIT_Event event;
	BOTTOM_LIMIT_State state;
	event = __bottom_limit_getEvent();	state = __bottom_limit_getState();	__bottom_limit_setEventNone();

//-- detect event -------------------------------------------------------------

	switch(event)
	{
	case __bottom_limit_evDo:
		goto bottom_limit_onDo;
	case __bottom_limit_evSearch:
		goto bottom_limit_onSearch;

	}
return false;
//-- handle events ------------------------------------------------------------
	bottom_limit_onDo:
	{
		switch(state)
		{
			case __bottom_limit_stCompareAverage:
				goto bottom_limit_toDoCompareAverage;
			case __bottom_limit_stMoveUpward:
				goto bottom_limit_toDoMoveUpward;
			case __bottom_limit_stAdjacent:
				goto bottom_limit_toDoAdjacent;
		}
	}
	return true;

	bottom_limit_onSearch:
	{
		switch(state)
		{
			case __bottom_limit_stIdle:
				goto bottom_limit_toSearchIdle;
		}
	}
	return true;

//-- actions -----------------------------------------------------------------------------
//== Make Decision
	bottom_limit_toSearchIdle:
	{
		if( bottom_limit_getBottom() > __bottom_limit_getTop() )
			goto bottom_limit_toCompareAverage;
		goto bottom_limit_toFound;
	}

	bottom_limit_toDoCompareAverage:
	{
		if( BOTTOM_LIMIT_getChar() < __bottom_limit_getAverageChar() )
		{
			bottom_limit_setBottom( __bottom_limit_getAverage() );
			goto bottom_limit_toCompareAverage;
		}
		goto bottom_limit_toMoveUpward;
	}

	bottom_limit_toDoMoveUpward:
	{
		if( __bottom_limit_areInnerLimitsAdjacent() )
		{
			goto bottom_limit_toAdjacent;
		}
		bottom_limit_setTop( __bottom_limit_getAverage() );
		goto bottom_limit_toCompareAverage;
	}

	bottom_limit_toDoAdjacent:
	{
		if( BOTTOM_LIMIT_getChar() == bottom_limit_getBottomChar() )
		{
			goto bottom_limit_toFound;
		}
		if( BOTTOM_LIMIT_getChar() == __bottom_limit_getTopChar() )
		{
			bottom_limit_setBottom( __bottom_limit_getTop() );
			goto bottom_limit_toFound;
		}
		goto bottom_limit_toNotFound;
	}


//== Dispatch State
	bottom_limit_toCompareAverage:
	{
		__bottom_limit_setStateCompareAverage();
		__bottom_limit_setEventDo();
	}
	return true;

	bottom_limit_toMoveUpward:
	{
		__bottom_limit_setStatestMoveUpward();
		__bottom_limit_setEventDo();
	}
	return true;

	bottom_limit_toAdjacent:
	{
		__bottom_limit_setStateAdjacent();
		__bottom_limit_setEventDo();
	}
	return true;

	bottom_limit_toFound:
	{
		__bottom_limit_setStateFound();
		BOTTOM_LIMIT_responseFound();
	}
	return true;

	bottom_limit_toNotFound:
	{
		__bottom_limit_setStateNotFound();
		BOTTOM_LIMIT_responseNotFound();
	}
	return true;
}



/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
