/*
7 segments
 -     a
| |   f b
 -     g
| |   e c
 - .   d P
*/

#define MICRO_DELAY 4000

# define LED_A 5
# define LED_B 7
# define LED_C 11
# define LED_D 9
# define LED_E 8
# define LED_F 6
# define LED_G 12
# define LED_P 10

# define DIGIT_1 1
# define DIGIT_2 2
# define DIGIT_3 3
# define DIGIT_4 4

#define PIN_TEMP 0

#define TEMP_SIZE 120

int DIGITS[] = {0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4};
int LEDS[] = {LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, LED_P};

int count = 0;
int temp[TEMP_SIZE] = {0};

void setup() {
  pinMode(LED_A,OUTPUT);
  pinMode(LED_B,OUTPUT);
  pinMode(LED_C,OUTPUT);
  pinMode(LED_D,OUTPUT);
  pinMode(LED_E,OUTPUT);
  pinMode(LED_F,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_P,OUTPUT);
  pinMode(DIGIT_1,OUTPUT);
  pinMode(DIGIT_2,OUTPUT);
  pinMode(DIGIT_3,OUTPUT);
  pinMode(DIGIT_4,OUTPUT);
  
  // Setea la temperatura inicial
  getTemp();
  for (int i=1; i<TEMP_SIZE; i++) {
    temp[i] = temp[0];
  }
  printTemperature();
}

void loop() {
  getTemp();
  printTemperature();
  
  if (count >= TEMP_SIZE-1) {
    count = 0;
  } else {
    count++;
  }
}

void getTemp() {
  float actual = analogRead(PIN_TEMP);
  actual = 5.0 * actual * 100.0 / 1024.0;
  
  temp[count] = actual;
}

int printTemperature() {
  int t = 0;
  for (int i=0; i<TEMP_SIZE; i++) {
    t += temp[i];
  }
  
  t = t / TEMP_SIZE;
  
  // Temperatura negativa
  if (t < 0) {
    writeDigit(DIGITS[1], 0x40);
    t = -t;
  } else if (t >= 100) {
    writeDigit(DIGITS[1], getNumber(t/100%10));
  } else {
    writeDigit(DIGITS[1], 0);
  }
  delayMicroseconds(MICRO_DELAY);
  writeDigit(DIGITS[2],getNumber(t/10%10));
  delayMicroseconds(MICRO_DELAY);
  writeDigit(DIGITS[3],getNumber((int)t%10));
  delayMicroseconds(MICRO_DELAY);
  writeDigit(DIGITS[4],0x63);
  delayMicroseconds(MICRO_DELAY);
}

/**
 * Transofrma un char en un número (8bits) para pintar en el 7-segment
 * BIT      7 6 5 4 3 2 1 0
 * SEGMENTO P G F E D C B A
 */
int getNumber(int number) {
  switch (number) {
    case 0: return 0x3f;
    case 1: return 0x06;
    case 2: return 0x5b;
    case 3: return 0x4f;
    case 4: return 0x66;
    case 5: return 0x6d;
    case 6: return 0x7d;
    case 7: return 0x07;
    case 8: return 0x7f;
    case 9: return 0x6f;
    
    
    case 'º': return 0x63;
    case '-': return 0x40;
    default: return 0;
  }
}

/**
 * Escribe el dígito indicado en el 7-segment
 * digit: indica el dígito (1-4 -> de izquierda a derecha)
 * x: indica los segmentos a escribir, de igual forma que en ¡getLetter
 */
void writeDigit(int digit, int x) {
  for (int i=1; i<=4; i++) {
    digitalWrite(DIGITS[i], HIGH);
  }
  digitalWrite(DIGITS[digit], LOW);
  
  for (int i=0; i<8; i++) {
    digitalWrite(LEDS[i], (x >> i) & 0x1);
  }
}

