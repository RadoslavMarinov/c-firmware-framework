/**********************************************************************************************************************
* C Source File: electricity-meter.c
* Component: Electricity Meter
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include application header
**********************************************************************************************************************/
#include "application.h"

/**********************************************************************************************************************
* Conditionally include internal (owned) source files
**********************************************************************************************************************/
#if ELECTRICITY_METER_M90E32AS_isSingleTranslationUnit
	#include "frame.c"
#endif

/**********************************************************************************************************************
* Private function definitions (static)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function definitions.
**********************************************************************************************************************/
 void electricity_meter_m90e32as_init(void)
{
	 ELECTRICITY_METER_M90E32AS_frameWrite(0,0);	//clear frame  output buffer
	 __electricity_meter_m90e32as_setStateIdle();
	 __electricity_meter_m90e32as_clearEvents();

#ifdef MY_DEBUG
	 __electricity_meter_m90e32as_setRegisterElement(2, 0x1A2B);
#endif
}

bool electricity_meter_m90e32as_dispatchEvents(void)
{
	 ELECTRICITY_METER_M90E32AS_Event event;
	 ELECTRICITY_METER_M90E32AS_State state;
	 event = __electricity_meter_m90e32as_getEvent(); state = __electricity_meter_m90e32as_getState(); __electricity_meter_m90e32as_clearEvents();
//-- Detect Events -------------------------------------------------------------
	 switch(event)
	 {
	 	 case __electricity_meter_m90e32as_evRead:
	 		 goto electricity_meter_m90e32as_onRead;
	 	 case __electricity_meter_m90e32as_evWrite:
	 		goto electricity_meter_m90e32as_onWrite;
	 	 case __electricity_meter_m90e32as_evEntry:
	 		 goto electricity_meter_m90e32as_onEntry;
	 	 case __electricity_meter_m90e32as_evDone:
	 		 goto electricity_meter_m90e32as_onDone;
	 }
	 return false;
//-- Dispatch Events ------------------------------------------------------------

	 electricity_meter_m90e32as_onDone:
	 {
		 switch(state)
		 {
		 case __electricity_meter_m90e32as_stRead:
			 goto electricity_meter_m90e32as_doneRead;
		 case __electricity_meter_m90e32as_stWrite:
			 goto electricity_meter_m90e32as_doneWrite;
		 default:
			 goto electricity_meter_m90e32as_toFail;
		 }
	 }return true;

	 electricity_meter_m90e32as_onRead:
	 {
		 switch(state)
		 {
		 	 case __electricity_meter_m90e32as_stIdle:
		 		 goto electricity_meter_m90e32as_toRead;
		 	 default:
		 	 	 goto electricity_meter_m90e32as_toFail;
		 }
	 }return true;

	 electricity_meter_m90e32as_onWrite:
	 {
		 switch(state)
		 {
		 	 case __electricity_meter_m90e32as_stIdle:
		 		goto electricity_meter_m90e32as_toWrite;
		 	 default:
		 		goto electricity_meter_m90e32as_toFail;
		 }
	 }return true;

	 electricity_meter_m90e32as_onEntry:
	 {
		 switch(state)
		 {
		 	 case __electricity_meter_m90e32as_stRead:
		 		 goto electricity_meter_m90e32as_entryRead;
		 	 case __electricity_meter_m90e32as_stWrite:
		 		 goto electricity_meter_m90e32as_entryWrite;
		 	 default:
		 		 goto electricity_meter_m90e32as_toFail;
		 }
	 }return true;


//-- Actions --------------------------------------------------------------------
	 electricity_meter_m90e32as_entryRead:
	 {
		 ELECTRICITY_METER_M90E32AS_requestSpiExchangerRead();
	 }return true;

	 electricity_meter_m90e32as_entryWrite:
	 {
		 ELECTRICITY_METER_M90E32AS_requestSpiExchangerWrite();
	 }return true;

	 electricity_meter_m90e32as_doneRead:
	 {
		 __electricity_meter_m90e32as_setStateIdle();
		 ELECTRICITY_METER_M90E32AS_responseDoneRead();
	 }return true;

	 electricity_meter_m90e32as_doneWrite:
	 {
		 __electricity_meter_m90e32as_setStateIdle();
		 ELECTRICITY_METER_M90E32AS_responseDoneWrite();
	 }return true;

//== Event-State handler
//== Exit Actions - some exit actions may not be triggered by "Exit" event.
//== Transition

//== Departure --------------------------------------------------------------------

	 electricity_meter_m90e32as_toRead:
	 {
		 __electricity_meter_m90e32as_setEventEntry();
		 __electricity_meter_m90e32as_setStateRead();
	 }
	 return true;

	 electricity_meter_m90e32as_toWrite:
	 {
		 __electricity_meter_m90e32as_setEventEntry();
		 __electricity_meter_m90e32as_setStateWrite();
	 }
	 return true;

	 electricity_meter_m90e32as_toFail:
	 {
		 __electricity_meter_m90e32as_setStateFail();
	 }return true;
}
//
//
/**********************************************************************************************************************
* Public data objects non-extern declaration
**********************************************************************************************************************/

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/

