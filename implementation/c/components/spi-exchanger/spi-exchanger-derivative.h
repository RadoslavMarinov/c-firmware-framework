/***********************************************************************************************************************
* C Header: spi-exchanger-derivative.h
* Component: Spi Exchanger
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include guard
**********************************************************************************************************************/
#ifndef __SPI_EXCHANGER_DERIVATIVE_INTERFCE__
#define __SPI_EXCHANGER_DERIVATIVE_INTERFCE__


/**********************************************************************************************************************
* Dependency check
**********************************************************************************************************************/
#ifndef SPI_EXCHANGER_initSpi
	#error Missing required SPI_EXCHANGER_initSpi()
#endif

#ifndef SPI_EXCHANGER_isDmaReadChannelDone
	#error Missing required SPI_EXCHANGER_isDmaReadChannelDone()
#endif

#ifndef SPI_EXCHANGER_isDmaWriteChannelDone
	#error Missing required SPI_EXCHANGER_isDmaWriteChannelDone()
#endif

#ifndef SPI_EXCHANGER_clearDmaReadChannelDone
	#error Missing required SPI_EXCHANGER_clearDmaReadChannelDone()
#endif

#ifndef SPI_EXCHANGER_clearDmaWriteChannelDone
	#error Missing required SPI_EXCHANGER_clearDmaWriteChannelDone()
#endif

#ifndef SPI_EXCHANGER_responseDone
	#error Missing required SPI_EXCHANGER_responseDone()
#endif

/**********************************************************************************************************************
* Include the derivative headers of the INTERNAL (owned) classes
**********************************************************************************************************************/
//#include "xxx-yyy-derivative.h"

/**********************************************************************************************************************
* Private typedefs (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private object-like macros   (__xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private function-like macros that DO return value  (__xxx)
**********************************************************************************************************************/

#define __spi_exchanger_getEvent()									( SPI_EXCHANGER_selfData.event )
#define __spi_exchanger_getState()									( SPI_EXCHANGER_selfData.state )

/**********************************************************************************************************************
* Private function-like macros that DO NOT return value (__xxx)
**********************************************************************************************************************/
// Event setters
#define __spi_exchanger_setEvent(ev)								do{ SPI_EXCHANGER_selfData.event = (ev);									}while(0)
#define __spi_exchanger_clearEvents()								do{ __spi_exchanger_setEvent( __spi_exchanger_evNone );						}while(0)
#define __spi_exchanger_setEventEntry()								do{ __spi_exchanger_setEvent( __spi_exchanger_evEntry );					}while(0)
#define __spi_exchanger_setEventRead()								do{ __spi_exchanger_setEvent( __spi_exchanger_evRead );						}while(0)
#define __spi_exchanger_setEventWrite()								do{ __spi_exchanger_setEvent( __spi_exchanger_evWrite );					}while(0)

// State setters
#define __spi_exchanger_setState(st)								do{ SPI_EXCHANGER_selfData.state = (st);									}while(0)
#define __spi_exchanger_setStateFail()								do{ __spi_exchanger_setState(__spi_exchanger_stFail);						}while(0)
#define __spi_exchanger_setStateIdle()								do{ __spi_exchanger_setState(__spi_exchanger_stIdle);						}while(0)
#define __spi_exchanger_setStateBusy()								do{ __spi_exchanger_setState(__spi_exchanger_stBusy);						}while(0)


/**********************************************************************************************************************
* Protected typedefs (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected object-like macros  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected function-like macros that DO return value  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected function-like macros that DO NOT return value  (_xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public typedefs  (xxx)
**********************************************************************************************************************/

typedef struct
{
	uint8_t event;
	uint8_t state;
}spi_exchanger_SelfData;

/**********************************************************************************************************************
* Public object-like macros  (xxx)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public function-like macros that DO return value (xxx)
**********************************************************************************************************************/

#define spi_exchanger_isBusy()					( __spi_exchanger_getState() ==  __spi_exchanger_stBusy ? true : false )

/**********************************************************************************************************************
* Public function-like macros that DO NOT return value (xxx)
**********************************************************************************************************************/

#define spi_exchanger_indicateRead()								do{ __spi_exchanger_setEventRead(); 										}while(0)
#define spi_exchanger_indicateWrite()								do{ __spi_exchanger_setEventWrite(); 										}while(0)



/**********************************************************************************************************************
* Public function declarations(extern)
**********************************************************************************************************************/
extern void spi_exchanger_init(void);
extern bool spi_exchanger_dispatchEvents(void);
/**********************************************************************************************************************
* Public Objects declaration
**********************************************************************************************************************/
	//extern ccc_SelfData ccc_selfData;


#endif //__SPI_EXCHANGER_DERIVATIVE_INTERFCE__
/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
