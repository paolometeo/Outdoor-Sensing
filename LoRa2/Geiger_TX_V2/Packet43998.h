//  43998;    Geiger        byte 8 + 6; 
typedef struct packet43998{
float          uSvh;   //microSv/h
uint16_t       countPeriod;
};

//  these declarations must not be changed
 typedef union pluto {
  packet43998 Data43998;            //  is the name of the structure to be joined to bufVar
  byte bufVar[MXVAR];               //  array of bytes to be joined with the structure
};
pluto minni;                       //  minni is the name of the union type pluto
