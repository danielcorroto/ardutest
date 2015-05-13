#include <IRremote.h>
#include <IRremoteInt.h>

// Pins
#define PIN_SENSOR 3
#define PIN_LED_R 8
#define PIN_LED_G 7
#define PIN_LED_B 6
// Config
#define DELAY 500
// Buttons
#define BUTTON_R 3672802284
#define BUTTON_G 732942060
#define BUTTON_B 1906441864


IRrecv irreceiver(PIN_SENSOR);
decode_results results;

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  
  irreceiver.enableIRIn();
}

// led pins
int leds[] = {PIN_LED_R, PIN_LED_G, PIN_LED_B};
// led status R, G, B
int led_status[] = {0, 0, 0};
// samsung red button, green button, blue button
unsigned long ir_value[] = {BUTTON_R, BUTTON_G, BUTTON_B};

void loop() {
  if (irreceiver.decode(&results)) {
    Serial.println(results.value);
    // find key pressed
    for (int i=0; i<sizeof(ir_value)/sizeof(ir_value[0]); i++) {
      if (results.value == ir_value[i]) {
        // update light
        if (led_status[i] == 0) {
          digitalWrite(leds[i], HIGH);
        } else {
          digitalWrite(leds[i], LOW);
        }
        // update value
        led_status[i] = 1 - led_status[i];
      }
    }
    
    irreceiver.resume();
  }
  delay(DELAY);
}
