  #define OEpin    3
  #define OUTpin   4
  #define Gatepin  5
/*  For TSL230 sensor and LED */
int   TSL230_samples = 20; // can be higher for more stability and accuracy but slower
float Ratio = 0;
float lightLevel1=0;
float lightLevel2=0;
int   samples = 10;
float Period = 5000;
float TimePassed = 0;
float TimeOld = 0;
