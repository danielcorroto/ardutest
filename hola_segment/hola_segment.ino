/*
7 segments
 -     a
| |   f b
 -     g
| |   e c
 - .   d P
*/

#define MICRO_DELAY 3000

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

int DIGITS[] = {0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4};
int LEDS[] = {LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, LED_P};

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
}

void loop() {
  char *c = "hola";
  for (int i=0; i<4; i++) {
    writeDigit(DIGITS[i+1],getLetter(c[i]));
    delayMicroseconds(MICRO_DELAY);
  }
}

/**
 * Transofrma un char en un número (8bits) para pintar en el 7-segment
 * BIT      7 6 5 4 3 2 1 0
 * SEGMENTO P G F E D C B A
 */
int getLetter(char letter) {
  switch (letter) {
    case '0': return 0x3f;
    case '1': return 0x06;
    case '2': return 0x5b;
    case '3': return 0x4f;
    case '4': return 0x66;
    case '5': return 0x6d;
    case '6': return 0x7d;
    case '7': return 0x07;
    case '8': return 0x7f;
    case '9': return 0x6f;
    
    case 'a': return 0x77;
    case 'b': return 0x7c;
    case 'c': return 0x39;
    case 'd': return 0x5e;
    case 'e': return 0x79;
    case 'f': return 0x71;
    case 'g': return 0x6f;
    case 'h': return 0x76;
    case 'i': return 0x30;
    case 'j': return 0x1e;
    case 'k': return 0x76;
    case 'l': return 0x38;
    case 'm': return 0x15;
    case 'n': return 0x54;
    case 'o': return 0x3f;
    case 'p': return 0x73;
    case 'q': return 0x67;
    case 'r': return 0x50;
    case 's': return 0x6d;
    case 't': return 0x78;
    case 'u': return 0x3e;
    case 'v': return 0x1c;
    case 'w': return 0x2a;
    case 'x': return 0x76;
    case 'y': return 0x6e;
    case 'z': return 0x5b;
    
    case 'º': return 0x63;
    case '-': return 0x40;
    case '_': return 0x08;
    case '.': return 0x80;
    case '!': return 0x86;
    case '=': return 0x48;
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

