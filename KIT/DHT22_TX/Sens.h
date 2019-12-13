//  put here libraries needed for sensors and global variables other than in Packet..

//  DHT22

#include "DHT.h"
#define PINdata 6       // DHT22 data pin
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
 DHT  dht(PINdata,DHTTYPE) ; // Creats a DHT object
//
word ncicli =    0;
word ncicliMax = 1;
word ID_TX = 30003;
word Length = 16;  // payload Length
