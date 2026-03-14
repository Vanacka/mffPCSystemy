#include "funshield.h"

struct Led {
  // tohle si pamatuje pin, ktery ma tahle `Led`ka pouzivat
  int pin;

  // konstruktor
  Led(int p) {
    pin = p;
  }

  // funkce na zavolani v setupu pro inicializaci
  void init() {
    pinMode(pin, OUTPUT);
  }

  // ovladani a zkratky
  void set(bool b) {
    digitalWrite(pin, b ? ON : OFF);
  }

  void on() {
    set(true);
  }

  void off() {
    set(false);
  }
};

// globalni promenne
int counter = 0;              // pocitadlo na stav
unsigned long last_flip = 0;  // cas v millis() kdy jsme udelali posledni flip
constexpr int period = 300;   // ocekavany cas na flip (v ms)
int direction = 1;            // aktualni smer blikani

Led leds[] = { LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN };

constexpr unsigned N_LEDS = sizeof(leds) / sizeof(*leds);
constexpr unsigned N_STATES = 1 << N_LEDS;


void setup() {
  for (unsigned int i = 0; i < N_LEDS; i++) {
    leds[i].init();
    leds[i].off();
  }
  last_flip = millis();
}

void loop() {
  if (last_flip + period < millis()) {
    // vypne stavajici ledku a zapne dalsi v poradi
    leds[counter].off();
    counter += direction;
    leds[counter].on();

    // prohodi smer rozsviceni ledek
    if (counter == 3 || counter == 0) {
      direction *= -1;
    }
    last_flip += period;
  }
}
