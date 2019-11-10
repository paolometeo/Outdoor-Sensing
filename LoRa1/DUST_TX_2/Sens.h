//  put here libraries needed for sensors and global variables other than in Packet..

  //  SDS011
#define PIN25  3     // PWM input from pin 2 of SDS011
#define PIN10  2     // PWM input from pin 4 of SDS011
#define PINpower 5   //  it provides power to SDS011 by means the Gate pin of the MOSFET (LOW = acceso)
#define PINLED  A0   //  it provides power to the LED

//  DHT22

#include "DHT.h"
#define PINdata 6       // DHT22 data pin
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
 DHT  dht(PINdata,DHTTYPE) ; // Creats a DHT object
//
word ncicli =    0;
word ncicliMax = 1;
word ID_TX = 30005;
word Length = 24;  // payload Length
