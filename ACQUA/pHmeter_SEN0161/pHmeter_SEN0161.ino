/*
 * pHmeter_SEN0161.ino
 * 
 * Hardware pH Probe DF-SEN 0161 con scheda BNC a due trimmer e uscita con 6 pin maschi
 * Stampa in uscita le tensioni che legge sul piedino P0 e i valori di pH.
 * Richiede tre valori di calibrazione, cioè le tensioni corrispondenti alle tre 
 * soluzioni campione di ph 4.00, 6.86, 9.18, ricavate dal programma TestPH.ino
 * 
 * Piedinatura scheda (vista dall'alto, piedini da sinistra)
 * T0:  Should be the temperature but I can't make it works.
 * D0:  High/Low 3.3v adjustable limit.
 * P0:  Analog Output to A0
 * GND: Probe ground. It is useful when the ground is not the same as your Arduino. 
 *      In some circumstances the ground voltage of the liquid to measure can be different.
 * GND: Power ground (direct from Arduino).
 * VCC: + 5 V

 */
#include "pH.h"

byte ECHO = 1;
////////////////////////////////////////////////
void setup() {
  if(ECHO){
    Serial.begin(9600);
    delay(100);
    Serial.println(" pHmeter_SEN0161.ino ");
  }
  pHInit();
}
/////////////////////////////////////////////////////////////////
void loop() {
   TimePassed = millis()-TimeOld;
   if(TimePassed >= Period){   
       ReadPH();
       TimeOld = millis();
   }
}
