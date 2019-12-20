/*  LoRa Receiver with ESP8266
 *  Hardware: ProMicroLoRa, Sparkfun ESP8266 Thing Dev, I2C Display LCD, level converter, Power supply by USB
 *  
 * This Sketch use ProMicroLoRa board as a radio, receiving packets from other ProMicroLoRa boards used as transmitters
 * This board re-transmit data to a Sparkfun ESP8266  via Software Serial, only if ID of transmitter is allowed
 * This board re-transmit data to a Display LCD I2C
 *  

   Upload with USB cable
   Setting the board as SparkFun Pro Micro
   Setting the IDE, select "verbouse"
   After upload from IDE, if the system search for the COM port, push two times the bottom reset

  Wiring 
   
 *   ProMicroLoRa        ESP8266          Display LCD    Power USB   Level converter
                                       
 *   GND                 GND               GND            GND             GND
 *   5 (TX)               0 (RX)                
 *   6 (RX)               5 (TX)                
 *   +3.3V              +3.3V                                              LV
 *   2                                                                     L1
 *   3                                                                     L2
 *                                         SDA                             H1       
 *                                         SCL                             H2
 *   +5                                   +5V             +5V              HV       
 *                                         
 *   
    Libraries not from Arduino
   https://github.com/PaulStoffregen/RadioHead/blob/master/RH_RF95.h
   https://github.com/adafruit/Adafruit_SleepyDog


   Paolo Bonelli 19/04/2019  
   Paolo Bonelli 05/06/2019
   Paolo Bonelli 18/08/2019
*/ 

#include "RadioRX_ESP.h"
#include "Packet.h"

//***************************************************************************
byte ECHO = 0;  // When 1 allows diagnostic on serial monitor
                // Put 0 when the board is not connected to the USB cable.
//***************************************************************************
////////////////////////////////////////////////////////
void setup() 
{
  RadioRX_ESP_Init();
}
///////////////////////////////////////////////////////
void loop(){
    byte Roger = Receive();  
    if(Roger){
      if(ECHO){
        Serial.println(" I received a message");
      }
      Action();
    }

//   Clear the receiving buffer
  for(i = 0; i < MXbuf; i++){
    buf[i] = 0;
  } 
  for(i = 0; i < MXVAR; i++){
    minni.bufVar[i] = 0;
  } 
}  
       
