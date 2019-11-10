//  30003;    Temperature and Humidity SHT21        byte 8 + 8; 
typedef struct packet30003{
float      Temp;   
float      Humi;
};

//  these declarations must not be changed
 typedef union pluto {
  packet30003 Data30003;            
  byte bufVar[MXVAR];               
};
pluto minni;                       
