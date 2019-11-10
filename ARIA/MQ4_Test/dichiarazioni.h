float ppmCH4 = 0;
float R0_CH4 = 0;
byte  airFlag = false;   // if true, compute the value of R0 in air (background concentration of CH4 and NO2) for all the sensors

byte  pinMQ4  = A0;
int   nSample = 30;
