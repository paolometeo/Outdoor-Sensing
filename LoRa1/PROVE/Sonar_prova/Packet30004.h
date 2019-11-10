//  30003;    Temperature and Humidity SHT21        byte 8 + 8; 
typedef struct packet30004{
float      Dist;   
};

//  these declarations must not be changed
 typedef union pluto {
  packet30004 Data30004;            //  Data12122 is the name of the structure to be joined to bufVar
  byte bufVar[MXVAR];               //  array of bytes to be joined with the structure
};
pluto minni;                       //  minni is the name of the union type pluto
