
// 4.-Knight Rider
#define LEDS 10
#define TIMER 500

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

