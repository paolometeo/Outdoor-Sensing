//  16133;    ConducTube        byte 8 + 6; 
uint16_t ID_TX = 16133;
uint16_t Length = 14;

typedef struct packet16133{
uint16_t      WCS;    
uint16_t      WCSspec; 
uint16_t      WTemp;   
};

//  these declarations must not be changed
 typedef union pluto {
  packet16133 Data16133;            //  Dataxxxxx is the name of the structure to be joined to bufVar
  byte bufVar[MXVAR];               //  array of bytes to be joined with the structure
};
pluto minni;                       //  minni is the name of the union type pluto
