/**********************************************************************************************************************
* C Source File: reader.c
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
 void reader_init(void)
{
	 __reader_setEventNone();
	 __reader_setStateIdle();
	 __reader_initializeColumn();
	 READER_initializeRange();
	 READER_initializeRangeLimits();	//Sets up Range character and range limits for search;
}


bool reader_dispatchEvents(void)
{
	 READER_Event event;
	 READER_State state;
	 event = __reader_getEvent(); state = __reader_getState(); __reader_clearEvents();
//-- detect event -------------------------------------------------------------
	 switch(event)
	 {
	 	 case __reader_evDo:
	 		 goto reader_onDo;
	 	 case __reader_evSearch:
	 		 goto reader_onSearch;
	 	 case __reader_evEntry:
	 		 goto reader_onEntry;
	 	 case __reader_evCharFound:
	 	 	 goto reader_onCharFound;
	 	 case __reader_evCharNotFound:
	 		 goto reader_onNotFound;
	 	 case __reader_evRangeReady:
	 		 goto reader_onRangeReady;

	 }
	 return false;
//-- handle events ------------------------------------------------------------
	 reader_onSearch:
	 {
		 switch(state)
		 {
		 	 case __reader_stIdle:
		 		 goto reader_fromIdle2Search;
		 }
	 }
	 return true;

	 reader_onEntry:
	 {
		 switch(state)
		 {
		 	 case __reader_stSearch:
		 		 goto reader_EntrySearch;
		 	 case __reader_stFound:
		 		 goto reader_entryFound;
		 	 case __reader_stNotFound:
		 		goto reader_entryNotFound;
		 	 case __reader_stResetRange:
		 		 goto reader_entryResetRange;
		 }
	 }
	 return true;

	 reader_onCharFound:
	 {
		 switch(state)
		 {
		 	 case __reader_stSearch:
		 		 goto reader_fromSearch2CheckNameStatus;
		 }
	 }
	 return true;

	 reader_onDo:
	 {
		 switch(state)
		 {
		 	 case __reader_stCheckNameStatus:
		 		 goto reader_doCheckNameStatus;
		 }
	 }
	 return true;

	 reader_onNotFound:
	 {
		 switch(state)
		 {
		 	 case __reader_stSearch:
		 		 goto reader_toNotFound;
		 }
	 }
	 return true;

	 reader_onRangeReady:
	 {
		 switch(state)
		 {
		 	 case __reader_stResetRange:
		 		 goto reader_toSearch;
		 }
	 }
	 return true;

//-- actions -----------------------------------------------------------------------------

//== Event-State handler
	 reader_EntrySearch:
	 {
		 READER_RequestRangeSearch();
	 }
	 return true;

	 reader_doCheckNameStatus:
	 {
		 if( __reader_hasNameChar() )
			 goto reader_fromCheckNameStatus2ResetRange;
		 if( __reader_isEndOfName() )
			 goto reader_fromCheckNameStatus2ResetRangeOnEndOfName;
		 goto reader_toFound;
	 }

	 reader_entryResetRange:
	 {
		 READER_requestRangeReset();
	 }
	 return true;

	 reader_entryFound:
	 {
		 READER_responseFound();
	 }
	 return true;

	 reader_entryNotFound:
	 {
		 reader_responseNotFound();
	 }
	 return true;

//== Transition

	 reader_fromIdle2Search:
	 {
		 READER_setRangeChar( READER_getInputChar() );
		 goto reader_toSearch;
	 }

	 reader_fromSearch2CheckNameStatus:
	 {
		 __reader_incrementColumn();
		 goto reader_toCheckNameStatus;
	 }

	 reader_fromCheckNameStatus2ResetRange:
	 {
		 READER_setRangeChar( READER_getInputChar() );
		 goto reader_toResetRange;
	 }
	 reader_fromCheckNameStatus2ResetRangeOnEndOfName:
	 {
		 READER_setRangeChar( '\0' );
		 goto reader_toResetRange;
	 }

//== Departure
	 reader_toSearch:
	 {
		 __reader_setStateSearch();
		 __reader_setEventEntry();
	 }
	 return true;

	 reader_toCheckNameStatus:
	 {
		 __reader_setStateCheckNameStatus();
		 __reader_setEventDo();
	 }
	 return true;

	 reader_toResetRange:
	 {
		 __reader_setStateResetRange();
		 __reader_setEventEntry();
	 }
	 return true;

	 reader_toFound:
	 {
		 __reader_setStateFound();
		 __reader_setEventEntry();
	 }
	 return true;

	 reader_toNotFound:
	 {
		 __reader_setStateNotFound();
		 __reader_setEventEntry();

	 }
	 return true;
}

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/
