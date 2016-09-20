/**********************************************************************************************************************
 * C Header: electricity-meter-application.h
 * Application Class: Electricity Meter Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

#ifndef __ELECTRICITY_METER_APPLICATION_DERIVATIVE_INTERFACE__
#define __ELECTRICITY_METER_APPLICATION_DERIVATIVE_INTERFACE__

/**********************************************************************************************************************
 * Class: Electricity Meter Application
 **********************************************************************************************************************/

/**********************************************************************************************************************
* Dependency check
***********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros
***********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value

***********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public typedefs
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public object-like macros
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros
***********************************************************************************************************************/



/**********************************************************************************************************************
* Public function-like macros
***********************************************************************************************************************/

/**********************************************************************************************************************
* Include header files of all INTERNAL, and utilized EXTERNAL classes
***********************************************************************************************************************/

#include "components/efm32/happy-gecko/cmu/cmu-derivative.h"
#include "components/efm32/happy-gecko/gpio/gpio-derivative.h"
//#include "components/efm32/usart/usart-derivative.h"
//#include "components/efm32/timer/timer-derivative.h"
//#include "components/efm32/dma/dma-derivative.h"
//#include "components/communicator/communicator-derivative.h"

/**********************************************************************************************************************
* Public typedefs
***********************************************************************************************************************/

//
typedef struct
{
//	ELECTRICITY_METER_APPLICATION_DmaSelfData dma;
//	ELECTRICITY_METER_APPLICATION_CommunicatorSelfData communicator;
//	ELECTRICITY_METER_APPLICATION_ElectricityMeterRegister electricity_meter_register;
//	ELECTRICITY_METER_APPLICATION_ElectricityMeterSelfData electricity_meter;
///	ELECTRICITY_METER_APPLICATION_CallerSelfData caller;
///	ELECTRICITY_METER_APPLICATION_BitsSelfData	bits;
///	ELECTRICITY_METER_APPLICATION_ElectricityMeterSelfData electricityMeter;
} electricity_meter_happy_gecko_application_SelfData;

/**********************************************************************************************************************
* Public function declarations(extern)
***********************************************************************************************************************/
//extern void electricity_meter_application_init(void);
//extern bool electricity_meter_application_isFinished(void);
//extern void electricity_meter_application_execute(void);

/**********************************************************************************************************************
* Component's data object declarations
***********************************************************************************************************************/
extern electricity_meter_happy_gecko_application_SelfData electricity_meter_application_happy_gecko_selfData;

/**********************************************************************************************************************
*
***********************************************************************************************************************/

#endif //__ELECTRICITY_METER_APPLICATION_DERIVATIVE_INTERFACE__

/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/
