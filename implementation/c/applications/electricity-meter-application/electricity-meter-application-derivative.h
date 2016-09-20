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

#define __electricity_meter_application_getEvent()					( ELECTRICITY_METER_APPLICATION_selfData.event )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value
***********************************************************************************************************************/
#define __electricity_meter_application_setEvent(ev)				do{ ELECTRICITY_METER_APPLICATION_selfData.event = (ev); 					}while(0)
#define __electricity_meter_application_clearEvents()				do{ __electricity_meter_application_setEvent(__electricity_meter_application_evNone);	}while(0)

/**********************************************************************************************************************
* Public typedefs, that DO NOT depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public object-like macros that DO NOT depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that RETURN value and DO NOT depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO NOT RETURN value and DO NOT depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function declarations(extern), that DO NOT depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Include header files of all INTERNAL, and utilized EXTERNAL classes
***********************************************************************************************************************/

//Include header files of all INTERNAL, and utilized EXTERNAL classes
#include <stdbool.h>  //??
#include <stdint.h>   //??

//#include "caller.h"
//#include "components/bits/bits.h"

#include "components/efm32/cmu/cmu-derivative.h"
#include "components/efm32/gpio/gpio-derivative.h"
#include "components/efm32/usart/usart-derivative.h"
#include "components/efm32/dma/dma-derivative.h"

//#include "components/electricity-meter-m90e32as/electricity-meter-m90e32as-derivative.h"
//#include "components/communicator/communicator-derivative.h"
//#include "components/spi-exchanger/spi-exchanger-derivative.h"
//#include "components/transmitter/transmitter-derivative.h"
#include "components/phrase-receiver/phrase-receiver-derivative.h"

//Public typedefs, that DO depend on external declarations
typedef struct
{
	ELECTRICITY_METER_APPLICATION_DmaSelfData dma;
	ELECTRICITY_METER_APPLICATION_PhraseReceiverSelfData phrase_receiver;
//	ELECTRICITY_METER_APPLICATION_CommunicatorSelfData communicator;
//	ELECTRICITY_METER_APPLICATION_ElectricityMeterSelfData electricity_meter_m90e32as;
//	ELECTRICITY_METER_APPLICATION_SpiExchanger spi_exchanger;
	ELECTRICITY_METER_APPLICATION_Event event;
	ELECTRICITY_METER_APPLICATION_State state;
} electricity_meter_application_SelfData;

/**********************************************************************************************************************
* Public object-like macros that DO depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public object-like macros that DO depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that RETURN value and DO depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO NOT RETURN value and DO depend on external declarations
***********************************************************************************************************************/

/**********************************************************************************************************************
* Public function declarations(extern)
***********************************************************************************************************************/
extern void electricity_meter_application_init(void);
extern bool electricity_meter_application_isFinished(void);
extern void electricity_meter_application_execute(void);

//Component's data object declarations
extern electricity_meter_application_SelfData electricity_meter_application_selfData;

#endif //__ELECTRICITY_METER_APPLICATION_DERIVATIVE_INTERFACE__

/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/


