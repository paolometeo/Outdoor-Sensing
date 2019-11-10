// TurbiTube1
///////////  variables to be transmitted////////////////////
typedef struct packet17899{
word       Value;   
};
 typedef union pluto {
  packet17899 Data17899;            //  myData is the name of the structure to be joined to bufferS
  byte bufVar[MXVAR];   //  array of bytes to be joined with the structure
};
pluto minni;                //  minni is the name of the union type pluto
