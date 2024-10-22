#include <SPI.h>
#include <Wire.h>
#include <RH_RF95.h>

/*  
// Uncomment if you need to transmit data to the ESP8266 
#include <SoftwareSerial.h>
#define RxPin  6
#define TxPin  5
SoftwareSerial mySerial1(RxPin, TxPin); //RX (blu), TX(verde)   verso ESP8266 
*/

#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//  for ProMicro
#define RFM95_CS   10
#define RFM95_RST   4
#define RFM95_INT   7
#define MXbuf      50
#define MXVAR      50

// Change to 434.0 or other frequency, must match RX's freq!
#define RF95_FREQ 868.0

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

// Blinky on receipt
#define LEDpin 17

byte  len     = 0;  
float nRSSI   = 0;
word  ID_TX   = 0;
word  npacket = 0;
word  vBatTX  = 0;
word  Length  = 0;
byte  buf[MXbuf];
word  i = 0;
