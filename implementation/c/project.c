/**************************************************************************//**
 * @file
 * @brief Empty Project
 * @author Energy Micro AS
 * @version 3.20.2
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silicon Labs Software License Agreement. See 
 * "http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt"  
 * for details. Before using this software for any purpose, you must agree to the 
 * terms of that agreement.
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "em_chip.h"

#include "application.h"


/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  APPLICATION_init();
  APPLICATION_execute();
}
