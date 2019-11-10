/*  Sonar_TX  30004
 *  Sketch for transmitting distance with a sonar sensor
 *  Hardware:  
 *  ProMicroLora, SR04 sonar sensor, level converter, Battery 3 x AAA, 
 *  Step-up, Two resistor of the same value for the divider
 
   Wiring:
   ProMicroLoRa      SR04    Level converter  Step-up 4.5 >> 5.0   Divider   3xAAA
   RAW                VCC          HV                OUT+ 
   3.3                             LV
   GND                GND          GND               OUT-             X        -
   D2                              LV4
   D3                              LV3
                      Echo         HV4
                      Trig         HV3                     
   A9                                                              Central     
                                                                      X        +
 *                                                                                                                                        
 *  Sketch uploading: set the board Sparkfun ProMicro in the IDE Board Menu
 *  Set ECHO to "1" if you want to see some things on the Serial Monitor; "0" othewise
 *  
 *  Paolo Bonelli 10/09/2019
 *  
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet30004.h"
////////////////////////////////////////////
byte ECHO  = 0;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
    while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("Sonar_TX.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    minni.Data30004.Dist = 0;
    minni.Data30004.Duration = 0;
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
