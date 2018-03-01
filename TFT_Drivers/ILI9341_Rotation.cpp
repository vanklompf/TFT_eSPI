#include "TFT_eSPI.h"

// This is the command sequence that rotates the ILI9341 driver coordinate frame
#if (TFT_DRIVER == ILI9341)

void TFT_eSPI::setRotationImpl(uint8_t rotation)
{

  rotation = rotation % 8; // Limit the range of values to 0-7

  writecommand(TFT_MADCTL);
  switch (rotation) {
    case 0:
#ifdef M5STACK
      writedata(TFT_MAD_MY | TFT_MAD_MV | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MX | TFT_MAD_BGR);
#endif
      _width  = _width_orig;
      _height = _height_orig;
      break;
    case 1:
#ifdef M5STACK
      writedata(TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MV | TFT_MAD_BGR);
#endif
      _width  = _height_orig;
      _height = _width_orig;
      break;
    case 2:
#ifdef M5STACK
      writedata(TFT_MAD_MV | TFT_MAD_MX | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MY | TFT_MAD_BGR);
#endif
      _width  = _width_orig;
      _height = _height_orig;
      break;
    case 3:
#ifdef M5STACK
      writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_MV | TFT_MAD_BGR);
#endif
      _width  = _height_orig;
      _height = _width_orig;
      break;
  // These next rotations are for bottom up BMP drawing
    case 4:
#ifdef M5STACK
      writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_MV | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_BGR);
#endif
      _width  = _width_orig;
      _height = _height_orig;
      break;
    case 5:
#ifdef M5STACK
      writedata(TFT_MAD_MY | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MV | TFT_MAD_MX | TFT_MAD_BGR);
#endif
      _width  = _height_orig;
      _height = _width_orig;
      break;
    case 6:
#ifdef M5STACK
      writedata(TFT_MAD_MV | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_BGR);
#endif
      _width  = _width_orig;
      _height = _height_orig;
      break;
    case 7:
#ifdef M5STACK
      writedata(TFT_MAD_MX | TFT_MAD_BGR);
#else
      writedata(TFT_MAD_MY | TFT_MAD_MV | TFT_MAD_BGR);
#endif
      _width  = _height_orig;
      _height = _width_orig;
      break;

  }
}
#endif /* (TFT_DRIVER == ILI9341) */

