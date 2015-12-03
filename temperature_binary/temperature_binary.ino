#define PIN_TEMP 0

#define PIN_LED2_0 5
#define PIN_LED2_1 6
#define PIN_LED2_2 7
#define PIN_LED2_3 8
#define PIN_LED2_4 9

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED2_0, OUTPUT);
  pinMode(PIN_LED2_1, OUTPUT);
  pinMode(PIN_LED2_2, OUTPUT);
  pinMode(PIN_LED2_3, OUTPUT);
  pinMode(PIN_LED2_4, OUTPUT);
}

void loop() {
  int temp = analogRead(PIN_TEMP);
  temp =  5.0 * temp * 100.0 / 1024.0;
  Serial.println(temp);
  
  digitalWrite(PIN_LED2_0, temp>>0&0x1);
  digitalWrite(PIN_LED2_1, temp>>1&0x1);
  digitalWrite(PIN_LED2_2, temp>>2&0x1);
  digitalWrite(PIN_LED2_3, temp>>3&0x1);
  digitalWrite(PIN_LED2_4, temp>>4&0x1);
  
  delay(1000);
}
