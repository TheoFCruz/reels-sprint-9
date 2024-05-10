#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "TFT_ILI9163C.h"
#include "Adafruit_GFX.h"

class Display{
public:
	/// @brief Inicializa o display
	Display(int tft_CS, int tft_DC);

	/// @brief Tela principal
	void main_screen();

  /// @brief Escreve um caractere no Display
  void write_character(char character);

  /// @brief Limpa o Display
  void reset_display();

private:
	TFT_ILI9163C _tft;
};

#endif //DISPLAY_HPP
