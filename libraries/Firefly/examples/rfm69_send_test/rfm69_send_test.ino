#include <RFM69.h>

const int kNodeId = 1;
const int kNetworkId = 137;
const int kLedPin = 0;

//SPIClass spi = SPIClass(&sercom0, /* MISO */, /* SCK */, /* MOSI */, /* TX
RFM69 radio = RFM69(SS, /* DIO */ 5, /* is HW */ false, /* SPIClass */ &SPI);

void setup() {
  pinMode(kLedPin, OUTPUT);

  digitalWrite(kLedPin, HIGH);
  delay(200);
  digitalWrite(kLedPin, LOW);
  delay(200);
  
  // put your setup code here, to run once:
  if (radio.initialize(RF69_868MHZ, kNodeId, kNetworkId)) {
    digitalWrite(kLedPin, HIGH);
    delay(100);
    digitalWrite(kLedPin, LOW);
    delay(100);
    digitalWrite(kLedPin, HIGH);
    delay(100);
    digitalWrite(kLedPin, LOW);
    delay(100);
  }
  radio.promiscuous(true);
}

const int kBufLen = 10;
char buf[kBufLen];

void loop() {
  radio.send(1, buf, kBufLen);
  // put your main code here, to run repeatedly:
  digitalWrite(kLedPin, HIGH);
  delay(100);
  digitalWrite(kLedPin, LOW);
  delay(500);
}
