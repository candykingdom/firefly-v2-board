#include <RFM69.h>
#include "FastLED.h"
#define NUM_LEDS 1
CRGB leds[NUM_LEDS];

const int kNodeId = 1;
const int kNetworkId = 137;
const int kLedPin = 0;

//SPIClass spi = SPIClass(&sercom0, /* MISO */, /* SCK */, /* MOSI */, /* TX */);
RFM69 radio = RFM69(SS, /* DIO */ 5, /* is HW */ false, /* SPIClass */ &SPI);

bool doFlash = false;
void flash() {
  doFlash = true;
}

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
  
  pinMode(kLedPin, OUTPUT);
  pinMode(5, INPUT);
  //attachInterrupt(5, flash, HIGH);

  /*digitalWrite(kLedPin, HIGH);
    delay(500);
    digitalWrite(kLedPin, LOW);
    delay(500);*/

  // put your setup code here, to run once:
  if (radio.initialize(RF69_868MHZ, kNodeId, kNetworkId)) {
    digitalWrite(kLedPin, HIGH);
    delay(200);
    digitalWrite(kLedPin, LOW);
    delay(200);
  }
  radio.promiscuous(true);

  //pinMode(5, INPUT_PULLUP);
  //attachInterrupt(5, flash, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.receiveDone() && radio.DATALEN > 0) {
    //radio.receiveDone();

    leds[0] = CHSV(random(360), 255, 100); FastLED.show();
    digitalWrite(kLedPin, HIGH);
    delay(100);
    digitalWrite(kLedPin, LOW);
    leds[0] = CRGB::Black; FastLED.show();
    delay(100);
  }

  if ((millis() % 5000) < 5) {
    digitalWrite(kLedPin, HIGH);
  } else {
    digitalWrite(kLedPin, LOW);
  }

  if (doFlash) {
    digitalWrite(kLedPin, HIGH);
    delay(100);
    digitalWrite(kLedPin, LOW);
    delay(100);
    digitalWrite(kLedPin, HIGH);
    delay(100);
    digitalWrite(kLedPin, LOW);
    delay(100);
    doFlash = false;
  }

  //delay(50);
  //digitalWrite(kLedPin, LOW);

  /*digitalWrite(kLedPin, HIGH);
  delay(1);
  digitalWrite(kLedPin, LOW);
  delay(2);*/
}
