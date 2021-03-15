/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME   "xxxxxx"
#define IO_KEY        "xxxxxx"

/******************************* WIFI **************************************/
// Cascinet
#define WIFI_SSID   "xxxxx"
#define WIFI_PASS   "xxxxx"


// comment out the following lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
