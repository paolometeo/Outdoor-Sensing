  void SerialTransmit2(){

//  verso ESP  AAAA..payload..Ch,FFFF  dove Ch è la somma di tutto il payload modulo 256
//  verso DataLogger  AAAA..payload..nRSSI,Ch,FFFF  dove Ch è la somma di tutto il payload modulo 256

//  Calcola il check sum
                   word sum = 0;
                   for(i = 0; i < Length; i++){
                       sum = sum + buf[i]; 
                   }
                   buf[Length]= sum % 256;
   
// trasmette verso ESP
                  mySerial1.write(0xAA);
                  mySerial1.write(0xAA);
                  for(i = 0; i <= Length; i++){
                       mySerial1.write(buf[i]); 
                  }
                  mySerial1.write(0xFF);
                  mySerial1.write(0xFF);
//
                  if(ECHO){
                    Serial.println();
                    Serial.println(" Trasmesso verso ESP");
                    Serial.print("AA");Serial.print(" ");
                    Serial.print("AA");Serial.print(" ");
                    for(i = 0; i <= Length; i++){
                       Serial.print(buf[i],HEX);Serial.print(" "); 
                    }
                    Serial.print("FF");Serial.print(" ");
                    Serial.print("FF");Serial.println(" ");
                    for(i = 0; i <= Length; i++){
                       Serial.print(buf[i]);Serial.print(" "); 
                    }
                    Serial.println(" ");
                  }
                  
//  trasmette verso il Datalogger
                  buf[Length] = lowByte(nRSSI);  
                  buf[Length+1] = highByte(nRSSI);   
                  sum = sum + nRSSI;
                  buf[Length+2]= sum % 256;
//                  
                  mySerial2.write(0xAA);
                  mySerial2.write(0xAA);
                   for(i = 0; i <= Length+2; i++){
                       mySerial2.write(buf[i]); 
                   }
                   mySerial2.write(0xFF);
                   mySerial2.write(0xFF);
//
                  if(ECHO){
                    Serial.println();
                    Serial.println(" Trasmesso verso Datalogger");
                    Serial.print("AA");Serial.print(" ");
                    Serial.print("AA");Serial.print(" ");
                    for(i = 0; i <= Length+2; i++){
                       Serial.print(buf[i],HEX);Serial.print(" "); 
                    }
                    Serial.print("FF");Serial.print(" ");
                    Serial.print("FF");Serial.println(" ");                   
                    for(i = 0; i <= Length+2; i++){
                       Serial.print(buf[i]);Serial.print(" "); 
                    }
                    Serial.println(" ");
                  }
 } 
