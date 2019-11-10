void SerialReceive(){
           ID_TX =      word(buf[1],buf[0]);
           Length =     word(buf[3],buf[2]);
           vBatTX =     word(buf[5],buf[4]);
           npacket =    word(buf[7],buf[6]);      
           for(ii = 8;ii < Length; ii++){
                 minni.bufVar[ii-8] = buf[ii];
           }
           if(ECHO){    
                Serial.println();
                Serial.println("  Message Received from Serial ");
                Serial.print(" Length ");Serial.print(Length);
                Serial.print(" ID_TX ");Serial.print(ID_TX);
                Serial.print(" vBatTX ");Serial.print(vBatTX);
                Serial.print(" npacket ");Serial.print(npacket);
                Serial.println();
           }
}
