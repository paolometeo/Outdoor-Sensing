/*  Vibration_TX_2  30002
 *  Sketch for  transmitting the number of vibration occurred in "Period" milliseconds, 
 *  every time it "hears" a vibration.
 *  It uses hardware interrupt on pin D2. If any vibration has been heard, after ncicliMax minutes, 
 *  it transmit a message with 0 vibration.

 Hardware:  ProMicroLoRa; Vibration sensor S801; 
            Battery 3 x AAA

   Wiring:
   ProMicroLoRa      S801
   3.3                Vcc
   GND                GND
   D2                  DO  (Digital Output)

 *  Paolo Bonelli 08/09/2019

 */
#include "Radio.h"
#include "Sens.h"
#include "Packet30002.h"
//*******************************************************************
byte ECHO = 0;        // put 1 if you want to print something on the serial monitor of 
                      // the PC; 0 otherwise
////////////////////////////////////////////////////////////////////
void setup() {
  if(ECHO){
    while(!Serial);
    Serial.begin(9600);
    delay(100);
    Serial.println(" Vibration_TX.ino ");
  }
  //  Initializing the radio
    RadioInit();
    SensInit();
    Battery();

//   First transmission with all the variables at 0
    Transmit();
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, RISING);
    
}
//////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  Tempo = 0;
  
  //   This loop to hear eventually interrupts during Period millisec
  while (Tempo < Period) {
    Tempo = millis() - TimeOld;
  }
  TimeOld = millis();
  detachInterrupt(digitalPinToInterrupt(interruptPin));

//  After ncicliMax without interrupts, it transmits a message anyway
 if( ncicli >= ncicliMax && n == 0){
    minni.Data30002.npulse = n;
    minni.Data30002.sPeriod = 0;
    Transmit();  
    ncicli = 0;
 }
 
//  if any interrupts occurs, it transmits a message with the number of interrupts
  if(n > 0){
    minni.Data30002.npulse = n;
    minni.Data30002.sPeriod = Period;
    Transmit();   //  trasmette il numero di conteggi
    ncicli = 0;
    n = 0;
  }
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, RISING);
  /////////////////////////////va a dormire per circa 1 m ////////////////
if(ECHO){
  altDelay(10000);
}
else{
  //  dorme per 20 sec
  rf95.sleep();
  Watchdog.sleep(8000);  // 0.31 mA di consumo. 8000 ms è il max, ma posso ripeterlo più volte
  Watchdog.sleep(8000);  // 0.31 mA di consumo. 8000 ms è il max, ma posso ripeterlo più volte
  Watchdog.sleep(4000);  
}
}
