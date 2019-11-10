/*
 * Test sketch for gas sensor MQ4 for CH4 
 * 
 * wiring
 * MQ4        Arduino      R-load 22Kohm
 *                                            
 * A                             X
 *               GND             X                X
 * B              A0                              X
 * J             +5V
 * H             +5V
 * 
 * Paolo Bonelli  08/02/2019
 * 
 */
#include "dichiarazioni.h"
////////////////////////////////////////////////////////////////7
void setup() {

  pinMode(pinMQ4, INPUT); 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println(" MQ4_Test.ino ");
  Serial.println(" Wait for heating ");
  altDelay(30,1);
  
//  Measure Sensor Resistance in Clean Air and compute R0_NO2
  Serial.println(" Rs in clean air for computing R0");
  float sum = 0;
  for(int i = 0; i < nSample; i++){
     Read_MQ4(pinMQ4,1);
     sum = sum + R0_CH4;
     altDelay(1,0);
  }
  R0_CH4 = sum/float(nSample);  // valore di fondo che rappresenta R0
  Serial.println();
  Serial.print("Valore di fondo di R0: "); Serial.println(R0_CH4,0);
  altDelay(10,0);
  Serial.println(" Now you can measure your air ");
}

//////////////////////////////////////////////////////////7
void loop() {
    Serial.println();
     Read_MQ4(pinMQ4,0);
     altDelay(5,0);        
     
}
