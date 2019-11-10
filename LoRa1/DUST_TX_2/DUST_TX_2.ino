/*  DUST_TX_2
 *  Sketch for transmit Dust concentration from SDS011 sensor
 *  Hardware:  ProMicroLora, SDS011, DHT22
 *  
 *   The sketch reads sensor SDS011 signals fromn PWM outputs 
 *   Power supply for the SDS011 is 5 V. Its outputs are at 5 V that are converted to 3.3 V 
 *   by means of two dividers built with two R: 4.7K and 33K.
 *   Sensor is switched on by means of a Mosfet Channel P  NDS356AP
 *   Wiring
 *   see picture
 *             
 *  Paolo Bonelli 13/09/2019
 *  Paolo Bonelli 03/10/2019
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet30005.h"
////////////////////////////////////////////
byte ECHO  = 0  ;
/////////////////////////////////////////////
void setup() {

  //  Initializing the serial monitor
  if(ECHO){
  while (!Serial);  
    Serial.begin(9600);
    delay(100);
    Serial.println("DUST_TX.ino");
  }

  //  Initializing the radio
    RadioInit();
    SensInit();
    
//   First transmission with all the variables at 0
    minni.Data30005.Conc10 = 0;
    minni.Data30005.Conc25 = 0;
    minni.Data30005.UMID = 0;
    minni.Data30005.TEMP = 0;
    Transmit();
    altDelay(5000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  if(ncicli >= ncicliMax){

//  Switch on SDS011 and LED
    digitalWrite(PINpower,LOW);
    digitalWrite(PINLED,HIGH);

// wait for sampling air
    altDelay(10000);

// Read concentrations
    minni.Data30005.Conc10 = 0;
    minni.Data30005.Conc25 = 0;
    ReadSensor();

// Switch off SDS011 and LED
    digitalWrite(PINpower,HIGH);
    digitalWrite(PINLED,LOW);

//  Read DHT22
    minni.Data30005.UMID = 0;
    minni.Data30005.TEMP = 0;
    ReadDHT();

// Transmit data
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
