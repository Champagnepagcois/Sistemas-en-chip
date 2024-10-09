// 2.- Shifting MSB -> LSB
  #define LEDS 10
  #define TIMER 500

  int leds[LEDS] = {2, 4, 5, 12, 13, 14, 15, 18, 19, 21};

  void setup() {
    for (int i = 0; i < LEDS; i++) {
      pinMode(leds[i], OUTPUT);
      digitalWrite(leds[i], LOW);
    }
  }

  void loop() {
    for (int i = 0; i < LEDS; i++) {
      for (int j = 0; j < LEDS; j++) {
        digitalWrite(leds[j], LOW);
      }

      for (int j = 0; j < 3; j++) {
        int shiftedIndex = (i + j) % LEDS;
        digitalWrite(leds[shiftedIndex], HIGH);
      }
      delay(TIMER);
    }
  }
