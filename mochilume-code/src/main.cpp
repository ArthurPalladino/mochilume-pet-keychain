#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include <SPI.h>


#define TFT_RES  4    //TFT_RES
#define TFT_CS   5    //TFT_CS
#define TFT_DC   15   //TFT_A0
#define TFT_MOSI 23   //TFT_SDA
#define TFT_SCLK 18   //TFT_SCK
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 240
#define FPS 60

Adafruit_GC9A01A screen(TFT_CS, TFT_DC);

int y = 0;

void setup() {
  Serial.begin(115200);
  screen.begin();
  screen.fillScreen(GC9A01A_BLACK);

}

void loop() {
  int oldY = y;
  y += 9.81;
  if (y>=240+55)
  {
    y=0;
  }
  screen.fillRect(100,oldY,50,55,GC9A01A_BLACK);
  screen.fillRect(100,y,50,55,GC9A01A_RED);
  delay(100);
}
