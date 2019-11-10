//  30005;    DUST        byte 8 + 16; 
typedef struct packet30005{
float      Conc25;   
float      Conc10;
float      UMID;    
float      TEMP;    
};

//  these declarations must not be changed
 typedef union pluto {
  packet30005 Data30005;            //  Dataxxxxx is the name of the structure to be joined to bufVar
  byte bufVar[MXVAR];               //  array of bytes to be joined with the structure
};
pluto minni;                       //  minni is the name of the union type pluto
