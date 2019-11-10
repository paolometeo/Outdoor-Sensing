/*
 *  Sketch for TurbiTube1 versione Torino
 *  Hardware:  ProMicroLora (vecchio),Dishwasher turbidity sensor, BSS138 Mosfet, DC/DC stepup, 3x AAA battery
 *  Wiring
 *  ProMicroLora  Mosfet    DC/DC IN    DC/DC OUT   Battery  22K   56K   10K  Sensor
 *  GND             S                     GND         GND          GND   GND   GND
 *  +                         +4.5                   +4.5V
 *                  D         -        
 *                                        +5V                                  VCC
 *  A1              G                                                     X
 *                                                           X                 Aout
 *  A0                                                       X      X
 *  
 *  Per caricare il programma su scheda ProMicroLora, selezionare nella IDE la scheda Sparkfun ProMicro
 *  Se si vuole l'uscita su Monitor Seriale, mettere la variabile ECHO = 1, altrimenti ECHO = 0.
 *  
 *  Paolo Bonelli 06/10/2018
 *  Paolo Bonelli 28/04/2019
 *  
 */

#include "Radio.h"
#include "Packet17899.h"
#include "Sens.h"
////////////////////////////////////////////
byte ECHO  =     1;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(57600);
    delay(100);
    Serial.println("TurbiTube1_TX.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    Transmit();
    altDelay(20000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  if(ncicli >= ncicliMax){
    
//  Transmit
    ReadSensor();
    if(minni.Data17899.Value > 5 && minni.Data17899.Value < 900){
      Transmit();
    }
  }
  if(ECHO){
  delay(5000);
  }else{
//  The radio goes to sleep
     rf95.sleep();  
// The ProMicro goes to sleep for 30 seconds. 
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
     Watchdog.sleep(6000);  
  }
}
