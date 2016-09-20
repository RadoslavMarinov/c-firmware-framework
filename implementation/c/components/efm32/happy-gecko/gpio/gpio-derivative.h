/***********************************************************************************************************************
 * C Header: gpio.h
 * Component: gpio
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * � 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __GPIO_DERIVATIVE_INTERFACE__
#define __GPIO_DERIVATIVE_INTERFACE__

 /**********************************************************************************************************************
 * Include the derivative headers of the INTERNAL (owned) classes
 **********************************************************************************************************************/
#include "port-derivative.h"

/**********************************************************************************************************************
 *Dependency check
 **********************************************************************************************************************/
#ifndef GPIO_isSingleTranslationUnit
	#error Missing required GPIO_isSingleTranslationUnit()
#endif

#ifndef GPIO_PortSelfData
	#error Missing required GPIO_PortSelfData
#endif

#ifndef GPIO_setPinsMode
	#error Missing required GPIO_setPinsMode(port, pinGroup, mode)
#endif


/**********************************************************************************************************************
 *Private typedefs
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *Private object-like macros
 **********************************************************************************************************************/


/**********************************************************************************************************************
*Private function-like macros that DO return value
**********************************************************************************************************************/
/*
#define __gpio_getPinsA07Mode()   ( GPIO_getA00Mode() | GPIO_getA01Mode() | GPIO_getA02Mode() | GPIO_getA03Mode() | GPIO_getA04Mode() | GPIO_getA05Mode() | GPIO_getA06Mode() | GPIO_getA07Mode() )
#define __gpio_getPinsA815Mode()  ( GPIO_getA08Mode() | GPIO_getA09Mode() | GPIO_getA10Mode() | GPIO_getA11Mode() | GPIO_getA12Mode() | GPIO_getA13Mode() | GPIO_getA14Mode() | GPIO_getA15Mode() )
#define __gpio_getPinsB07Mode()   ( GPIO_getB00Mode() | GPIO_getB01Mode() | GPIO_getB02Mode() | GPIO_getB03Mode() | GPIO_getB04Mode() | GPIO_getB05Mode() | GPIO_getB06Mode() | GPIO_getB07Mode() )
#define __gpio_getPinsB815Mode()  ( GPIO_getB08Mode() | GPIO_getB09Mode() | GPIO_getB10Mode() | GPIO_getB11Mode() | GPIO_getB12Mode() | GPIO_getB13Mode() | GPIO_getB14Mode() | GPIO_getB15Mode() )
#define __gpio_getPinsC07Mode()   ( GPIO_getC00Mode() | GPIO_getC01Mode() | GPIO_getC02Mode() | GPIO_getC03Mode() | GPIO_getC04Mode() | GPIO_getC05Mode() | GPIO_getC06Mode() | GPIO_getC07Mode() )
#define __gpio_getPinsC815Mode()  ( GPIO_getC08Mode() | GPIO_getC09Mode() | GPIO_getC10Mode() | GPIO_getC11Mode() | GPIO_getC12Mode() | GPIO_getC13Mode() | GPIO_getC14Mode() | GPIO_getC15Mode() )
#define __gpio_getPinsD07Mode()   ( GPIO_getD00Mode() | GPIO_getD01Mode() | GPIO_getD02Mode() | GPIO_getD03Mode() | GPIO_getD04Mode() | GPIO_getD05Mode() | GPIO_getD06Mode() | GPIO_getD07Mode() )
#define __gpio_getPinsD815Mode()  ( GPIO_getD08Mode() | GPIO_getD09Mode() | GPIO_getD10Mode() | GPIO_getD11Mode() | GPIO_getD12Mode() | GPIO_getD13Mode() | GPIO_getD14Mode() | GPIO_getD15Mode() )
#define __gpio_getPinsE07Mode()   ( GPIO_getE00Mode() | GPIO_getE01Mode() | GPIO_getE02Mode() | GPIO_getE03Mode() | GPIO_getE04Mode() | GPIO_getE05Mode() | GPIO_getE06Mode() | GPIO_getE07Mode() )
#define __gpio_getPinsE815Mode()  ( GPIO_getE08Mode() | GPIO_getE09Mode() | GPIO_getE10Mode() | GPIO_getE11Mode() | GPIO_getE12Mode() | GPIO_getE13Mode() | GPIO_getE14Mode() | GPIO_getE15Mode() )
#define __gpio_getPinsF07Mode()   ( GPIO_getF00Mode() | GPIO_getF01Mode() | GPIO_getF02Mode() | GPIO_getF03Mode() | GPIO_getF04Mode() | GPIO_getF05Mode() | GPIO_getF06Mode() | GPIO_getF07Mode() )
#define __gpio_getPinsF815Mode()  ( GPIO_getF08Mode() | GPIO_getF09Mode() | GPIO_getF10Mode() | GPIO_getF11Mode() | GPIO_getF12Mode() | GPIO_getF13Mode() | GPIO_getF14Mode() | GPIO_getF15Mode() )
//

#define __gpio_getPortAOutput()   ( GPIO_getPinA00OutputLevel() | GPIO_getPinA01OutputLevel() | GPIO_getPinA02OutputLevel() | GPIO_getPinA03OutputLevel() | GPIO_getPinA04OutputLevel()\
								  | GPIO_getPinA05OutputLevel() | GPIO_getPinA06OutputLevel() | GPIO_getPinA07OutputLevel() | GPIO_getPinA08OutputLevel() | GPIO_getPinA09OutputLevel()\
								  | GPIO_getPinA10OutputLevel() | GPIO_getPinA11OutputLevel() | GPIO_getPinA12OutputLevel() | GPIO_getPinA13OutputLevel() | GPIO_getPinA14OutputLevel()\
								  | GPIO_getPinA15OutputLevel() )

#define __gpio_getPortBOutput()   ( GPIO_getPinB00OutputLevel() | GPIO_getPinB01OutputLevel() | GPIO_getPinB02OutputLevel() | GPIO_getPinB03OutputLevel() | GPIO_getPinB04OutputLevel()\
								  | GPIO_getPinB05OutputLevel() | GPIO_getPinB06OutputLevel() | GPIO_getPinB07OutputLevel() | GPIO_getPinB08OutputLevel() | GPIO_getPinB09OutputLevel()\
								  | GPIO_getPinB10OutputLevel() | GPIO_getPinB11OutputLevel() | GPIO_getPinB12OutputLevel() | GPIO_getPinB13OutputLevel() | GPIO_getPinB14OutputLevel()\
								  | GPIO_getPinB15OutputLevel() )

#define __gpio_getPortCOutput()   ( GPIO_getPinC00OutputLevel() | GPIO_getPinC01OutputLevel() | GPIO_getPinC02OutputLevel() | GPIO_getPinC03OutputLevel() | GPIO_getPinC04OutputLevel()\
								  | GPIO_getPinC05OutputLevel() | GPIO_getPinC06OutputLevel() | GPIO_getPinC07OutputLevel() | GPIO_getPinC08OutputLevel() | GPIO_getPinC09OutputLevel()\
								  | GPIO_getPinC10OutputLevel() | GPIO_getPinC11OutputLevel() | GPIO_getPinC12OutputLevel() | GPIO_getPinC13OutputLevel() | GPIO_getPinC14OutputLevel()\
								  | GPIO_getPinC15OutputLevel() )

#define __gpio_getPortDOutput()   ( GPIO_getPinD00OutputLevel() | GPIO_getPinD01OutputLevel() | GPIO_getPinD02OutputLevel() | GPIO_getPinD03OutputLevel() | GPIO_getPinD04OutputLevel()\
								  | GPIO_getPinD05OutputLevel() | GPIO_getPinD06OutputLevel() | GPIO_getPinD07OutputLevel() | GPIO_getPinD08OutputLevel() | GPIO_getPinD09OutputLevel()\
								  | GPIO_getPinD10OutputLevel() | GPIO_getPinD11OutputLevel() | GPIO_getPinD12OutputLevel() | GPIO_getPinD13OutputLevel() | GPIO_getPinD14OutputLevel()\
								  | GPIO_getPinD15OutputLevel() )

#define __gpio_getPortEOutput()   ( GPIO_getPinE00OutputLevel() | GPIO_getPinE01OutputLevel() | GPIO_getPinE02OutputLevel() | GPIO_getPinE03OutputLevel() | GPIO_getPinE04OutputLevel()\
								  | GPIO_getPinE05OutputLevel() | GPIO_getPinE06OutputLevel() | GPIO_getPinE07OutputLevel() | GPIO_getPinE08OutputLevel() | GPIO_getPinE09OutputLevel()\
								  | GPIO_getPinE10OutputLevel() | GPIO_getPinE11OutputLevel() | GPIO_getPinE12OutputLevel() | GPIO_getPinE13OutputLevel() | GPIO_getPinE14OutputLevel()\
								  | GPIO_getPinE15OutputLevel() )

#define __gpio_getPortFOutput()   ( GPIO_getPinF00OutputLevel() | GPIO_getPinF01OutputLevel() | GPIO_getPinF02OutputLevel() | GPIO_getPinF03OutputLevel() | GPIO_getPinF04OutputLevel()\
								  | GPIO_getPinF05OutputLevel() | GPIO_getPinF06OutputLevel() | GPIO_getPinF07OutputLevel() | GPIO_getPinF08OutputLevel() | GPIO_getPinF09OutputLevel()\
								  | GPIO_getPinF10OutputLevel() | GPIO_getPinF11OutputLevel() | GPIO_getPinF12OutputLevel() | GPIO_getPinF13OutputLevel() | GPIO_getPinF14OutputLevel()\
								  | GPIO_getPinF15OutputLevel() )

//
#if __gpio_getPinsA07Mode() > 0
	#define __gpio_setPinsA07Mode()   do { GPIO_setPinsMode( gpio_portA, GPIO_pins_0_7, __gpio_getPinsA07Mode() );  } while(0)
#else
	#define __gpio_setPinsA07Mode()   //
#endif
//
#if __gpio_getPinsA815Mode() > 0
	#define __gpio_setPinsA815Mode()   do { GPIO_setPinsMode( gpio_portA, GPIO_pins_8_15, __gpio_getPinsA815Mode() );  } while(0)
#else
	#define __gpio_setPinsA815Mode()   //
#endif
//
#if __gpio_getPinsB07Mode() > 0
	#define __gpio_setPinsB07Mode()   do { GPIO_setPinsMode( gpio_portB, GPIO_pins_0_7, __gpio_getPinsB07Mode() );  } while(0)
#else
	#define __gpio_setPinsB07Mode()   //
#endif
//
#if __gpio_getPinsB815Mode() > 0
	#define __gpio_setPinsB815Mode()  do { GPIO_setPinsMode( gpio_portB, GPIO_pins_8_15, __gpio_getPinsB815Mode() );  } while(0)
#else
	#define __gpio_setPinsB815Mode()   //
#endif
//
#if __gpio_getPinsC07Mode() > 0
	#define __gpio_setPinsC07Mode()   do { GPIO_setPinsMode( gpio_portC, GPIO_pins_0_7, __gpio_getPinsC07Mode() );  } while(0)
#else
	#define __gpio_setPinsC07Mode()   //
#endif
//
#if __gpio_getPinsC815Mode() > 0
	#define __gpio_setPinsC815Mode()   do { GPIO_setPinsMode( gpio_portC, GPIO_pins_8_15, __gpio_getPinsC815Mode() );  } while(0)
#else
	#define __gpio_setPinsC815Mode()   //
#endif
//
#if __gpio_getPinsD07Mode() > 0
	#define __gpio_setPinsD07Mode()   do { GPIO_setPinsMode( gpio_portD, GPIO_pins_0_7, __gpio_getPinsD07Mode() );  } while(0)
#else
	#define __gpio_setPinsD07Mode()  //
#endif
//
#if __gpio_getPinsD815Mode() > 0
	#define __gpio_setPinsD815Mode()   do { GPIO_setPinsMode( gpio_portD, GPIO_pins_8_15, __gpio_getPinsD815Mode() );  } while(0)
#else
	#define __gpio_setPinsD815Mode()   //
#endif
//
#if __gpio_getPinsE07Mode() > 0
	#define __gpio_setPinsE07Mode()   do { GPIO_setPinsMode( gpio_portE, GPIO_pins_0_7, __gpio_getPinsE07Mode() );  } while(0)
#else
	#define __gpio_setPinsE07Mode()   //
#endif
//
#if __gpio_getPinsE815Mode() > 0
	#define __gpio_setPinsE815Mode()   do { GPIO_setPinsMode( gpio_portE, GPIO_pins_8_15, __gpio_getPinsE815Mode() );  } while(0)
#else
	#define __gpio_setPinsE815Mode()   //
#endif
//
#if __gpio_getPinsF07Mode() > 0
	#define __gpio_setPinsF07Mode()   do { GPIO_setPinsMode( gpio_portF, GPIO_pins_0_7, __gpio_getPinsF07Mode() );  } while(0)
#else
	#define __gpio_setPinsF07Mode()   //
#endif
//
#if __gpio_getPinsF815Mode() > 0
	#define __gpio_setPinsF815Mode()   do { GPIO_setPinsMode( gpio_portF, GPIO_pins_8_15, __gpio_getPinsF815Mode() );  } while(0)
#else
	#define __gpio_setPinsF815Mode()   //
#endif
//
//--//
//
#if __gpio_getPortAOutput() > 0
	#define __gpio_setPortAOutput() 	do{ GPIO_setPortOutput(gpio_portA, __gpio_getPortAOutput() );               } while(0)
#else
	#define __gpio_setPortAOutput()
#endif

#if __gpio_getPortBOutput() > 0
	#define __gpio_setPortBOutput() 	do{ GPIO_setPortOutput(gpio_portB, __gpio_getPortBOutput() );               } while(0)
#else
	#define __gpio_setPortBOutput()
#endif

#if __gpio_getPortCOutput() > 0
	#define __gpio_setPortCOutput() 	do{ GPIO_setPortOutput(gpio_portC, __gpio_getPortCOutput() );               } while(0)
#else
	#define __gpio_setPortCOutput()
#endif

#if __gpio_getPortDOutput() > 0
	#define __gpio_setPortDOutput() 	do{ GPIO_setPortOutput(gpio_portD, __gpio_getPortDOutput() );               } while(0)
#else
	#define __gpio_setPortDOutput()
#endif

#if __gpio_getPortEOutput() > 0
	#define __gpio_setPortEOutput() 	do{ GPIO_setPortOutput(gpio_portE, __gpio_getPortEOutput() );               } while(0)
#else
	#define __gpio_setPortEOutput()
#endif

#if __gpio_getPortFOutput() > 0
	#define __gpio_setPortFOutput() 	do{ GPIO_setPortOutput(gpio_portF, __gpio_getPortFOutput() );               } while(0)
#else
	#define __gpio_setPortFOutput()
#endif
//
//--//
/*/
/**********************************************************************************************************************
* Private function-like macros that DO NOT return value
**********************************************************************************************************************/


