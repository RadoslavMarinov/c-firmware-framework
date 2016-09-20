/**********************************************************************************************************************
* C Source File: transmitter.c
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
* Private function definitions (static)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function definitions.
**********************************************************************************************************************/

void transmitter_init(void)
{
	__transmitter_setEventNone();
	__transmitter_setStateIdle();
	TRANSMITTER_initializeDma();
}

bool transmitter_dispatchEvents(void)
{
	TRANSMITTER_Event event;
	TRANSMITTER_State state;
	event = __transmitter_getEvent(); __transmitter_setEventNone(); state = __transmitter_getState();

//-- detect events
	//-- detect Non-Standard Events
	if( TRANSMITTER_isDmaCh1Done() )
		goto transmitter_onDmaDone;

	//-- detect Standard Events
	switch(event)
	{
		case __transmitter_eventTransmit:
			goto transmitter_onTransmit;
		case __transmitter_eventEntry:
			goto tranmitter_onEntry;
		case __transmitter_eventReset:
			goto transmitter_onReset;
	}
	return false;
//-- Dispatch events ------------------------------------------------------------
	transmitter_onDmaDone:
	{
		TRANSMITTER_clearDmaCh1Done();
		switch(state)
		{
			case __transmitter_stateBusy:
				goto transmitter_exitBusy;
			case __transmitter_stateIdle:
				goto transmitter_toFail;
		}
	}
	return true;

	transmitter_onTransmit:
	{
		switch(state)
		{
			case __transmitter_stateIdle:
				goto transmitter_toBusy;
		}
	}
	return true;

	tranmitter_onEntry:
	{
		switch(state)
		{
			case __transmitter_stateBusy:
				goto transmitter_entryBusy;
		}
	}
	return true;

	transmitter_onReset:
	{
		switch(state)
		{
			case __transmitter_stateFail:
				goto transmitter_toIdle;
		}
	}
	return true;

//-- actions ------------------------------------------------------------------

//== Event-State handler
	transmitter_entryBusy:
	{
		TRANSMITTER_startDma();
	}
	return true;
//==Exit Actions - some exit actions may not be triggered by "Exit" event.
	transmitter_exitBusy:
	{
		TRANSMITTER_stop();
		TRANSMITTER_responseDone();
		goto transmitter_toIdle;
	}
	return true;
//== Transition

//== Departure
	transmitter_toIdle:
	{
		__transmitter_setStateIdle();
	}
	return true;

	transmitter_toBusy:
	{
		__transmitter_setStateBusy();
		__transmitter_setEventEntry();
	}
	return true;

	transmitter_toFail:
	{
		__transmitter_setStateFail();
	}
	return true;
}

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
