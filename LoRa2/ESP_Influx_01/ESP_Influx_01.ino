/*****************************************************************************
  // Hardware: ESP8266 Thing Dev by Sparkfun
  ESP8266 is connected to the ProMicroLoRa by means of SoftwareSerial in order to collect data coming from
  that board.
  ESP8266 is connected to a WiFi network and transfer data to the  Exosite server https://portals.exosite.com

Setting before uploading
WiFi SSID and password      ConnectWiFi
cikData for Exosite         ExositeKeys.h


  Wiring 
     ProMicroLoRa        ESP8266    Step-up 5 V
     GND                 GND          OUT-
     5 (RX)               0  (TX)
     6 (TX)               5  (RX)
     RAW                  VCC         OUT+
   

     Library other than Arduino
     https://github.com/ekstrand/ESP8266wifi
     https://github.com/exosite-garage/arduino_exosite_library

     Paolo Bonelli 11/09/2019  
*/

#include "Variables.h"
#include "Packet.h"
#include "ExositeKeys.h"
#include <ESP8266WiFiMulti.h> 
#include <SoftwareSerial.h>
//#include <Exosite.h>
#include <InfluxDb.h>

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
///////////////////////////////////////////////////////////////////////////////
byte ECHO = 1;  //  1: you can see serial output; 0: you can't. Use 0 when no USB cable is connected
////////////////////////////////////////////////////////////////////////////////
byte TrasmettiExosite = 1; // se 0 it doesn't transmit on Exosite server
///////////////////////////////////////////////////////
SoftwareSerial mySerial1(RXpin, TXpin); // RX, TX
WiFiClient client;
//Exosite exosite(cikData, &client);

void setup() {
  pinMode(RXpin, INPUT);
  pinMode(TXpin, OUTPUT);

// Init Serial Monitor
  if (ECHO) {
    Serial.begin(115200);
    Serial.println("ESP_Influx_01.ino");
    delay(1000);
  }

//  Init Software Serial 
  mySerial1.begin(57600);
  delay(1000);
  if(ECHO){
    Serial.println(" Seriali inizializzate");
  }

//  Connect WiFi
  connectWifi();
  delay(2000);

//  Write sketch name
  if (ECHO) {
    Serial.println(" Sketch name: ESP_Influx_01.ino");
    delay(1000);
    Serial.println(" End setup ");
  }
}
/////////////////////////////////////////////////////////
void loop() {
      if(mySerial1.available() > 0){ 
         primo = mySerial1.read();
         if(ECHO){
//            Serial.println(primo,HEX);
         }
         if      (primo == 0xAA && flag == 0){  // trova un primo AA
           flag = 1;   
         }else if(primo == 0xAA && flag == 1){  // trova un secondo AA subito dopo il primo
           flag = 2;
           if(ECHO){
//              Serial.println(" inizio ");
           }
         }else if(primo != 0xAA && flag == 1){  // trova un carattere diverso dopo il primo
           flag = 0;          
         }else if(primo != 0xAA && flag == 2 && primo != 0xFF){
          buf[i] = primo;
          if(ECHO){
//            Serial.print(i); Serial.print(" ");
//            Serial.println(buf[i],HEX);
          }
          i++;
         }else if(primo == 0xFF && flag == 2){
          flag = 3;
         }else if(primo == 0xFF && flag == 3){
          
           //  finisce messaggio
            if(ECHO){
//               Serial.println(" fine");
            }
           nbyte = i;
           if(ECHO){
              Serial.println(nbyte);
              for(int j = 0; j < nbyte; j++){
                Serial.print(buf[j],HEX);Serial.print(" ");
              }
              Serial.println();
           }              
           SerialReceive();  
           WiFi_Transmit();
           flag = 0;
           nbyte = 0;
     //            clear received
           buono = 0;
           for(int j = 0; j < MXbuf; j++){
                 buf[j]=0;
           }
           for(int j = 0; j < MXVAR; j++){
                 minni.bufVar[j]=0;
           }
           i = 0;
         } 
     }
}
