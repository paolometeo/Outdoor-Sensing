
/*
   Sketch for TurbiTube3Sub  (Totally submerged turbidimeter)
   feather_TSL230_TurbiTube3Sub_V6.ino
   Hardware: Adafruit Feather 32u4 LoRa; light sensor TSL230; Emitter diode IR SE5470-004
   Wiring:
   TSL230          Feather      MOSFET   Emitter diode   39 ohm resistor   battery
    1 S0             +3.3
    2 S1             +3.3
    3 OE             D3
    4 GND            GND
    5 VDD           +3.3
    6 OUT           D6
    7 S2            GND
    8 S3            +3.3
                    D5           gate     
                                 drain       catode
                    GND          source
                                             anode            x
                    +3.3                                      x             
  //////////////////////////////////////////////////////////////////////////


   Paolo Bonelli 10/05/2018
   Paolo Bonelli 06/10/2018
   Paolo Bonelli 12/12/2018
   Paolo Bonelli 15/05/2019
   Paolo Bonelli 12/06/2019
*/
#include "Radio.h"
#include "Packet51515.h"
#include "Sens.h"
//***************************************************************************
   byte ECHO = 0;  // When 1 allows diagnostic
// Put 0 when the board is not connected to the USB cable.
//***************************************************************************

void setup() {

  if (ECHO) {
    while (!Serial);
    Serial.begin(9600);
    delay(100);
    Serial.println(" feather_TSL230_TurbiTube3Sub_V6.ino ");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();


// trasmissione di prova senza misure
    Transmit();
    altDelay(20000);
}
//////////////////////////////////////////////////////////////////////
void loop() {
    ncicli++;
    if(ncicli >= ncicliMax){
        digitalWrite(OEpin,LOW);  //  accende sensore
        altDelay(100);

//      take measures
        ReadSensor(TSL230_samples); 

//      Transmit 
        Transmit();
        if (ECHO) {
          Serial.println(" Trasmetto ");
        }
        ncicli = 0;
   }
   digitalWrite(OEpin,HIGH);  //  spegne sensore

     if(ECHO){   
       altDelay(5000);
     }
     else{
    
//  Usa le funzioni di sleep

     rf95.sleep();  
     
  // Go to sleep for 60 seconds. 
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(4000);  
 }
}
