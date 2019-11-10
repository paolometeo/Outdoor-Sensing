//  put here libraries needed for sensors and global variables other than in Packet..  
#define         LedPin   6
#define         SoundPin 5
#define         CountPin 2  // interrupt pin
word            ID_TX         = 43998;
word            Length        = 14;  // payload Length
volatile word   n;
float           CPM           = 0;
long            timePassedLog = 0;
long            tempoOldLog   = 0;

// conversion factor from cpm to uSv/h for SBM20 and LND712 tubes
//  from
//  https://www.cooking-hacks.com/documentation/tutorials/geiger-counter-radiation-sensor-board-arduino-raspberry-pi-tutorial#cpm_to_servants
float          CF_SBM20      = 0.0057;  
float          CF_LND712     = 0.01;  
float          CF            = CF_SBM20;   //  SBM20 tube

float          uSv_h = 0;
long          period1 = 5000;   // short period
long          period2 = 30000;  // long period
long          period = 0;
float          CPM1 = 100;  // cpm threshold
