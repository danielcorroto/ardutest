#define PINTEMP 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = analogRead(PINTEMP);
  temp =  5.0 * temp * 100.0 / 1024.0; 
  Serial.println(temp);
  delay(1000);
}
