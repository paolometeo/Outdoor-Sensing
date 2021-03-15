/*  MiniReteLoRa Receiver with communication with ESP8266 and Arduino UNO
 *  Hardware: ProMicroLoRa
 *  
 * This Sketch use ProMicroLoRa board as a radio, receiving packets from other ProMicroLoRa boards used as transmitters
 * This board re-transmit data to an ESP8266 board and an Arduino Board
 *  
   Upload with USB cable
   Setting the board as SparkFun Pro Micro
   Setting the IDE, select "verbouse"
   After upload from IDE, if the system search for the COM port, push two times the bottom reset

   
   
                             
   Paolo Bonelli 28/04/2020
*/ 


#include "RadioRX_ESP.h"
#include "Packet.h"
//  frequency must be the same of the transmitter
#define RF95_FREQ_RX 868.0

//***************************************************************************
byte ECHO = 1;  // When 1 allows diagnostic on serial monitor
                // Put 0 when the board is not connected to the USB cable.
//***************************************************************************
////////////////////////////////////////////////////////
void setup(){

// It's necessary, when you switch-on the power,in order to start setup without reset
  delay(2000);  
  RadioRX_Init();
  rf95.setFrequency(RF95_FREQ_RX);
  delay(2000);
      if (ECHO) {
         Serial.print("Set Freq to: "); Serial.println(RF95_FREQ_RX);
      }
  if(ECHO){
     Serial.println(" Ho finito il setup");
  }
Roger = 0;
delay(3000);
} 
///////////////////////////////////////////////////////
void loop(){
    Roger = Receive();  
    if(Roger){
      if(ECHO){
        Serial.println(" I received a message");
      }
      Action();
      Roger = 0;
    }
}  
