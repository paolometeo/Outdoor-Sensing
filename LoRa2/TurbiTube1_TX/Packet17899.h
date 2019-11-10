// 17899 TurbiTube1  byte 8 + 2
///////////  variables to be transmitted////////////////////
typedef struct packet17899{
uint16_t       Value;   
};
 typedef union pluto {
  packet17899 Data17899;           
  byte bufVar[MXVAR];   
};
pluto minni;                
