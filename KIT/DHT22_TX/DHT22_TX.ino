/*  DUST_TX_2
 *  Sketch for transmit Temperature and Humidity
 *  Hardware:  ProMicroLora, DHT22
 *  
 *   Wiring
 *   
 *   ProMicroLora       DHT22
          D6             DATA
          +               3.3
          GND             GND
 *             
 *  Paolo Bonelli 08/12/2019
  */

#include "Radio.h"
#include "Sens.h"
#include "Packet30003.h"
////////////////////////////////////////////
byte ECHO  = 0  ;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("DHT22_TX.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    minni.Data30003.UMID = 0;
    minni.Data30003.TEMP = 0;
    Transmit();
    altDelay(5000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  if(ncicli >= ncicliMax){

//  Read DHT22
    minni.Data30003.UMID = 0;
    minni.Data30003.TEMP = 0;
    ReadDHT();

// Transmit data
    Transmit();
    ncicli = 0;
  }
 
  if(ECHO){
     altDelay(5000);
  }else{
  
//  The radio goes to sleep
     rf95.sleep();  
// The ProMicro goes to sleep for 20 seconds. 
     Watchdog.sleep(4000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
  }
}
