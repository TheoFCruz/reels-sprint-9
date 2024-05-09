#include "Display.hpp"

Display::Display(int tft_CS, int tft_DC) {
  _tft.begin();
  _tft.setTextColor(ILI9341_WHITE);
  _tft.setTextSize(2);
  _tft.setRotation(1);
  _tft.fillScreen(ILI9341_BLACK);
}

void Display::main_screen() {
  _tft.setCursor(0, 0);
  _tft.setTextSize(2);
  _tft.println("\n\n");
  _tft.print("  Palavra decodificada:");
  _tft.setTextSize(3);
  _tft.println("\n\n\n");
  _tft.print("  ");
}

void Display::write_character(char character) {
  _tft.print(character);
}

void Display::reset_display() {
  _tft.fillRect(0, 80, 400, 300, ILI9341_BLACK);
  this->main_screen();
}
