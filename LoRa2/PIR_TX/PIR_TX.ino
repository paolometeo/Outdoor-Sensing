/*  PIR_TX
 *  Sketch for transmitting PIR sensor status 
 *  Hardware:  ProMicroLora, PIR sensor
 *  The sketch uses Interrupt on pin 3. 
 *  Wiring
 *  
 *  
 *  Per caricare il programma su scheda ProMicroLora, selezionare nella IDE la scheda Sparkfun ProMicro
 *  Se si vuole l'uscita su Monitor Seriale, mettere la variabile ECHO = 1, altrimenti ECHO = 0.
 *  
 *  Paolo Bonelli 08/09/2019
 *  
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet30001.h"
////////////////////////////////////////////
byte ECHO  =   1;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("PIR_TX.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    Battery();
    
//   First transmission with all the variables at 0
    Transmit();
    altDelay(5000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
    if(PIR == 1){
      detachInterrupt(digitalPinToInterrupt(PIRpin)); 
      minni.Data30001.PIRstatus = PIR;     
      Transmit();                      // Transmit the PIR alert
      altDelay(8000);                  // Don't transmit anything else for 8 sec
      PIR = 0;
      minni.Data30001.PIRstatus = PIR;     
      Transmit();                      //  Transmit the end of the alert      
    }
    attachInterrupt(digitalPinToInterrupt(PIRpin), ISR_PIR, LOW); 

//   it does a loop every 10 sec in the  Serial Monitor mode
    if(ECHO){
        altDelay(10000);
    }else{

//  it does a loop every 20 sec without Serial Monitor
//  The radio goes to sleep
     rf95.sleep();  
// The ProMicro goes to sleep for 20 seconds. 
     Watchdog.sleep(4000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
  }
}
