/*
 * Sketch di prova del sensore di polvere SDS011 (range 0 - 1000 ug/m3)
 * Hardware: Sensore, Arduino UNO
 * Il sensore trasmette i dati via seriale. 2 parametri: PM2.5 e PM 10 in ug/m3
 * i segnali sono a 3.3 V
 * ATTENZIONE!  Quando si usa la ProMicro, l'unico pin su cui può ricevere il segnale seriale è 8
 * 
 * Wiring
 * Sensore            Arduino
 * 
     TX0              SSRxPin
 *   RX0              SSTxPin  (non serve)
 *   + 5              + 5 
 *   GND              GND
 */

#define SSRxPin 5  
#define SSTxPin 7  
#include <SoftwareSerial.h>  // comunicazione con Feather
SoftwareSerial mySerial(SSRxPin, SSTxPin); //RX, TX   verso ARduino 

byte received[10];
byte ECHO = 1;

void setup() {
  pinMode(SSTxPin, OUTPUT);
  pinMode(SSRxPin, INPUT);
  
  while(!mySerial);
  mySerial.begin(9600);
  delay(1000);
    while(!Serial);
    Serial.begin(9600);
    delay(1000);
  Serial.println(" SDS011_Test.ino");

  }

void loop() {
ReadSDS();
}
 
