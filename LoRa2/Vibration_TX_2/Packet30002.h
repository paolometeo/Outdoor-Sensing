//  Vibration packet  30002   Total byte 8 + 4
typedef struct packet30002{

uint16_t       npulse;   //  number of pulses
uint16_t       sPeriod;  //  time interval in seconds in which it counts pulses
};
 typedef union pluto {
  packet30002 Data30002;     //  myData is the name of the structure to be joined to bufferS
  byte bufVar[MXVAR];          //  array of bytes to be joined with the structure
};
pluto minni;                //  minni is the name of the union type pluto
