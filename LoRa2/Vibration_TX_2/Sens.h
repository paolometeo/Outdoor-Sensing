#define  interruptPin  2  
volatile word n   = 0;
int   ncicli      = 0;
int   ncicliMax   = 3;
float Tempo       = 0;
float TimeOld     = 0;
float Period      = 3000;
word  ID_TX       = 30002;
word  Length      = 12;
