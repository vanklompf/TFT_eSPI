#ifndef TFT_eSPI_CONFIG_H
#define TFT_eSPI_CONFIG_H

// This header file is used to define type and configuration of driver used in Your project
// Keep it as simple as possible, do not add any preprocessor logic here not.
//
// Users can create configurations for different Espressif boards and TFT displays.
// This makes selecting between hardware setups easy by "uncommenting" few lines.


// For PlatformIO define configure your platform by proper defines in platformio.ini file
#if defined(PLATFORMIO)
  #ifndef TFT_DRIVER
    #error "Configure selected driver in platformio.ini file. See examples in TBD"
  #endif
#else
  // Select major type of driver by uncommenting ONE of #define TFT_DRIVER line. Default is ILI9163 driver.
  //#define TFT_DRIVER ILI9341
  //#define TFT_DRIVER ST7735
  //#define TFT_DRIVER S6D02A1
  //#define TFT_DRIVER RPI_ILI9486
  #define TFT_DRIVER ILI9163
#endif





/////////////////////////////////////////////////////////////////////////////////////
//                                                                                 //
//     DON'T TINKER WITH ANY OF THE FOLLOWING LINES, THESE ADD THE TFT DRIVERS     //
//       AND ESP8266 PIN DEFINITONS THEY ARE HERE FOR BODMER'S CONVENIENCE!        //
//                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////



// These are the pins for all ESP8266 boards
#define PIN_D0 16
#define PIN_D1  5
#define PIN_D2  4
#define PIN_D3  0
#define PIN_D4  2
#define PIN_D5 14
#define PIN_D6 12
#define PIN_D7 13
#define PIN_D8 15
#define PIN_D9  3
#define PIN_D10 1

#define PIN_MOSI 8
#define PIN_MISO 7
#define PIN_SCLK 6
#define PIN_HWCS 0

#define PIN_D11  9
#define PIN_D12 10

#endif /* TFT_eSPI_CONFIG_H */
