#include <SPI.h>
#include <RH_RF95.h>
#include "Adafruit_SleepyDog.h"

//  for ProMicro
#define RFM95_CS   10
#define RFM95_RST   4
#define RFM95_INT   7

//  Pin where you can measure the battery power divided by 2
#define VBATPIN    A0
#define RF95_FREQ  868.0
#define RF95_POW   23
#define RXLED      17   //  for blinking

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

#define MXVAR  50
int   i  = 0;
word       vBatTX;
word       npacket;
byte       buf[255];
