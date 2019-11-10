// porta 6
#include <SoftwareSerial.h>
SoftwareSerial mySerial1(4, 6); // RX, TX
byte primo;
byte buf[50];
int i = 0;
int nbyte=0;
byte flag = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(4, INPUT);
//  pinMode(6, OUTPUT);

// Init Serial Monitor
    Serial.begin(115200);
    Serial.println("ProvaTrasmissioneRX_v2");
    delay(1000);
  
//  Init Software Serial 
  mySerial1.begin(57600);
  delay(1000);
    Serial.println(" Seriali inizializzate");
    i = 0;
}


void loop() {
  
      if(mySerial1.available() > 0){
         primo = mySerial1.read();
         if(primo != 0){
         Serial.print(primo,HEX);Serial.print(" ");
         }
         i++;
         if(i > 17){
          Serial.println();
          i=0;
         }
       }
}
