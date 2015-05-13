#define LED_R 4
#define LED_G 3
#define LED_B 2

#define DELAY 500

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

int leds[] = {LED_R, LED_G, LED_B};
int i = 0;

void loop() {
  digitalWrite(leds[i], LOW);
  digitalWrite(leds[(i+1)%3], HIGH);
  i  =(i+1) % (sizeof(leds)/sizeof(leds[0]));
  delay(DELAY);
}

void replaceLed(int off, int on) {
  
}
