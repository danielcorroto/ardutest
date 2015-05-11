// Configuration constants
#define PINLED 13

const int LENGTH_DOT = 70;
const int LENGTH_DASH = LENGTH_DOT * 3;

const int WAIT_SIMBOL = LENGTH_DOT;
const int WAIT_LETTER = LENGTH_DOT * 3;
const int WAIT_WORD = LENGTH_DASH * 3;

// Program

void setup() {
  pinMode(PINLED, OUTPUT);
}

void loop() {
  void (*morse[26])() = { morseA, morseB, morseC, morseD, morseE, morseF, morseG, morseH,
    morseI, morseJ,morseK, morseL, morseM, morseN, morseO, morseP, morseQ,
    morseR, morseS, morseT, morseU, morseV, morseW, morseX, morseY, morseZ };
  char s[] = "gol";
  for (int i=0; i<strlen(s); i++) {
    if (s[i]>='a' && s[i]<='z') {
      morse[ s[i]-97 ]();
    }
  }
  wordWait();
}

// LETTERS

void morseA() {
  dot();
  dash();
  letterWait();
}

void morseB() {
  dash();
  dot();
  dot();
  letterWait();
}

void morseC() {
  dash();
  dot();
  dash();
  dot();
  letterWait();
}

void morseD() {
  dash();
  dot();
  dot();
  letterWait();
}

void morseE() {
  dot();
  letterWait();
}

void morseF() {
  dot();
  dot();
  dash();
  dot();
  letterWait();
}

void morseG() {
  dash();
  dash();
  dot();
  letterWait();
}

void morseH() {
  dot();
  dot();
  dot();
  dot();
  letterWait();
}

void morseI() {
  dot();
  dot();
  letterWait();
}

void morseJ() {
  dot();
  dash();
  dash();
  dash();
  letterWait();
}

void morseK() {
  dash();
  dot();
  dash();
  letterWait();
}

void morseL() {
  dot();
  dash();
  dot();
  dot();
  letterWait();
}

void morseM() {
  dash();
  dash();
  letterWait();
}

void morseN() {
  dot();
  dash();
  letterWait();
}

void morseO() {
  dash();
  dash();
  dash();
  letterWait();
}

void morseP() {
  dot();
  dash();
  dash();
  dot();
  letterWait();
}

void morseQ() {
  dash();
  dash();
  dot();
  dash();
  letterWait();
}

void morseR() {
  dot();
  dash();
  dot();
  letterWait();
}

void morseS() {
  dot();
  dot();
  dot();
  letterWait();
}

void morseT() {
  dash();
  letterWait();
}

void morseU() {
  dot();
  dot();
  dash();
  letterWait();
}

void morseV() {
  dot();
  dot();
  dot();
  dash();
  letterWait();
}

void morseW() {
  dot();
  dash();
  dash();
  letterWait();
}

void morseX() {
  dash();
  dot();
  dot();
  dash();
  letterWait();
}

void morseY() {
  dash();
  dot();
  dash();
  dash();
  letterWait();
}

void morseZ() {
  dash();
  dash();
  dot();
  dot();
  letterWait();
}

// MORSE

void dot() {
  digitalWrite(13, HIGH);
  delay(LENGTH_DOT);
  digitalWrite(13, LOW);
  delay(WAIT_SIMBOL);
}

void dash() {
  digitalWrite(13, HIGH);
  delay(LENGTH_DASH);
  digitalWrite(13, LOW);
  delay(WAIT_SIMBOL);
}

void letterWait() {
  delay(WAIT_LETTER);  
}

void wordWait() {
  delay(WAIT_WORD);
}
