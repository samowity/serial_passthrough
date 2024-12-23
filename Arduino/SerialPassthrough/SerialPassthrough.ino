/* 
Based on "Adafruit TinyUSB Library/CDC/cdc multi" example.

Tested on:
- Seeed Studio XIAO SAMD21
- Seeed Studio XIAO RP2040

*/

#include <Adafruit_TinyUSB.h>

Adafruit_USBD_CDC Serial_CDC;
int ch;

void setup() {

  Serial.begin(1); // CDC serial ports ignores baudrate.

  if ( CFG_TUD_CDC < 2 ) {
    while(1) {
      Serial.printf("CFG_TUD_CDC must be at least 2, current value is %u\n", CFG_TUD_CDC);
      Serial.println("  Config file is located in Adafruit_TinyUSB_Arduino/src/arduino/ports/{platform}/tusb_config_{platform}.h");
      Serial.println("  where platform is one of: nrf, rp2040, samd");
      delay(1000);
    }
  }

  Serial_CDC.begin(1); // CDC serial ports ignores baudrate.

  while (!Serial || !Serial_CDC) {
    delay(100);
  }

}

void loop() {
  if (Serial.available() > 0) {
    ch = Serial.read();
    Serial_CDC.write(ch);
  }
  if (Serial_CDC.available() > 0) {
    ch = Serial_CDC.read();
    Serial.write(ch);
  }
}
