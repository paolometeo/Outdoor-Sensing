#include <Wire.h>
#include <RH_RF95.h>

//  only for OLED display
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define MXbuf      50
#define MXVAR      50
#define RFM95_RST   4

//  for ProMicro
#define RFM95_CS   10
#define RFM95_INT   7
#define VBATPIN    A9
#define LEDpin     17   //  for blinking

/*
//  for TTGO
#define RFM95_CS   10
#define RFM95_INT   2  
#define VBATPIN    A0
#define LEDpin      8   //  for blinking

//  for Feather 32u4
#define RFM95_CS  8
#define RFM95_INT 7
#define VBATPIN   A9  
#define LEDpin    13   //  for blinking
*/

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);


byte      Roger   = 0;
byte      len     = 0;  
uint16_t  ID_TX   = 0;       //  TX ID received from message header
uint16_t  Length  = 0;       //  message Length from TX header
uint16_t  npacket = 0;       //  message number from TX header
uint16_t  vBatTX  = 0;      //   Battery voltage from TX header
uint16_t  nRSSI   = 0;      //  received RSSI
byte      buf[MXbuf];
int i = 0;
