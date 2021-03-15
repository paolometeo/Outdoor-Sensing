/*  LoRa Receiver with display OLED
 *  Hardware: ProMicroLoRa, I2C Display OLED  128 x 32
 *  
 * This Sketch use ProMicroLoRa board as a radio, receiving packets from other ProMicroLoRa boards used as transmitters
 * This board re-transmit data to a Display OLED I2C
 *  
   Upload with USB cable
   Setting the board as SparkFun Pro Micro
   Setting the IDE, select "verbouse"
   After upload from IDE, if the system search for the COM port, push two times the bottom reset

  Wiring 
   
 *   ProMicroLoRa    Display OLED                
 *       GND            GND                                  
 *       VCC (3.3)      VCC
 *       D2             SDA
 *       D3             SCL
 *       
 *   
    Libraries not from Arduino
   https://github.com/PaulStoffregen/RadioHead/blob/master/RH_RF95.h
   https://github.com/adafruit/Adafruit_SleepyDog
   Adafruit_SSD1306.h
                              
   Paolo Bonelli 08/12/2019 
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
       
