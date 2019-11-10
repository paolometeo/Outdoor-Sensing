#include <SPI.h>
#include <RH_RF95.h>
#include "Adafruit_SleepyDog.h"

/* for feather32u4 */
#define RFM95_CS  8
#define RFM95_RST 4
#define RFM95_INT 7

//  Pin where you can measure the battery power divided by 2
#define VBATPIN    A9
#define RF95_FREQ  868.0
#define RF95_POW   23

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

#define MXVAR  50
int   i  = 0;
word       ID_TX;
word       Length;
word       vBatTX;
word       npacket;
byte       buf[255];
