/*
  Read CCS811 sensor

  Paolo Bonelli 17/02/2019
*/
#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;
float ppbVOC = 0;
float Temp811 = 0;
float ppmCO2 = 0;

//  You can put a value computed in the past and put airFlag = flase or ask for computing a value putting airFlag = true.

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println(" CCS811:Test.ino ");
  
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
//calibrate temperature sensor
  while(!ccs.available());
  float temp = ccs.calculateTemperature();
  Serial.println(temp);
  ccs.setTempOffset(temp - 25.0);
}

//////////////////////////////////////////////////////////7
void loop() {
  Read_CCS811();
  Serial.print(" Temperature ");Serial.print(Temp811,1);
  Serial.print("  ppb VOC: ");Serial.println(ppbVOC);
  altDelay(3,0);
}
