#include "funshield.h"

int led_state = 0;
unsigned long last_flip = 0;
int period = 100;


struct Led {
  int pin;
  Led(int p) {
    pin = p;
  }
  void init () {
    pinMode(pin, OUTPUT);
  }

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

Led leds[] = { LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN };

int gray(int ledState) {
  return ledState ^ (ledState >> 1);
}

#if PUVODNI_VERZE
void setLed(int i, bool state){
  digitalWrite(pins[i], state ? ON : OFF);
}
#endif

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    leds[i].init();
    leds[i].off();
  }
  last_flip = millis();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (last_flip + period < millis()) {
    led_state++;
    if (led_state >= 16) led_state = 0;
    int led_state_gray = gray(led_state);
    for (int i = 0; i < 4; i++) {
      leds[i].set(led_state_gray & (1 << i));
    }
    last_flip += period;
  }
}
