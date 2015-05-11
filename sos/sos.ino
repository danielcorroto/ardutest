void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  morseS();
  morseO();
  morseS();
  wait();
}

void morseO() {
  dash();
  dash();
  dash();
}

void morseS() {
  dot();
  dot();
  dot();
}

void dot() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}

void dash() {
  digitalWrite(13, HIGH);
  delay(400);
  digitalWrite(13, LOW);
  delay(100);
}

void wait() {
  delay(500);
}
