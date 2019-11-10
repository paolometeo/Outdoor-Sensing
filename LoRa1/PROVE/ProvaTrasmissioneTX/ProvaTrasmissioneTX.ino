
//  porta 46 Trasmettitore
#include <SoftwareSerial.h>
SoftwareSerial mySerial1(6, 7); // RX, TX
int i = 0;
int j = 0;
int Length = 17;
byte buf[50];
byte flag = 0;
byte ECHO = 0;

void setup() {
//  pinMode(7, OUTPUT);
//  pinMode(6, INPUT);

// Init Serial Monitor
    if(ECHO){
    Serial.begin(115200);
    Serial.println("ProvaTrasmissioneTX");
    }
    delay(1000);
  
//  Init Software Serial 
  mySerial1.begin(57600);
  delay(1000);
    if(ECHO){
    Serial.println(" Seriali inizializzate");
    }
    flag = 0;
    for(j = 0; j < 17; j++){
      buf[j]=j;
    }
}

void loop() {
    for(j = 0; j < 17; j++){
      buf[j]=j;
    }
                  mySerial1.write(0xAA);
                  mySerial1.write(0xAA);
                   for(j = 0; j < Length; j++){
                       mySerial1.write(buf[j]); 
                       if(ECHO){
                          Serial.print(buf[j],HEX); Serial.print(" ");
                       }
                   }
                   mySerial1.write(0xFF);
                   mySerial1.write(0xFF);

delay(5000);
}
