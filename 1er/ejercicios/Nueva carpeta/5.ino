
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

