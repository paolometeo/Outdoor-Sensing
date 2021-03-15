// TurbiTube3  51515  byte 8+8
uint16_t ID_TX = 51515;
uint16_t Length = 16;
///////////  variables to be transmitted////////////////////
typedef struct packet51515{
uint16_t       Level1;   //  number of pulses
uint16_t       Level2;  //  time interval in seconds in which it counts pulses
float          Ratio;
};
 typedef union pluto {
  packet51515 Data51515;            //  myData is the name of the structure to be joined to bufferS
  byte bufVar[MXVAR];   //  array of bytes to be joined with the structure
};
pluto minni;                //  minni is the name of the union type pluto
