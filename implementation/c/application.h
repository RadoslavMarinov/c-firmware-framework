

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

// Defined into the ProjectProperties -> C/C++ General -> Tab #Symbols -> Language C
#ifdef ELECTRICITY_METER_CONTROLLER_HAPPY_GECKO_APPLICATION
	// Include application header files
	#include "applications/electricity-meter-controller-happy-gecko/electricity-meter-controller-happy-gecko-application-primary.h"
	#include "applications/electricity-meter-controller-happy-gecko/electricity-meter-controller-happy-gecko-application-configuration.h"
	#include "applications/electricity-meter-controller-happy-gecko/electricity-meter-controller-happy-gecko-application-derivative.h"

	// project.c uses these methods in its main()
	#define APPLICATION_init()                      do{ electricity_meter_controller_happy_gecko_application_init(); }while(0)
	#define APPLICATION_execute()                   ( electricity_meter_controller_happy_gecko_application_execute() )

	// Defined into the ProjectProperties -> C/C++ General -> Tab #Symbols -> Language C
	#if application_isSingleCompilationUnit()
		#include"applications/electricity-meter-controller-happy-gecko/electricity-meter-controller-happy-gecko-application.c"
	#endif
#endif

#endif
