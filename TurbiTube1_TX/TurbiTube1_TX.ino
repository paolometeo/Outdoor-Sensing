/*
 *  Sketch for TurbiTube1 
 *  Hardware:  ProMicroLora,
 *             Dishwasher turbidity sensor, 
 *             NDS356AP Mosfet, 
 *             DC/DC stepup, 
 *             3x AAA battery
 *             2 resistor 22K and 56K
 *  Wiring
 *  ProMicroLora  Mosfet    DC/DC IN    DC/DC OUT   Battery  22K   56K    Sensor
 *  GND                       IN-        GND         GND           GND      GND
 *                            IN+                   +4.5V
 *                                  
 *  +               S                   +5V                                    
 *  A1              G         
 *                                                           X              Aout
 *  A2                                                       X      X
 *                  D                                                       VCC
 *  Per caricare il programma su scheda ProMicroLora, selezionare nella IDE la scheda Sparkfun ProMicro
 *  Se si vuole l'uscita su Monitor Seriale, mettere la variabile ECHO = 1, altrimenti ECHO = 0.
 *  
 *  Paolo Bonelli 06/10/2018
 *  Paolo Bonelli 28/04/2019
 *  Paolo Bonelli 17/05/2020
 *  Paolo Bonelli 28/08/2020
 *  
 */

#include "Radio.h"
#include "Sens.h"
#include "Packet.h"
#define RF95_FREQ 868.0  // LoRa Frequency
#define RF95_POW   23    // Transmitting power dBm

word ncicli =    0;
word ncicliMax = 2;
////////////////////////////////////////////
byte ECHO  =     1;
/////////////////////////////////////////////
void setup() {
  //  Initializing the radio
    RadioInit();
    rf95.setFrequency(RF95_FREQ);
    if (ECHO) {
      Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);
    }
//  Set transmission Power
    rf95.setTxPower(RF95_POW, false);
    if (ECHO) {
    Serial.print("Set Power to: "); Serial.println(RF95_POW);
  }  
  SensInit();
  
//   First transmission with all the variables at 0
    minni.Data17899.Value = 0;
    Transmit();
    altDelay(5000);
}
//////////////////////////////////////////////////////////////////////////////
void loop() {
  ncicli++;
  if(ncicli >= ncicliMax){
    ReadSensor();
    if(minni.Data17899.Value > 5 && minni.Data17899.Value < 900){
      Transmit();
      ncicli = 0;
    }
  }
  if(ECHO){
     altDelay(5000);
  }else{
//  The radio goes to sleep
     rf95.sleep();  
// The ProMicro goes to sleep for 30 seconds. 
     Watchdog.sleep(8000);  
     Watchdog.sleep(8000);  
  }
}