/**********************************************************************************************************************
 *Public typedefs, that DO depend on EXTERNAL declarations
 **********************************************************************************************************************/

typedef struct
{
	GPIO_PortSelfData ports;
	uint32_t reserved[10];
	volatile uint32_t lowLevelInterrupt;
	volatile uint32_t highLevelInterrupt;
	volatile uint32_t risingEdgeInterrupt;
	volatile uint32_t fallingEdgeInterrupt;
	volatile uint32_t interruptEnable;
	volatile uint32_t interruptFlag;
	volatile uint32_t raiseInterruptFlagCommand;
	volatile uint32_t clearInterruptFlagCommand;
	volatile uint32_t route;
	volatile uint32_t inputSense;
	volatile uint32_t lock;
	volatile uint32_t control;
	volatile uint32_t command;
	volatile uint32_t em4WakeUpEnable;
	volatile uint32_t em4WakeUpPolarity;
	volatile uint32_t em4WakeUpCause;
} gpio_SelfData;

/**********************************************************************************************************************
*Public object-like macros that
**********************************************************************************************************************/

/**********************************************************************************************************************
 *Public function-like macros that DO return value
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *Public function-like macros that DO NOT return value
 **********************************************************************************************************************/

#define gpio_init()              		do { \
                                               __gpio_setPinsA07Mode();\
                                               __gpio_setPinsA815Mode();\
                                               __gpio_setPinsB07Mode();\
                                               __gpio_setPinsB815Mode();\
                                               __gpio_setPinsC07Mode();\
                                               __gpio_setPinsC815Mode();\
                                               __gpio_setPinsD07Mode();\
                                               __gpio_setPinsD815Mode();\
                                               __gpio_setPinsE07Mode();\
                                               __gpio_setPinsE815Mode();\
                                               __gpio_setPinsF07Mode();\
                                               __gpio_setPinsF815Mode();\
                                               __gpio_setPortAOutput();\
                                               __gpio_setPortBOutput();\
                                               __gpio_setPortCOutput();\
                                               __gpio_setPortDOutput();\
                                               __gpio_setPortEOutput();\
                                               __gpio_setPortFOutput();\
                                          } while(0)

/**********************************************************************************************************************
*Public function declarations(extern
**********************************************************************************************************************/

/**********************************************************************************************************************
* Component's data object declarations
**********************************************************************************************************************/
extern gpio_SelfData gpio_selfData;

#endif //__GPIO_DERIVATIVE_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/
