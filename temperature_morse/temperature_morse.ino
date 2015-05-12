#define PIN_TEMP 0
#define PIN_LED 13

const int LENGTH_DOT = 70;
const int LENGTH_DASH = LENGTH_DOT * 3;

const int WAIT_SIMBOL = LENGTH_DOT;
const int WAIT_LETTER = LENGTH_DOT * 3;
const int WAIT_WORD = LENGTH_DASH * 3;

// Morse 0-9
char *m[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  int temp = analogRead(PIN_TEMP);
  temp =  5.0 * temp * 100.0 / 1024.0;
  
  Serial.println(temp);
  delay(1000);
  morseTemp(temp);
  delay(1000);
}

/**
* Temperature > 0
*/
void morseTemp(int temp) {
  if (temp > 0) {
    morseTemp(temp/10);
  }
  if (temp != 0) {
    morse(m[temp%10]);
  }
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
