/**********************************************************************************************************************
 * C Source File: electricity-meter-application.c
 * Application: Electricity Meter Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

//Include class header file

#include "application.h"

// DEBUG LINE
#include <string.h>

//Conditional inclusion of all INTERNAL and EXTERNAL source files
#if ( ELECTRICITY_METER_APPLICATION_isSingleTranslationUnit() != 0 )
//	#include "components/electricity-meter-m90e32as/electricity-meter-m90e32as.c"
//	#include "components/communicator/communicator.c"
//	#include "components/spi-exchanger/spi-exchanger.c"
	#include "components/phrase-receiver/phrase-receiver.c"
//	#include "components/transmitter/transmitter.c"
#endif

/**********************************************************************************************************************
 * Class: Electricity Meter Application
 **********************************************************************************************************************/

//Private types

//Private function definitions (static)

//Public function definitions


void electricity_meter_application_init(void)
{
	ELECTRICITY_METER_APPLICATION_cmuInit();
	ELECTRICITY_METER_APPLICATION_gpioInit();
	ELECTRICITY_METER_APPLICATION_usartInit();
//	ELECTRICITY_METER_APPLICATION_receiverInit();
//	ELECTRICITY_METER_APPLICATION_transmitterInit();
//	ELECTRICITY_METER_APPLICATION_communicatorInit();
//	ELECTRICITY_METER_APPLICATION_initElectricityMeterM90E32AS();
//	ELECTRICITY_METER_APPLICATION_initSpiExchanger();
	__electricity_meter_application_clearEvents();
}
// DEBUG SECTION END


bool electricity_meter_application_isFinished(void)
{
	ELECTRICITY_METER_APPLICATION_Event event;
	event = __electricity_meter_application_getEvent(); __electricity_meter_application_clearEvents();

//-- Detect Events -------------------------------------------------------------
	switch(event)
	{
		case __electricity_meter_application_evDone:
			goto electricity_meter_application_onDone;
	}
	return false;
//-- Dispatch Events ------------------------------------------------------------
	electricity_meter_application_onDone:
	{
		return true;
	}
//-- Actions --------------------------------------------------------------------
//== Event-State handler
//       class_name_EventNameStateName
//== Exit Actions - some exit actions may not be triggered by "Exit" event.
//== Transition
//        class_name_[evenName]fromSourceStateNameDestinationStateName:	//if from one state to another there is more than one transition then the event differentiate the identificator.
//== Departure
//        class_name_toStateName
}

void electricity_meter_application_execute(void)
{
//	frame_write(0xDA, 0xDDAA);

//	SPI_EXCHANGER_startDmaRxChannel();
//	uint32_t a[4];

//	usart_loadUsart1TxData(0x04);
//	uint16_t a = frame_getValue();
//	dma_sfr.channelEnableSet = (1<<2);
	while(1)
	{
// 		if( ELECTRICITY_METER_APPLICATION_receiverDispatchEvents() )
//			continue;
//
//		if( ELECTRICITY_METER_APPLICATION_dispatchCommunicatorEvents() )
//			continue;
//
//		if( ELECTRICITY_METER_APPLICATION_dispatchElectricityMeterM90e32asEvents() )
//			continue;
//
//		if( ELECTRICITY_METER_APPLICATION_dispatchSpiExchangerEvents() )
//			continue;
//
//  		if( ELECTRICITY_METER_APPLICATION_transmitterDispatchEvents() )
//			continue;

  				usart_loadUsart1TxData(0xAA);
  		//		frame_setWriteValue(0xABCD);


//		if( timer_isOverflowFlagRaised(timer_timer0) )
//		{
//			timer_clearOverflowInterruptFlag(timer_timer0);
//			//transmitter_startTransfer( 9, 12 );
//			gpio_toggleE2();
//			if( dma_isChannel0Done() )
//			{
//				for(i = 0; i < 20; i++ )
//				{
//					while( !(usart_isTxBufferEmpty(usart_uart1)) );
//					usart_loadTxData(usart_uart1, COMMUNICATOR_selfData.buffer[i]);
//				}
//				dma_clearChannel0DoneInterruptFlag();
//			}
//		}

//        if( electricity_meter_application_isFinished() )
//		{
//		    break;
//		}
	}
}

//Application data objects (instances)
electricity_meter_application_SelfData electricity_meter_application_selfData;

/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

