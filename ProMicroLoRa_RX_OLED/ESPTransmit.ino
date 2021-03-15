/*  
// Uncomment if you need to transmit data to the ESP8266 

  void ESPTransmit(){
                  mySerial1.write(0xAA);
                  mySerial1.write(0xAA);
                   for(i = 0; i < Length; i++){
                       mySerial1.write(buf[i]); 
                       if(ECHO){
                          Serial.print(buf[i],HEX); Serial.print(" ");
                       }
                   }
                   mySerial1.write(0xFF);
                   mySerial1.write(0xFF);
//
                   if(ECHO){
                     Serial.println(" ");
                     Serial.println(" Trasmesso");
                   }
}
*/
