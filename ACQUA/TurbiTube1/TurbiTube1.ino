/*
 *  Sketch for TurbiTube1 
 *  Hardware:  Arduino UNO,Dishwasher turbidity sensor
 *  Wiring
 *  ARDUINO UNO    Sensor
 *  GND            G     viola/marrone/grigio
 *  +5V            V     rosso/arancio                
 *  A0             A    giallo
 *    
 *  Paolo Bonelli 01/04/2019
 *  
 */

#include "TT1.h"
//***************************************************************************
   byte ECHO = 1;  // When 1 allows diagnostic
// Put 0 when the board is not connected to the USB cable.
//***************************************************************************

/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("TurbiTube1.ino");
  }
  TT1Init();
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
   TimePassed = millis()-TimeOld;
   if(TimePassed >= Period){   
       ReadTT1();
       if(ECHO){
          Serial.println(Value);
       }
       TimeOld = millis();
   }
}
