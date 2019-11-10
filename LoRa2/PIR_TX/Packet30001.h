//  PIR Sensor  30001;           Total byte: 8 + 1; 
typedef struct packet30001{
byte      PIRstatus;   
};

 typedef union pluto {
  packet30001 Data30001;            //  Dataxxxxx is the name of the structure to be joined to bufVar
  byte bufVar[MXVAR];               //  array of bytes to be joined with the structure
};
pluto minni;                       //  minni is the name of the union type pluto
