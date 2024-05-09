#include <Arduino.h>

#include "morse_map.hpp"
#include "Display.hpp"

// O pino que le o fotorresistor
#define LED_INPUT 35

// Os pinos do display e do botão de reset
#define TFT_DC 32
#define TFT_CS 5
#define reset 2

// Durações mínimas do traço e do espaço
#define DASH_DUR 240
#define SPACE_DUR 560

Display *tft;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_INPUT, INPUT);
  pinMode(reset, INPUT_PULLUP);

  //Construção de um instância da classe Display
  tft = new Display(TFT_CS, TFT_DC);

  //Constrói a tela principal do Display
  tft->main_screen();
}

void loop()
{
  // A ideia é, assim que o input for 1, manter a contagem de quanto tempo ele fica em 1
  // e adicionar em uma string um traço ou um ponto a depender desse tempo. Esse processo é repetido
  // enquanto o tempo que o input fica em 0 for menor que a duração do espaço e, então, essa string
  // é associada a um caractere por meio do mapa de morse_map.hpp e esse caractere é colocado no display.

  if (digitalRead(LED_INPUT) == 1)
  {
    String morse_letter = "";
    while (1)
    {
      uint32_t start_1 = millis();
      while (digitalRead(LED_INPUT) == 1);
      uint32_t end_1 = millis();

      if (end_1 - start_1 < DASH_DUR) morse_letter += '.';
      else morse_letter += '-';

      uint32_t start_0 = millis();
      while (digitalRead(LED_INPUT) == 0 && millis() - start_0 < SPACE_DUR);
      uint32_t end_0 = millis();

      if (end_0 - start_0 >= SPACE_DUR) break;
      else continue;
    }

    std::map<String, char>::const_iterator iter = morse_to_ascii.find(morse_letter);
    if (iter != morse_to_ascii.end())
    {
      Serial.println(iter->second);
      tft->write_character(iter->second);
    }
  }
  
  if (!digitalRead(reset)) tft->reset_display();
}
