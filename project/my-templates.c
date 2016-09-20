								

								*******************************************************************************
								                                   ORDINARY
								*******************************************************************************


/**********************************************************************************************************************
 * C Header: xxx-yyy.h
 * Component | Composition | Application: Xxx Yyy Zzz
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __XXX_YYY_INTERFACE__
#define __XXX_YYY_INTERFACE__

//Include the component's configuration file
#include "xxx-zzz-configuration.h"

/**********************************************************************************************************************
 * Class: Xxx
 **********************************************************************************************************************/

//Dependency check

//Private typedefs

//Private object-like macros

//Private function-like macros that DO return value

//Private function-like macros that DO NOT return value

//Public typedefs

//Public object-like macros

//Public function-like macros that DO return value

//Public function-like macros that DO NOT return value

//Public function declarations (extern)

#endif //__XXX_YYY_INTERFACE__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/

/********************************************* ORDINARY SOURCE FILE ****************************************************

/**********************************************************************************************************************
 * C Source File: xxx-yyy.c
 * Component | Composition | Application: Xxx Yyy Zzz
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Class: Xxx
 **********************************************************************************************************************/

//Include class header files
#include "xxx-yyy.h"

//Private function definitions (static)

//Public function definitions.

/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/


						
						*******************************************************************************
						                                   COMPONENT
						*******************************************************************************


/************************************************COMPONENT HEADER FILE *************************************************
/***********************************************************************************************************************
 * C Header: xxx-yyy.h
 * Component: Xxx Yyy
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __XXX__YYY_INTERFACE__
#define __XXX__YYY_INTERFACE__

//Include component configuration file
#include "xxx-yyy-configuration.h"

 /**********************************************************************************************************************
 * Class: Xxx Yyy
 **********************************************************************************************************************/

//Dependency check

//Private typedefs

//Private object-like macros

//Private function-like macros that DO return value

//Private function-like macros that DO NOT return value

//Public typedefs, that DO NOT depend on EXTERNAL declarations

//Public object-like macros that DO NOT depend on EXTERNAL declarations

//Public function-like macros that DO return value and DO NOT depend on EXTERNAL declarations

//Public function-like macros that DO NOT return value and DO NOT depend on EXTERNAL declarations

//Public function declarations(extern), that DO NOT depend on EXTERNAL declarations

//Include header files of all(own) INTERNAL classes

//Public typedefs, that DO depend on EXTERNAL declarations

//Public object-like macros that DO depend on EXTERNAL declarations

//Public function-like macros that DO return value and DO depend on EXTERNAL declarations

//Public function-like macros that DO NOT return value and DO depend on EXTERNAL declarations

//Public function declarations(extern), that DO depend on EXTERNAL declarations

#endif //__XXX__YYY_INTERFACE__
/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

/************************************************COMPONENT SOURCE FILE *************************************************

/**********************************************************************************************************************
 * C Source File: xxx-yyy.c
 * Components: Xxx Yyy
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Class: Xxx Yyy
 **********************************************************************************************************************/

//Include class header file
#include "xxx-yyy.h"

//Conditionally include component's INTERNAL(OWN) source files
	#if (CCC_singleTranslationUnit() != 0)
#endif

//Private functions definition (static)

//Public function definitions

/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

/*************************************************COMPONENT CONFIGURATION***********************************************

/**********************************************************************************************************************
 * C Configuration Header: xxx-yyy-configuration.h
 * Component: Xxx Yyy Zzz
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __XXX_YYY_CONFIGURATION__
#define __XXX_YYY_CONFIGURATION__

//Include application configuration file
#include "application-configuration.h"

//Interface declarations required by its own classes

#endif //__XXX_YYY_CONFIGURATION__
/**********************************************************************************************************************
* End of File
**********************************************************************************************************************/


					*******************************************************************************
					                                   COMPOSITION
					*******************************************************************************


/************************************************COMPOSITION HEADER FILE *************************************************
/**********************************************************************************************************************
 * C Header: xxx-yyy.h
 * Composition: Xxx Yyy
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __XXX__YYY_INTERFACE__
#define __XXX__YYY_INTERFACE__

//Include component configuration file
#include "xxx-yyy-configuration.h"

 /**********************************************************************************************************************
 * Class: Xxx Yyy
 **********************************************************************************************************************/

//Dependency check

//Private typedefs

//Private object-like macros

//Private function-like macros that DO return value

//Private function-like macros that DO NOT return value

//Public typedefs, that DO NOT depend on EXTERNAL declarations

//Public object-like macros that DO NOT depend on EXTERNAL declarations

//Public function-like macros that DO return value and DO NOT depend on EXTERNAL declarations

//Public function-like macros that DO NOT return value and DO NOT depend on EXTERNAL declarations

//Public function declarations(extern), that DO NOT depend on EXTERNAL declarations

//Include header files of all(own) INTERNAL classes

//Public typedefs, that DO depend on EXTERNAL declarations

//Public object-like macros that DO depend on EXTERNAL declarations

//Public function-like macros that DO return value and DO depend on EXTERNAL declarations

//Public function-like macros that DO NOT return value and DO depend on EXTERNAL declarations

//Public function declarations(extern), that DO depend on EXTERNAL declarations

#endif //__XXX__YYY_INTERFACE__
/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

