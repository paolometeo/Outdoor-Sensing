
/*
   Sketch TurbiTube3_TX for TurbiTube3 turbidimeter
   
   Hardware: Adafruit Feather 32u4 LoRa; 
             light sensor TSL230; 
             Emitter diode IR SE5470-004;
             MOSFET   BSS138;
             Lipo Battery 3.7 V;
   Wiring:
   TSL230          Feather      MOSFET   Emitter diode   39 ohm resistor   battery
    1 S0             +3.3
    2 S1             +3.3
    3 OE             D3
    4 GND            GND
    5 VDD            +3.3
    6 OUT            D6
    7 S2             GND
    8 S3             +3.3
                     D5          gate     
                                 drain       catode
                     GND         source
                                             anode            x
                    +3.3                                      x             
                    +                                                      +3.7
                    -                                                      GND
  //////////////////////////////////////////////////////////////////////////


   Paolo Bonelli 10/05/2018
   Paolo Bonelli 06/10/2018
   Paolo Bonelli 12/12/2018
   Paolo Bonelli 15/05/2019
   Paolo Bonelli 29/08/2020
*/
#include "Radio.h"
#include "Sens.h"
#include "Packet.h"
#define RF95_FREQ 868.0  // LoRa Frequency
#define RF95_POW   23    // Transmitting power dBm
  int   ncicliMax =       1;  // numero di loop prima di fare una misura e trasmettere
  int   ncicli =          0;

//***************************************************************************
   byte ECHO = 0;  // When 1 allows diagnostic
// Put 0 when the board is not connected to the USB cable.
//***************************************************************************

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
    minni.Data51515.Level1 = 0;
    minni.Data51515.Level2 = 0;
    minni.Data51515.Ratio = 0;
    Transmit();
    altDelay(5000);
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
