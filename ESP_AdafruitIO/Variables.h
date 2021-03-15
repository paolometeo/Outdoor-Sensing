#define MXbuf 50
#define MXVAR 50
#define RXpin   0  //      Quando si usa la Wemos: D5,  oppure 0 con la Sparkfun ESP8266
#define TXpin   4 //       Quando si usa la Wemos: D0,  oppure 4 con la Sparkfun ESP8266
uint16_t    ID_TX   = 0;
uint16_t    npacket = 0;
uint16_t    vBatTX  = 0;
uint16_t    Length  = 0;
uint16_t    i =     0;
uint16_t    nbyte = 0;
uint16_t    nbyteRec = 0;
uint8_t     flag =  0;
uint8_t     flagEnd =  0;
uint8_t     err = 0;
uint8_t     buf[MXbuf];
uint8_t     primo = 0;
