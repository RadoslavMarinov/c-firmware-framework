/**********************************************************************************************************************
* C Source File: communicator.c
* Component: Electricity Meter Application
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

void communicator_init(void)
{
	 __communicator_clearEvents();
	 __communicator_setStateWaitReceiver();
}

bool communicator_dispatchEvents(void)
{
	 uint8_t event;
	 uint8_t state;
	 event = __communicator_getEvent(); state = __communicator_getState(); __communicator_clearEvents();
//-- Detect Events -------------------------------------------------------------
	 switch(event)
	 {
	 	 case __communicator_evCommand:
	 		 goto communicator_onCommand;
	 	 case __communicator_evEntry:
	 		 goto communicator_onEntry;
	 	 case __communicator_evDone:
	 		 goto communicator_onDone;
	 }
	 return false;
//-- Dispatch Events ------------------------------------------------------------
	 communicator_onCommand:
	 {
		 switch(state)
		 {
		 	 case __communicator_stWaitReceiver:
		 		 goto communicator_commandWaitReceiver;
		 }
	 }
	 return true;

	 communicator_onEntry:
	 {
		 switch(state)
		 {
		 case __communicator_stRead:
			 goto communicator_entryRead;
		 case __communicator_stWrite:
			 goto communicator_entryWrite;
		 case __communicator_stRequestTransmitter:
			 goto communicator_entryRequestTrnasmitter;
		 }
	 }
	 return true;

	 communicator_onDone:
	 {
		 switch(state)
		 {
		 	 case __communicator_stWrite:		//Electricity Meter response Done
		 	 case __communicator_stRead:		//Electricity Meter response Done
		 		 goto communicator_prepareTransmission;
		 	 case __communicator_stRequestTransmitter:
		 		 goto communicator_doneRequestTransmitter;
		 }
	 }
	 return true;

//-- Actions -------------------------------------------------------------------------------
	 communicator_commandWaitReceiver:
	 {
		 if( COMMUNICATOR_isCommandRead() )
			 goto communicator_toRead;
		 else 	//For readability
			 goto communicator_toWrite;

	 }
	 return true;

	 communicator_entryRead:
	 {
		 COMMUNICATOR_requestElectricityMeterRead(COMMUNICATOR_getWordAddress());
	 }
	 return true;

	 communicator_entryWrite:
	 {
		 COMMUNICATOR_requestElectricityMeterWrite(COMMUNICATOR_getWordAddress(), COMMUNICATOR_getWordValue());
	 }
	 return true;

	 communicator_prepareTransmission:
	 {
		 COMMUNICATOR_preparePhrase();
		 COMMUNICATOR_prepareTransmission();
		 goto communicator_toRequestTransmitter;
	 }
	 return true;

	 communicator_entryRequestTrnasmitter:
	 {
		 COMMUNICATOR_requestTransmitter();
	 }
	 return true;

	 communicator_doneRequestTransmitter:
	 {
		 COMMUNICATOR_requestReceiverReset();
		 goto communicator_toWaitReceiver;
	 }
	 return true;

//== Event-State handler
//== Exit Actions - some exit actions may not be triggered by "Exit" event.
//== Transition
//class_name_[evenName]fromSourceStateNameDestinationStateName:	//if from one state to another there is more than one transition then the event differentiate the identificator.
//== Departure

	 communicator_toRead:
	 {
		 __communicator_setStateRead();
		 __communicator_setEventEntry();
	 }
	 return true;

	 communicator_toWrite:
	 {
		 __communicator_setStateWrite();
		 __communicator_setEventEntry();
	 }
	 return true;

	 communicator_toRequestTransmitter:
	 {
		 __communicator_setStateRequestTransmitter();
		 __communicator_setEventEntry();
	 }
	 return true;

	 communicator_toWaitReceiver:
	 {
		 __communicator_setStateWaitReceiver();
	 }
	 return true;
}

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
