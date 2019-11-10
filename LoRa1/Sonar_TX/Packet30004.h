//  30004;    Sonar SR04        byte 8 + 8; 
typedef struct packet30004{
float      Dist;  
long       Duration; 
};

//  these declarations must not be changed
 typedef union pluto {
  packet30004 Data30004;            
  byte bufVar[MXVAR];               
};
pluto minni;                       
