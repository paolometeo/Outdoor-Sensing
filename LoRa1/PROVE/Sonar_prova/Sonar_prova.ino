/*  Sonar_prova
    Wiring:
   ProMicroLoRa      SR04    Level converter  Step-up 4.5 >> 5.0  Divider
   RAW                VCC          HV                OUT+
   3.3                             LV
   GND                GND          GND               OUT-
   D2                              LV4
   D3                              LV3
                      Echo         HV4
                      Trig         HV3                     
   A9                                                               Central 
 *  
 *  Per caricare il programma su scheda ProMicroLora, selezionare nella IDE la scheda Sparkfun ProMicro
 *  Se si vuole l'uscita su Monitor Seriale, mettere la variabile ECHO = 1, altrimenti ECHO = 0.
 *  
 *  
 *  Paolo Bonelli 10/09/2019
 *  
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet30004.h"
////////////////////////////////////////////
byte ECHO  = 1;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("Sonar_prova.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    minni.Data30004.Dist = 0;
    Transmit();
    altDelay(5000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  if(ncicli >= ncicliMax){
    ReadSensor();
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
