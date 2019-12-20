//  30003;    DHT22        byte 8 + 8; 
typedef struct packet30003{
float      Temp;    
float      Humi;    
};

//  30004;    Sonar SR04        byte 8 + 8; 
typedef struct packet30004{
float      Dist;  
long       Duration; 
};

typedef union pluto {
  packet30003 Data30003;
  packet30004 Data30004;
  byte bufVar[MXVAR];   //  array of bytes to be joined with the structure
};
pluto minni;     
