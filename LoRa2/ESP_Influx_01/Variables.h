#define MXbuf 50
#define MXVAR 50
#define RXpin   5
#define TXpin   0

#define INFLUXDB_HOST "influxdb.panu.it"
#define INFLUXDB_DB "wemake"
#define INFLUXDB_ROW "lettura"
//#define INFLUXDB_OBJECT "sensore"
#define INFLUXDB_USER "wemake"
#define INFLUXDB_PASS "topolino28"
#define WIFI_SSID "WeMake00"
#define WIFI_PASS "wemakemilano!"

uint16_t    ID_TX   = 0;
uint16_t    npacket = 0;
uint16_t    vBatTX  = 0;
uint16_t    Length  = 0;
byte    buf[MXbuf];
String  TotalString = " ";  // String to be sent to the exosite portal
String  InfluxSensor;
String  InfluxTemperature;
String  InfluxVBat;
String  readString = " ";  // String needed to ask the portal
String  returnString;      // String issued by the portal
uint8_t    buono = 0;
uint8_t    primo = 0;
uint8_t    val =   0;
uint16_t   i =     0;
uint16_t   ii =     0;
uint16_t   nbyte = 0;
uint8_t    flag =  0;
