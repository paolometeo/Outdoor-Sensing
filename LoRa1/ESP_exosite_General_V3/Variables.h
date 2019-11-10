#define MXbuf 50
#define MXVAR 50
#define RXpin   0  // 5
#define TXpin   4  // 0
uint16_t    ID_TX   = 0;
uint16_t    npacket = 0;
uint16_t    vBatTX  = 0;
uint16_t    Length  = 0;
byte    buf[MXbuf];
String  TotalString = " ";  // String to be sent to the exosite portal
String  readString = " ";  // String needed to ask the portal
String  returnString;      // String issued by the portal
uint8_t    buono = 0;
byte       primo = 0;
uint16_t   i =     0;
uint16_t   ii =     0;
uint16_t   nbyte = 0;
uint8_t    flag =  0;
