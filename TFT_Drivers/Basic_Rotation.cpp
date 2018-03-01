#include "TFT_eSPI.h"

// This is the command sequence that rotates the ST7735/ILI9163/S6D02A1 driver coordinate frame
#if (TFT_DRIVER == ILI9163) || (TFT_DRIVER == ST7735) || (TFT_DRIVER == S6D02A1)

#if (TFT_DRIVER == ST7735)
  #include "TFT_Drivers/ST7735_Defines.h"
#elif (TFT_DRIVER == ILI9163)
  #include "TFT_Drivers/ILI9163_Defines.h"
#elif (TFT_DRIVER == S6D02A1)
  #include "TFT_Drivers/S6D02A1_Defines.h"
#endif

void TFT_eSPI::setRotationImpl(uint8_t rotation)
{
  rotation = rotation % 4; // Limit the range of values to 0-3

  writecommand(TFT_MADCTL);
  switch (rotation) {
    case 0:
       writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_COLOR_ORDER);
      _width  = _width_orig;
      _height = _height_orig;
#ifdef CGRAM_OFFSET
      colstart = R0_OFFSET_X;
      rowstart = R0_OFFSET_Y;
#endif
      break;
    case 1:
       writedata(TFT_MAD_MY | TFT_MAD_MV | TFT_COLOR_ORDER);
      _width  = _height_orig;
      _height = _width_orig;
#ifdef CGRAM_OFFSET
      colstart = R1_OFFSET_X;
      rowstart = R1_OFFSET_Y;
#endif
      break;
    case 2:
       writedata(TFT_COLOR_ORDER);
      _width  = _width_orig;
      _height = _height_orig;
#ifdef CGRAM_OFFSET
      colstart = R2_OFFSET_X;
      rowstart = R2_OFFSET_Y;
#endif
      break;
    case 3:
       writedata(TFT_MAD_MX | TFT_MAD_MV | TFT_COLOR_ORDER);
      _width  = _height_orig;
      _height = _width_orig;
#ifdef CGRAM_OFFSET
      colstart = R3_OFFSET_X;
      rowstart = R3_OFFSET_Y;
#endif
      break;
  }
}

#endif
