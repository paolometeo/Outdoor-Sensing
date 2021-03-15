//  packets to be received
uint16_t ID1 = 30002;
uint16_t ID2 = 30003;

//  30002;    Vibration Sensor        byte 8 + 4; 
typedef struct packet30002{
uint16_t       npulse;   //  number of pulses
uint16_t       sPeriod;  //  time interval in seconds in which it counts pulses
};

//  30003;    DHT22        byte 8 + 8; 
typedef struct packet30003{
float      Temp;    
float      Humi;    
};

typedef union pluto {
  packet30002 Data30002;            //  Data is the name of the structure to be joined to bufferS
  packet30003 Data30003;            //  Data is the name of the structure to be joined to bufferS
  byte bufVar[MXVAR];   //  array of bytes to be joined with the structure
};
pluto minni;     
//
AdafruitIO_Feed *npulse = io.feed("npulse");
AdafruitIO_Feed *sPeriod = io.feed("sPeriod");
AdafruitIO_Feed *Temp = io.feed("Temp");
AdafruitIO_Feed *Humi = io.feed("Humi");
