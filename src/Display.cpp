#include "Display.hpp"

#include "Adafruit_GFX.h"

Display::Display(int tft_CS, int tft_DC):
  _tft(tft_CS, tft_DC)
{
  _tft.begin();
  _tft.setTextColor(WHITE);
  _tft.setTextSize(1);
  _tft.setRotation(0);
  _tft.fillScreen(BLACK);
}

void Display::main_screen() {
  _tft.setCursor(0, 0);
  _tft.setTextSize(1);
  _tft.println("\n");
  _tft.print(" Palavra decodificada");
  _tft.setTextSize(1);
  _tft.println("\n\n");
  _tft.print("  ");
}

void Display::write_character(char character) {
  _tft.print(character);
}

void Display::reset_display() {
  _tft.fillRect(0, 30, 200, 200, BLACK);
  this->main_screen();
}

