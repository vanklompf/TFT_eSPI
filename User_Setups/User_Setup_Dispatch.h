#ifndef USER_SETUP_DISPATCH_H
#define USER_SETUP_DISPATCH_H

#define ILI9341     101
#define ST7735      102
#define S6D02A1     103
#define RPI_ILI9486 104
#define ILI9163     105

#include "TFT_eSPI_config.h"


#if (TFT_DRIVER == ILI9341)
  #include "User_Setups/Setup_ILI9341.h"
  #include "TFT_Drivers/ILI9341_Defines.h"
#elif (TFT_DRIVER == ST7735)
  #include "User_Setups/Setup_ST7735.h"
  #include "TFT_Drivers/ST7735_Defines.h"
#elif (TFT_DRIVER == S6D02A1)
  #include "User_Setups/Setup_S6D02A1.h"
  #include "TFT_Drivers/S6D02A1_Defines.h"
#elif (TFT_DRIVER == RPI_ILI9486)
  #include "User_Setups/Setup_RPi_ILI9486.h"
  #include "TFT_Drivers/RPI_ILI9486_Defines.h"
#elif (TFT_DRIVER == ILI9163)
  #include "Setup_ILI9163.h"
  #include "TFT_Drivers/ILI9163_Defines.h"
#endif

#endif /* USER_SETUP_DISPATCH_H*/
