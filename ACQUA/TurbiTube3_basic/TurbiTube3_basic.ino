/*
   Sketch for TurbiTube3  Versione con lettura tramite un Arduino UNO
   Hardware: Arduino UNO; light sensor TSL230; Emitter diode IR SE5470-004, Mosfet
   Wiring:
   TSL230          Arduino      Emitter diode   72 ohm R  15K R  1.5K R  Mosfet
    1 S0             +5
    2 S1             +5
    3 OE             D3
    4 GND            GND
    5 VDD           +5                              
    6 OUT           D4
    7 S2            GND                                    x              S
    8 S3            +5                                     |
                    D5                                     |      x                
                                   catode(black)           |      |       D
                                   anode            x      |      |
                                                    |      x      x       G
                    +5                         (red)x

   Paolo Bonelli 25/03/2019
*/

#include "TT3.h"

void setup() {
    Serial.begin(9600);
    delay(100);
    Serial.println(" TurbiTube3.ino ");
  TT3Init();
 }
//////////////////////////////////////////////////////////////////////
void loop() {

//  take measures and put them in these variables



Serial.println(" Leggi");
   ReadTT3();
   Serial.print(" LED spento ");Serial.print(lightLevel1,0);
   Serial.print(" LED Acceso ");Serial.print(lightLevel2,0);
   Serial.print(" Acceso/Spento ");Serial.println(Ratio);
   delay(1000);
}
