/*  SHT21_TX  30003
 *  Sketch for transmitting Temperature and Humidity from SHT21 sensor
 *  Hardware:  ProMicroLora, SHT21, Stepup, 3xAAA, 
 *  Two resistor of the same value for the divider
 *  
 *  Wiring
 *  ProMicroLora   SHT21   3xAAA   Step up 4.5 >> 5.0  Divider
 *  VCC             VIN                                      
 *  D2              SDA 
 *  D3              SCL 
 *  RAW                                   OUT+           X
 *  GND             GND                   OUT-           X
 *                           +            IN +
 *                           -            IN -
 *  A9                                                  Central
 *  
 *  Sketch uploading: set the board Sparkfun ProMicro in the IDE Board Menu
 *  Set ECHO to "1" if you want to see some things on the Serial Monitor; "0" othewise
 *  
 *  Paolo Bonelli 10/09/2019
 *  
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet30003.h"
////////////////////////////////////////////
byte ECHO  = 0;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("SHT21_TX.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    minni.Data30003.Temp = 0;
    minni.Data30003.Humi = 0;
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
