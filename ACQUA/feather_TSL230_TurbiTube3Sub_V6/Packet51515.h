typedef struct packet51515{

word       Level1;   //  number of pulses
word       Level2;  //  time interval in seconds in which it counts pulses
float      Ratio;
};
 typedef union pluto {
  packet51515 Data51515;
  byte bufVar[MXVAR];   //  array of bytes to be joined with the structure
};
pluto minni;     