/*************************************** COMPOSITION SOURCE FILE **********************************************

/**********************************************************************************************************************
 * C Source File: xxx-yyy.c
 * Composition: Xxx Yyy 
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include class header file
 #include "xxx-yyy-application.h"

//Conditional inclusion of all INTERNAL and EXTERNAL source files

/**********************************************************************************************************************
 * Class: Xxx Yyy Application
 **********************************************************************************************************************/

//Private function definitions (static) 

//Public function definitions 


 /**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

/*************************************** COMPOSITION CONFIGURATION *****************************************************

/**********************************************************************************************************************
 * C Configuration Header: xxx-yyy-configuration.h
 * Composition: Xxx Yyy
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include guard
#ifndef __XXX_YYY_CONFIGURATION__
#define __XXX_YYY_CONFIGURATION__

//Include application configuration file
#include "application-configuration.h"

//Interface declarations required by its(own) INTERNAL and ('aggregated')EXTERNAL classes

#endif //__XXX_YYY_CONFIGURATION__
/**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/


					*******************************************************************************
					                                   APPLICATION
					*******************************************************************************


/**********************************************************************************************************************
 * C Header: xxx-yyy-application.h
 * Application: Xxx Yyy Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

#ifndef __XXX_YYY_APPLICATION_INTERFACE__
#define __XXX_YYY_APPLICATION_INTERFACE__

//Include application configuration file

/**********************************************************************************************************************
 * Class: Xxx Yyy Application
 **********************************************************************************************************************/

//Dependency check

//Private typedefs

//Private object-like macros

//Private function-like macros that DO return value

//Private function-like macros that DO NOT return value

//Public typedefs, that DO NOT depend on EXTERNAL declarations

//Public object-like macros that DO NOT depend on EXTERNAL declarations

//Public function-like macros that RETURN value and DO NOT depend on EXTERNAL declarations

//Public function-like macros that DO NOT RETURN value and DO NOT depend on EXTERNAL declarations

//Public function declarations(extern), that DO NOT depend on EXTERNAL declarations

//Include header files of all INTERNAL, and utilized EXTERNAL classes

//Public typedefs, that DO depend on EXTERNAL declarations

//Public object-like macros that DO depend on EXTERNAL declarations

//Public function-like macros that RETURN value and DO depend on EXTERNAL declarations

//Public function-like macros that DO NOT RETURN value and DO depend on EXTERNAL declarations

//Public function declarations(extern), that DO depend on EXTERNAL declarations

//Component's data object declarations

#endif //__XXX_YYY_APPLICATION_INTERFACE__
 /**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

/*************************************** APPLICATION SOURCE FILE **********************************************

/**********************************************************************************************************************
 * C Source File: xxx-yyy-application.c
 * Application: Xxx Yyy Application
 *=====================================================================================================================
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/

//Include class header file
 #include "xxx-yyy-application.h"

//Conditional inclusion of all INTERNAL and EXTERNAL source files

/**********************************************************************************************************************
 * Class: Xxx Yyy Application
 **********************************************************************************************************************/

//Private function definitions (static) 

//Public function definitions 

//Application data objects (instances) 

 /**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/

/********************************************APPLICATION CONFIGURATION**************************************************

/**********************************************************************************************************************
 * C Configuration Header: xxx-yyy-application-configuration.h
 * Application: Xxx Yyy Application
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/
///////////////// APPLICATION CLASS CONFIGURATION HEADER FILE /////////////////

//Include guard
#ifndef __XXX_YYY_APPLICATION_CONFIGURATION__
#define __XXX_YYY_APPLICATION_CONFIGURATION__

//Interface declarations required by its(own) INTERNAL and (aggregated)EXTERNAL classes

#endif //__XXX_YYY_APPLICATION_CONFIGURATION__
 /**********************************************************************************************************************
 * End of File
 **********************************************************************************************************************/


              ***********************************************************************************
              ***********************************************************************************
              ***********************************************************************************
              ***********************************************************************************
              ***********************************************************************************
              ***********************************************************************************
              ***********************************************************************************
              ***********************************************************************************


 /**********************************************************************************************************************
 * <C Header: caller.h 		// 'C '{'Source File', 'Header', 'Configuration Header'}': ''file-name.''{'.c','h'}'
 * <Component: Electricity Meter Application> 	//{'Component', 'Composition', 'Application'}': ''The Name Of the
 * 	Component That Owns The File'
 *===================================================================================================================== 
 * C Software Construction Framework v1-1-03.16
 * © 2016 ADD-Bulgaria Ltd.
 **********************************************************************************************************************/
 - 'Ordinary class' symbolizes a pair of definitions and declarations separated in two files - one source file and a header.
       	The ordinary classes are used to categorize code with common classified characteristics and processes.

 - 'Package' symbolizes a folder, that contains one configuration file, one component class and from none to many ordinary classes.
 		That folder bears the name of the component.

  - 'Component' symbolizes reusable, relatively accomplished code-module that can be included by composition or application. The component is
       	configured trough its configuration file. The component has the file structure of a package.
    
 - 'INTERNAL' symbolizes all files within the component(the package), except the component class itself.
 - 'EXTERNAL' symbolizes  all files that are used by the component, but do not reside within the component(package).  
 
 - Whenever into the HEADER(Of the file) there are several options for a symbol, these options are separated by pipe character '|'. Only one
 	option is allowed.