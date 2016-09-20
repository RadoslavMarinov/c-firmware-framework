/**********************************************************************************************************************
* C Source File: electricity-meter-application.c
* Application: Electricity Meter Application
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* � 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

#include "application.h"

//Conditional inclusion of all INTERNAL and EXTERNAL source files
#if ( electricity_meter_controller_happy_gecko_application_isSingleCompilationUnit() != 0 )
	#include "components/efm32/happy-gecko/cmu/cmu.c"
	#include "components/efm32/happy-gecko/gpio/gpio.c"
//	#include "components/efm32/usart/usart.c"
#endif

/**********************************************************************************************************************
* Class: Electricity Meter Application
**********************************************************************************************************************/

//Private types

//Private function definitions (static)

//Public function definitions

void electricity_meter_controller_happy_gecko_application_init(void)
{
	cmu_disableHighFrequencyPeripheralClock();
	cmu_enableHighFrequencyPeripheralClock();
	cmu_enableGpioHighFrequencyPeripheralClock();
	port_setPortAModeDisabledPin(5);
//	ELECTRICITY_METER_CONTROLLER_HAPPY_GECKO_APPLICATION_cmuInit();
//	ELECTRICITY_METER_CONTROLLER_HAPPY_GECKO_APPLICATION_gpioInit();
}

bool electricity_meter_application_isFinished(void)
{
//electricity_meter_application_dispatchEvents:

//-- Detect Events -------------------------------------------------------------

//-- Dispatch Events ------------------------------------------------------------

//-- Actions --------------------------------------------------------------------
//== Event-State handler
//        class_name_EventNameStateName
//== Exit Actions - some exit actions may not be triggered by "Exit" event.
//== Transition
//        class_name_[evenName]fromSourceStateNameDestinationStateName:	//if from one state to another there is more than one transition then the event differentiate the identificator.
//== Departure
// /        class_name_toStateName
	return false;
}

void electricity_meter_controller_happy_gecko_application_execute(void)
{
	while(1)
	{
//		if( ELECTRICITY_METER_APPLICATION_isRangeRunning() && ELECTRICITY_METER_APPLICATION_dispatchRangeEvents() )
//			continue;
//		if( ELECTRICITY_METER_APPLICATION_isTopLimitRunning() && ELECTRICITY_METER_APPLICATION_dispatchTopLimitEvents() )
//			continue;
//		if( ELECTRICITY_METER_APPLICATION_isBottomLimitRunning() && ELECTRICITY_METER_APPLICATION_dispatchBottomLimitEvents() )
//			continue;

        if( electricity_meter_application_isFinished() )
		{
		    break;
		}
	}
}

//Application data objects (instances)
//electricity_meter_application_SelfData electricity_meter_application_selfData;

/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
