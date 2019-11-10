/*
 *  TurbiTube1_TX  17899
 *  Hardware:  ProMicroLora, Dishwasher turbidity sensor, BSS138 Mosfet, 
 *  DC/DC stepup, 3x AAA battery
 *  Wiring
 *  ProMicroLora  Mosfet    DC/DC IN    DC/DC OUT   Battery  22K   56K   10K  Sensor
 *  GND             S                     OUT-         GND          X     X    GND
 *  +                         IN+                    +4.5V
 *                  D         IN-        
 *                                        OUT+                                  VCC
 *  A1              G                                                     X
 *                                                           X                 Aout
 *  A0                                                       X      X
 *  
 *  Sketch uploading: set the board Sparkfun ProMicro in the IDE Board Menu
 *  Set ECHO to "1" if you want to see some things on the Serial Monitor; "0" othewise
 *  
 *  Paolo Bonelli 06/10/2018
 *  Paolo Bonelli 28/04/2019
 *  
 */

#include "Radio.h"
#include "Packet17899.h"
#include "Sens.h"
////////////////////////////////////////////
byte ECHO  =     0;
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
