/*
 Sparkfun ESP8266 
  It receives data from a Feather LoRa board and transmit to Adafruit IO
  via WiFi connection.
  
 // From a tutorial by Adafruit
//  modified by Paolo Bonelli 15/02/2020 

************************* Configuration ***********************************
 edit the config.h tab and enter your Adafruit IO credentials
 and any additional configuration needed for WiFi, cellular,
 or ethernet clients.
*/
#include "Config.h"
#include "Variables.h"
#include "Packet.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial1(RXpin, TXpin); // RX, TX
///////////////////////////////////////////////////////////////////////////////
byte ECHO = 1;  //  1: you can see serial output; 0: you can't. Use 0 when no USB cable is connected
byte ECHO2 = 1;  // 1: you can see serial output of receiving bytes
////////////////////////////////////////////////////////////////////////////////
byte TrasmettiAda = 1; // se 0 it doesn't transmit to Adafruit server
///////////////////////////////////////////////////////

float TimePassed = 0;
float TimeOld = 0;
byte datanew = 0;

void setup() {
  pinMode(RXpin, INPUT);
  pinMode(TXpin, OUTPUT);

  // start the serial connection
  if(ECHO){
  Serial.begin(115200);
  Serial.println("ESP_AdafruitIOmain_V2.ino");
  }
  mySerial1.begin(57600);
  delay(1000);

  // wait for serial monitor to open
//  while(! Serial);

if(TrasmettiAda){
  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}
}

void loop() {
/*
   io.run(); is required for all sketches.
   it should always be present at the top of your loop function. 
   it keeps the client connected to
   io.adafruit.com, and processes any incoming data.
   
*/
       if(TrasmettiAda){
           io.run();
       }
  //   Receive data from Serial
        flagEnd = 0;
        nbyte = mySerial1.available();
        if(nbyte > 0){ 
         primo = mySerial1.read();
         if(ECHO2){
            Serial.print(" ");Serial.print(primo,HEX);
         }
         if(primo == 0xAA && flag == 0){  // trova un primo AA
           flag = 1;   
         }else if(primo == 0xAA && flag == 1){  // trova un secondo AA subito dopo il primo
           flag = 2;
           i = 0;
           buf[i] = primo;
           i++;
           if(ECHO2){
              Serial.println(" inizio ");
           }
         }else if(primo != 0xAA && flag == 1){  // trova un carattere diverso dopo il primo
           flag = 0;          
         }else if(primo == 0xFF && flag == 2){
           flag = 3; 
           buf[i] = primo;
           i++;
         }else if(primo != 0xFF && flag == 3){
          flag = 2;
          buf[i] = primo;
          i++;        
         }else if(primo == 0xFF && flag == 3){
           flagEnd = 1;
           buf[i] = primo;
           i++;         
       //  finisce messaggio
           if(ECHO2){
               Serial.println(" fine");
           }
         }else if(flag == 2){
            buf[i] = primo;
            i++;          
         }
         if(flagEnd){
            flagEnd = 0;
            nbyteRec = i-3;
            if(nbyteRec > 49){
               if(ECHO2){
                  Serial.println(" nbyteRec fuori range ");
                  Serial.println(" stoppo tutto ");
               }
               while(1);
            }
            i = 0;
            nbyte = 0;
            flag = 0; 
            for(int j = 0; j < nbyteRec+1; j++){
                buf[j]= buf[j+1];
            }     
            if(ECHO2){
                Serial.println("  Contenuto ");
                Serial.print("nbyteRec ");Serial.println(nbyteRec);
                for(int j = 0; j < nbyteRec; j++){
                   Serial.print(buf[j],HEX);Serial.print(" ");
                }
                Serial.println();
            }               
 //  check data
            word sum = 0;
            for(int j = 0; j < nbyteRec-1; j++){
                sum = sum + buf[j];
            }
            byte chs = sum % 256;
            if(ECHO2){
               Serial.println(" Controllo somma ");
               Serial.print(chs);Serial.print(" ");Serial.println(buf[nbyteRec-1]);
            }
            err = 0;
            if(chs != buf[nbyteRec-1]){
                   err = 1;
                   if(ECHO2){
                     Serial.println(" messaggio corrotto ");
                   }
            }else{
                   if(ECHO2){
                     Serial.println(" messaggio corretto ");
                   }
            }             
            if(!err){
               SerialReceive();  // decodifica
               datanew = 1;     
            }
          }                               
         }
               
  // Adafruit IO is rate limited for publishing, so a delay is required in
  // between feed->save events. In this example, we will wait three seconds
  // (1000 milliseconds == 1 second) during each loop.
  //  delay(6000);
    if(datanew == 1){
       TimePassed = millis()-TimeOld;
       if(TimePassed > 6000){
           Action();    // gestisce la trasmissione ad Adafruit
           TimeOld = millis();
           datanew = 0;
       }
    }
}
