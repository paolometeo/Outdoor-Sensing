void ReadSDS(){
    int i = 0;
    if(mySerial.available() > 0){
       received[0]= mySerial.read();
       if(received[0] == 0xAA){
          i++;
          while(i < 10){
             while(mySerial.available()== 0){}
                received[i]=mySerial.read();  
                 i++;
          }   
          if(ECHO){ 
             Serial.println(" Nuova lettura ");
             for(i = 0; i < 10; i++){
                 Serial.print(received[i],HEX);Serial.print(" ");
             }
             Serial.println();
          }
          if(received[9] == 0xAB){
//  Valori in ug/m3 con una cifra decimale
             float FPM25 = received[3]*256+float(received[2])/10;
             float FPM10 = received[5]*256+float(received[4])/10;
          if(ECHO){
              Serial.print(" PM2.5: ");Serial.print(FPM25);
              Serial.print(" PM10: ");Serial.println(FPM10);
          }
          }
    }
  }
}
