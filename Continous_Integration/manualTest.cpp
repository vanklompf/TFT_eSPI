#include <Arduino.h>
#include <TFT_eSPI.h>

static TFT_eSPI tft;

void setup(void)
{
  tft.init();
  tft.setTextFont(4);
}

void loop(void)
{
  for (uint8_t rot = 0; rot<4; rot++)
  {
    tft.setRotation(rot);
    tft.fillScreen(TFT_ORANGE);
    tft.setCursor(0, 0);
    tft.println("ABCDEFG");
    tft.println("123456");
    tft.println("ABCDEFG");
    tft.println("123456");
    tft.println("ABCDEFG");
    tft.println("123456");
    delay(1000);
  }
	
  for(int32_t x=0; x<128; x++)
  {
      tft.drawFastVLine(x, 0, 128, ILI9163_BLUE);
      delay(7);
  }
  
  for(int32_t x=0; x<128; x++)
  {
      tft.drawFastHLine(0, x, 128, ILI9163_RED);
      delay(7);
  }
}
