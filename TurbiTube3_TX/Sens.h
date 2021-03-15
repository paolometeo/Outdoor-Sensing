  #define OEpin    3
  #define OUTpin   6
  #define Gatepin  5
  word  RatioOld =     0;
  word  diffRatio =    0;
  float threshold_Trans = 2;
  
/*  For TSL230 sensor and LED */
uint16_t   TSL230_samples = 10; // can be higher for more stability and accuracy but slower
