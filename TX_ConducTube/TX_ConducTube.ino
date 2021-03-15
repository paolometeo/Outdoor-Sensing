/*
 Programma per ConducTube che usa ProMicroLoRa

Collegamenti hardware

PIN1------O  O----PIN2-----RRRRR-----PIN3     Lato sensore

D3                 A0       2200        D5      Lato ProMicroLoRa

Sensore temperatura   DS18B20
VCC >>> D2
DATA >>> D6
GND >>> GND
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet.h"
#define RF95_FREQ 868.0  // LoRa Frequency
#define RF95_POW   23    // Transmitting power dBm

word ncicli =    0;
word ncicliMax = 1;
///////////////////////////////////////////
byte ECHO  =     1;
/////////////////////////////////////////////
void setup() {
  //  Initializing the radio
    RadioInit();
    rf95.setFrequency(RF95_FREQ);
    if (ECHO) {
      Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);
    }
//  Set transmission Power
    rf95.setTxPower(RF95_POW, false);
    if (ECHO) {
    Serial.print("Set Power to: "); Serial.println(RF95_POW);
  }  
  SensInit();
  
//   First transmission with all the variables at 0
    minni.Data16133.WCS = 0;
    minni.Data16133.WCSspec = 0;   
    minni.Data16133.WTemp = 0;   
    Transmit();
    altDelay(5000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  if(ncicli >= ncicliMax){
    
  //  take measures
    ReadTemp();
    ReadConduct();
    Battery();
    
//  Transmit
    Transmit();
    ncicli = 0;
  }

  if(ECHO){
  delay(5000);
  }else{
    
//  The radio goes to sleep
     rf95.sleep();  
     
// It goes to sleep for 16 seconds. 
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
  }
}
