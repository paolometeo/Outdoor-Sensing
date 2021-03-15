/*  MiniReteLoRa Receiver with display OLED
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
 *          ProMicroLoRa  PIN  (new)
 *   + -    3.3  A3  A2  A1  A0        G  A
 *  USB
 *     TX  RX  G  G  D2  D3  D5  D6  D8  A9
    Libraries not from Arduino
   https://github.com/PaulStoffregen/RadioHead/blob/master/RH_RF95.h
   https://github.com/adafruit/Adafruit_SleepyDog
   Adafruit_SSD1306.h
                              
   Paolo Bonelli 28/04/2020
*/ 


#include "RadioRX.h"
#include "Packet.h"
//  frequency must be the same of the transmitter
#define RF95_FREQ_RX 868.0

//***************************************************************************
byte ECHO = 0;  // When 1 allows diagnostic on serial monitor
                // Put 0 when the board is not connected to the USB cable.
//***************************************************************************
////////////////////////////////////////////////////////
void setup(){

// It's necessary, when you switch-on the powerin order to start setup without reset
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
  //  Display OLED
    display.clearDisplay();
    delay(500);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Frequency");
    display.setCursor(0,16);
    display.print(RF95_FREQ_RX);
    display.display();
//
delay(3000);
Roger = 0;
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
