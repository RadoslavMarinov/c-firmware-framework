
/**********************************************************************************************************************
* C Source File: spi-exchanger.c
* Component: Spi Exchanger
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
#if SPI_EXCHANGER_isSingleTranslationUnit()
	//#include "xxx-yyy.c"
#endif

/**********************************************************************************************************************
* Private function definitions (static)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function definitions.
**********************************************************************************************************************/
void spi_exchanger_init(void)
{
	SPI_EXCHANGER_initSpi();
	SPI_EXCHANGER_initDMA();
	__spi_exchanger_clearEvents();
	__spi_exchanger_setStateIdle();
}

bool spi_exchanger_dispatchEvents(void)
{
	SPI_EXCHANGER_Event event;
	SPI_EXCHANGER_State state;

	event = __spi_exchanger_getEvent(); state = __spi_exchanger_getState(); __spi_exchanger_clearEvents();
//-- Detect Events -------------------------------------------------------------
	switch(event)
	{
		case  __spi_exchanger_evEntry:
			goto spi_exchanger_onEntry;
		case __spi_exchanger_evRead:
		case __spi_exchanger_evWrite:
			goto spi_exchanger_onWrite;
	}

	if( SPI_EXCHANGER_isDmaReadChannelDone() )
	{
		SPI_EXCHANGER_clearDmaWriteChannelDone();
		SPI_EXCHANGER_clearDmaReadChannelDone();
		goto spi_exchanger_onReadDone;
	}
	return false;
//-- Dispatch Events ------------------------------------------------------------
	spi_exchanger_onEntry:
	{
		switch(state)
		{
			case __spi_exchanger_stBusy:
				goto spi_exchanger_entryBusy;
			default:
				goto spi_exchanger_toFail;
		}
	}return true;

	spi_exchanger_onReadDone:
	{
		switch(state)
		{
			case __spi_exchanger_stBusy:
				goto spi_exchanger_toIdle;
			default:
				goto spi_exchanger_toFail;
		}
	}return true;

	spi_exchanger_onWrite:
	{
		switch(state)
		{
			case __spi_exchanger_stIdle:
				goto spi_exchanger_toBusy;
			default:
				goto spi_exchanger_toFail; //Event Write is acceptable only in state Idle, thus prevent bypassing of Channel_done flags
		}
	}return true;

//-- Actions --------------------------------------------------------------------
//== Event-State handler

	spi_exchanger_entryBusy:
	{
		SPI_EXCHANGER_recycleTxTransfer();
		SPI_EXCHANGER_recycleRxTransfer();
	}return true;

//== Exit Actions - some exit actions may not be triggered by "Exit" event.
//== Transition
//class_name_[evenName]fromSourceStateNameDestinationStateName:	//if from one state to another there is more than one transition then the event differentiate the identificator.
//== Departure

	spi_exchanger_toIdle:
	{
		SPI_EXCHANGER_responseDone();
		__spi_exchanger_setStateIdle();
	}return true;

	spi_exchanger_toBusy:
	{
		__spi_exchanger_setEventEntry();
		__spi_exchanger_setStateBusy();
	}return true;

	spi_exchanger_toFail:
	{
		__spi_exchanger_setStateFail();
	}return true;
}

/**********************************************************************************************************************
* Public data objects non-extern declaration
**********************************************************************************************************************/

/**********************************************************************************************************************
* End of File
***********************************************************************************************************************/

