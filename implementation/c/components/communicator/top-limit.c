/**********************************************************************************************************************
* C Source File: top-limit.c
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
void top_limit_init(void)
{
	__top_limit_setEventNone();
	__top_limit_setStateIdle();
}

bool top_limit_dispatchEvents(void)
{
	TOP_LIMIT_Event event;
	TOP_LIMIT_State state;
	event = __top_limit_getEvent(); __top_limit_setEventNone(); state = __top_limit_getState();

//-- detect event -------------------------------------------------------------
	switch (event)
	{
		case __top_limit_evDo:
			goto top_limit_onDo;
		case __top_limit_evSearch:
			goto top_limit_onSearch;
	}
	return false;
//-- handle events ------------------------------------------------------------
//--
	top_limit_onDo:
	{
		switch (state)
		{
			case __top_limit_stCompareAverage:
				goto top_limit_toDoCompareAverage;
			case __top_limit_stSearchDownward:
				goto top_limit_toDoSearchDownward;
			case __top_limit_stSearchUpward:
				goto top_limit_toDoSearchUpward;
			case __top_limit_stCompareBottom:
				goto top_limit_toDoCompareBottom;
		}
	}
	return true;

	top_limit_onSearch:
	{
		switch(state)
		{
			case __top_limit_stIdle:
				goto top_limit_toSearchIdle;
		}
	}
	return true;

//-- actions ------------------------------------------------------------------
//== Decision maker
	top_limit_toSearchIdle:
	{
		if( top_limit_getTop() < __top_limit_getBottom() )
			goto top_limit_toCompareAverage;
		goto top_limit_toRejected;
	}

	top_limit_toDoCompareAverage:
	{
		if( TOP_LIMIT_getChar() > __top_limit_getAverageChar() )
			goto top_limit_toSearchDownward;
		goto top_limit_toSearchUpward;
	}

	top_limit_toDoSearchDownward:
	{
		if( __top_limit_areInnerLimitsAdjacent() )
			goto top_limit_toCompareBottom;
		top_limit_setTop( __top_limit_getAverage() );
		goto top_limit_toCompareAverage;
	}

	top_limit_toDoSearchUpward:
	{
		if( __top_limit_areInnerLimitsAdjacent() )
			goto top_limit_toFound;
		top_limit_setBottom( __top_limit_getAverage() );
		goto top_limit_toCompareAverage;
	}

	top_limit_toDoCompareBottom:
	{
		if( TOP_LIMIT_getChar() == __top_limit_getBottomChar() )
		{
			top_limit_setTop( __top_limit_getBottom() );
			goto top_limit_toFound;
		}
		goto top_limit_toNotFound;
	}

//== Dispatcher
	top_limit_toCompareAverage:
	{
		__top_limit_setStateCompareAverage();
		__top_limit_setEventDo();
	}
	return true;

	top_limit_toRejected:
	{
		__top_limit_setStateRejected();
		TOP_LIMIT_onRejected();
	}
	return true;

	top_limit_toSearchDownward:
	{
		__top_limit_setStateSearchDownward();
		__top_limit_setEventDo();
	}
	return true;

	top_limit_toSearchUpward:
	{
		__top_limit_setStateSearchUpward();
		__top_limit_setEventDo();
	}
	return true;

	top_limit_toCompareBottom:
	{
		__top_limit_setStateCompareBottom();
		__top_limit_setEventDo();
	}
	return true;

	top_limit_toFound:
	{
		__top_limit_setStateFound();
		TOP_LIMIT_responseFound();
	}
	return true;

	top_limit_toNotFound:
	{
		__top_limit_setStateNotFound();
		TOP_LIMIT_responseNotFound();
	}
	return true;

}

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
