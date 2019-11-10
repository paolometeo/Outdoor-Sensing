/*   Geiger_TX_V2 43998
 *   Hardware:  Geiger Tube, ProMicroLoRa, Power Board for the tube,  3xAAA battery, Step-up 6V, 
 *   Buzzer,LED
 *   
    Settings for New Geiger Project (negative pulse and pullup input)
 *  Sketch uploading: set the board Sparkfun ProMicro in the IDE Board Menu
 *  Set ECHO to "1" if you want to see some things on the Serial Monitor; "0" othewise
 *  
 *  Paolo Bonelli 10/10/2019
 *  
 */

#include "Radio.h"
#include "Packet43998.h"
#include "Sens.h"
////////////////////////////////////////////
byte ECHO  = 0;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("Geiger_TX_V2.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    minni.Data43998.uSvh = 0;
    minni.Data43998.countPeriod = 0;
    Transmit();
  digitalWrite(CountPin,HIGH);  // internal pullup resistor
  attachInterrupt(digitalPinToInterrupt(CountPin), count, FALLING);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  minni.Data43998.uSvh = 0;
  minni.Data43998.countPeriod = 0;
  timePassedLog = millis() - tempoOldLog;  // Time passed for update datalogger (s)
  if(timePassedLog > period){
    detachInterrupt(digitalPinToInterrupt(CountPin));
    CPM = 60000.0*float(n)/float(period);  // Computes cpm
    uSv_h = CPM*CF;        // Computes uSv/h
    if(ECHO){
       Serial.print(" n ");Serial.print(n);Serial.print(" CPM ");
       Serial.print(CPM); Serial.print(" uSv_h ");Serial.println(uSv_h,3);
    }
    n = 0;
    if(CPM > CPM1){
       period = period1;  // 5 s
    }else {
       period = period2;  // 30 s
    }
    minni.Data43998.uSvh = uSv_h;
    minni.Data43998.countPeriod = period/1000.0;
    Transmit();
    tempoOldLog = millis();
    attachInterrupt(digitalPinToInterrupt(CountPin),count,FALLING);
  }
 }
