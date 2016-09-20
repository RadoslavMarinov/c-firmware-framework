/**********************************************************************************************************************
* C Header: top-limit-primary.h
* Component: Communicator
*=====================================================================================================================
* C Software Construction Framework v1-1-03.16
* © 2016 ADD-Bulgaria Ltd.
**********************************************************************************************************************/

/**********************************************************************************************************************
* Include guard
**********************************************************************************************************************/
#ifndef __TOP_LIMIT_PRIMARY_INTERFACE__
#define __TOP_LIMIT_PRIMARY_INTERFACE__

/**********************************************************************************************************************
* Private  constants  (__xxx_)
**********************************************************************************************************************/

//== Events
enum
{
	__top_limit_evDo,
	__top_limit_evNone,
	__top_limit_evSearch,
};

//== States
enum
{
	__top_limit_stCompareAverage,
	__top_limit_stCompareBottom,
	__top_limit_stRejected,
	__top_limit_stFound,
	__top_limit_stIdle,
	__top_limit_stNotFound,
	__top_limit_stSearchDownward,
	__top_limit_stSearchUpward,

};


/**********************************************************************************************************************
* Private  typedefs  (__xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private  Object-like macro definitions  (__xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private Function-like macro definitions  (__xxx_)  that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* Private Function-like macro definitions  (__xxx_) that DON'T RETURN VALUE
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected typedefs  (__xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected Object-like macro definitions  (__xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected Function-like macro definitions  (__xxx_)  that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* Protected Function-like macro definitions  (__xxx_) that DON'T RETURN VALUE
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public  typedefs  (xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public  Object-like macro definitions  (xxx_)
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public Function-like macro definitions  (xxx_)  that DO return value
**********************************************************************************************************************/

/**********************************************************************************************************************
* Public Function-like macro definitions  (xxx_) that DON'T RETURN VALUE
**********************************************************************************************************************/

#endif //__TOP_LIMIT_PRIMARY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/

/*
 * In order to work properly the following properties need to be set.
 * PROPERTYS					EXAMPLES
 * Set Column: 					__reader_setColumn(0);
 * Set Character 				__range_setCharacter('s');
 * Set Top: 					top_limit_setTop(0);
 * Set Bottom:					top_limit_setBottom(9);
 * Initialize the instance: 	ELECTRICITY_METER_APPLICATION_topLimitInit();
 * Post Event Search:			top_limit_indicateSearch();
 */