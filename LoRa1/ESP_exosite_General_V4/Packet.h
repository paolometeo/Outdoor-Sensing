//  packets to be received

// 43998  Geiger  byte 8 + 6
typedef struct packet43998{
float          uSvh;   //microSv/h
uint16_t       countPeriod;
};

// 17899 TurbiTube1  byte 8 + 2
typedef struct packet17899{
uint16_t       Value;   
};

//  PIR Sensor  30001;           Total byte: 8 + 1; 
typedef struct packet30001{
uint8_t      PIRstatus;   
};

//  Vibration packet  30002   Total byte 8 + 4
typedef struct packet30002{
uint16_t       npulse;   //  number of pulses
uint16_t       sPeriod;  //  time interval in seconds in which it counts pulses
};

//  30003;    Temperature and Humidity SHT21        byte 8 + 8; 
typedef struct packet30003{
float      Temp;   
float      Humi;
};

//  30004;    Sonar SR04        byte 8 + 8; 
typedef struct packet30004{
float      Dist;  
long       Duration; 
};
//  30005;    DUST        byte 8 + 16; 
typedef struct packet30005{
float      Conc25;   
float      Conc10;
float      UMID;    
float      TEMP;    
};
typedef union pluto {
  packet30001 Data30001;            //  Data is the name of the structure to be joined to bufferS
  packet30002 Data30002;
  packet30003 Data30003;
  packet30004 Data30004;
  packet30005 Data30005;
  packet17899 Data17899;
  packet43998 Data43998;
  byte bufVar[MXVAR];   //  array of bytes to be joined with the structure
};
pluto minni;     
