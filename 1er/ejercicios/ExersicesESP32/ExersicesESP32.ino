// 2.- Shifting MSB -> LSB
  #define LEDS 10
  #define TIMER 1000

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

// 3.- Shifting MSB <- LSB
  #define LEDS 10
  #define TIMER 1000

  int leds[LEDS] = {21, 19, 18, 15, 14, 13, 12, 5, 4, 2};

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

// 4.-Knight Rider
#define LEDS 10
#define TIMER 1000

int leds[LEDS] = {2, 4, 5, 12, 13, 14, 15, 18, 19, 21};
int direction = 1;  // 1 para mover hacia adelante, -1 para mover hacia atrás
int position = 0;   // Posición actual

void setup() {
  for (int i = 0; i < LEDS; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  // Apagar todos los LEDs
  for (int i = 0; i < LEDS; i++) {
    digitalWrite(leds[i], LOW);
  }

  // Encender el LED actual y los dos LEDs a sus lados
  for (int j = -1; j <= 1; j++) {
    int ledIndex = (position + j + LEDS) % LEDS;
    digitalWrite(leds[ledIndex], HIGH);
  }

  delay(TIMER);

  // Cambiar la posición
  position += direction;

  // Invertir la dirección al llegar a los extremos
  if (position == 0 || position == LEDS - 1) {
    direction = -direction;
  }
}


// 5.- Loading MSB -> LSB
    #define LEDS 10
    #define TIMER 200

    int leds[LEDS] = {2, 4, 5, 12, 13, 14, 15, 18, 19, 21}; 

    void setup() {
      for (int i = 0; i < LEDS; i++) {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW);   
      }
    }

    void loop() {
      for (int i = 0; i <= LEDS; i++) {
        digitalWrite(leds[i], HIGH); 
        delay (TIMER);  // delayMicrosenconds 
      }
    }


// 6.- Empting MSB <- LSB
#define LEDS 10
#define TIMER 200

int leds[LEDS] = {2, 4, 5, 12, 13, 14, 15, 18, 19, 21}; 

void setup() {
  for (int i = 0; i < LEDS; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);   
  }
}

void loop() {
  for (int i = 10; i <= LEDS; i--) {
    digitalWrite(leds[i], LOW); 
    delay (TIMER);  // delayMicrosenconds 
  }
}


