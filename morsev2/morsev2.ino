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
  char *m[] = { ".-", "-...", "-.-.-", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
  "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
  char s[] = "gol";
  for (int i=0; i<sizeof(s); i++) {
    if (s[i]>='a' && s[i]<='z') {
      morse( m[s[i]-97] );
    }
  }
  wordWait();
}

// MORSE
void morse(char t[]) {
  for (int i=0; i<strlen(t); i++) {
    if (t[i] == '.') {
      dot();
    } else if (t[i] == '-') {
      dash();
    }
  }
  letterWait();
}

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
