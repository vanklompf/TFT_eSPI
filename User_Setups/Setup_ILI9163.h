#ifndef SETUP_ILI9163_H
#define SETUP_ILI9163_H

//                            ILI9163_DRIVER SETTINGS
//   Set driver type, fonts to be loaded, pins used and SPI control method etc

// define the pixel width and height in portrait orientation
#ifndef TFT_WIDTH
  #define TFT_WIDTH  128
#endif
#ifndef TFT_HEIGHT
  #define TFT_HEIGHT 160
#endif

// For ILI9163 variants with height smaller than 160 offsets for CGRAM are needed
// Multiple variants of CGRAM to display mapping exist. Here define offset for x and y axis for each rotation. Offsets are used in Basic_Rotation.h
#if (TFT_HEIGHT != 160)
  #ifndef CGRAM_OFFSET
    #define CGRAM_OFFSET
  #endif
  #ifndef R0_OFFSET_X
    #define R0_OFFSET_X 0
  #endif
  #ifndef R0_OFFSET_Y
    #define R0_OFFSET_Y 0
  #endif
  #ifndef R1_OFFSET_X
    #define R1_OFFSET_X 0
  #endif
  #ifndef R1_OFFSET_Y
    #define R1_OFFSET_Y 0
  #endif
  #ifndef R2_OFFSET_X
    #define R2_OFFSET_X 0
  #endif
  #ifndef R2_OFFSET_Y
    #define R2_OFFSET_Y 0
  #endif
  #ifndef R3_OFFSET_X
    #define R3_OFFSET_X 0
  #endif
  #ifndef R3_OFFSET_Y
    #define R3_OFFSET_Y 0
  #endif
#endif

// ##################################################################################
//
// Section 1. Define the pins that are used to interface with the display here
//
// ##################################################################################

// We must use hardware SPI, a minimum of 3 GPIO pins is needed.
// Typical setup for ESP8266 NodeMCU ESP-12 is :
//
// Display SDO/MISO  to NodeMCU pin D6 (or leave disconnected if not reading TFT)
// Display LED       to NodeMCU pin VIN (or 5V, see below)
// Display SCK       to NodeMCU pin D5
// Display SDI/MOSI  to NodeMCU pin D7
// Display DC (RS/AO)to NodeMCU pin D3
// Display RESET     to NodeMCU pin D4 (or RST, see below)
// Display CS        to NodeMCU pin D8 (or GND, see below)
// Display GND       to NodeMCU pin GND (0V)
// Display VCC       to NodeMCU 5V or 3.3V
//
// The TFT RESET pin can be connected to the NodeMCU RST pin or 3.3V to free up a control pin
//
// The DC (Data Command) pin may be labeled AO or RS (Register Select)
//
// With some displays such as the ILI9341 the TFT CS pin can be connected to GND if no more
// SPI devices (e.g. an SD Card) are connected, in this case comment out the #define TFT_CS
// line below so it is NOT defined. Other displays such at the ST7735 require the TFT CS pin
// to be toggled during setup, so in these cases the TFT_CS line must be defined and connected.
//
// The NodeMCU D0 pin can be used for RST
//
// See Section 2. below if DC or CS is connected to D0
//
// Note: only some versions of the NodeMCU provide the USB 5V on the VIN pin
// If 5V is not available at a pin you can use 3.3V but backlight brightness
// will be lower.


// ###### EDIT THE PIN NUMBERS IN THE LINES FOLLOWING TO SUIT YOUR ESP8266 SETUP ######

// For NodeMCU - use pin numbers in the form PIN_Dx where Dx is the NodeMCU pin designation
#ifndef TFT_CS
  #define TFT_CS   PIN_D8  // Chip select control pin D8
#endif
#ifndef TFT_DC
 #define TFT_DC   PIN_D3  // Data Command control pin
#endif
#ifndef TFT_RST
  #define TFT_RST  PIN_D4  // Reset pin (could connect to NodeMCU RST, see next line)
  //#define TFT_RST  -1  // Set TFT_RST to -1 if the display RESET is connected to NodeMCU RST or 3.3V
#endif



// ######  FOR ESP8266 OVERLAP MODE EDIT THE PIN NUMBERS IN THE FOLLOWING LINES  ######

// In ESP8266 overlap mode the TFT chip select MUST connect to pin D3
//#define TFT_CS   PIN_D3
//#define TFT_DC   PIN_D5  // Data Command control pin
//#define TFT_RST  PIN_D4  // Reset pin (could connect to NodeMCU RST, see next line)
//#define TFT_RST  -1  // Set TFT_RST to -1 if the display RESET is connected to NodeMCU RST or 3.3V

// In ESP8266 overlap mode the following must be defined
//#define TFT_SPI_OVERLAP


// ##################################################################################
//
// Section 2. Define the way the DC and/or CS lines are driven (ESP8266 only)
//
// ##################################################################################

// Normally the library uses direct register access for the DC and CS lines for speed
// If D0 (GPIO16) is used for CS or DC then a different slower method must be used
// Uncomment one line if D0 is used for DC or CS
// DC on D0 = 6% performance penalty at 40MHz SPI running graphics test
// CS on D0 = 2% performance penalty at 40MHz SPI running graphics test

// #define D0_USED_FOR_DC
// #define D0_USED_FOR_CS

// ##################################################################################
//
// Section 3. Define the fonts that are to be used here
//
// ##################################################################################

// Comment out the following #define if "SPI Transactions" do not need to be
// supported. When commented out the code size will be smaller and sketches will
// run slightly faster, so leave it commented out unless you need it!

// Transaction support is needed to work with SD library but not needed with TFT_SdFat
// Transaction support is required if other SPI devices are connected.

// Transactions are automatically enabled by the library for an ESP32 (to use HAL mutex)
// so changing it here has no effect

// #define SUPPORT_TRANSACTIONS

#endif /* SETUP_ILI9163_H */
