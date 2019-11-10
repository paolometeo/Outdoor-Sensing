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
//  pinMode(6, INPUT);
//  pinMode(5, OUTPUT);

// Init Serial Monitor
    Serial.begin(115200);
    Serial.println("ProvaTrasmissioneRX");
    delay(1000);
  
//  Init Software Serial 
  mySerial1.begin(57600);
  delay(1000);
    Serial.println(" Seriali inizializzate");
    i = 0;
    flag = 0;
}


void loop() {

// messaggio che inizia con AAAA e finisce con FFFF
      if(mySerial1.available() > 0){ 
         primo = mySerial1.read();
         Serial.println(primo,HEX);
         if      (primo == 0xAA && flag == 0){  // trova un primo AA
           flag = 1;   
         }else if(primo == 0xAA && flag == 1){  // trova un secondo AA subito dopo il primo
           flag = 2;
           Serial.println(" inizio ");
         }else if(primo != 0xAA && flag == 1){  // trova un carattere diverso dopo il primo
           flag = 0;          
         }else if(primo != 0xAA && flag == 2 && primo != 0xFF){
          buf[i] = primo;
          i++;
         }else if(primo == 0xFF && flag == 2){
          flag = 3;
         }else if(primo == 0xFF && flag == 3){
            Serial.println(" fine");
           //  finisce messaggio
           nbyte = i;
           for(i = 0; i < nbyte; i++){
            Serial.print(buf[i],HEX);Serial.print(" ");
           }
           Serial.println();
           mySerial1.flush();
           i = 0;
           flag = 0;
           primo=0;
         } 
       }
}
