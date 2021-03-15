byte Receive(){
    byte Received = 0;
    Received = rf95.available();
    if(Received){

    // Should be a message for us now   
    len = sizeof(buf);
    if (rf95.recv(buf, &len)){
      Blinking();    
      if(ECHO){
         Serial.println();
         RH_RF95::printBuffer("************** Received: ", buf, len);
      }     
      ID_TX =      word(buf[1],buf[0]);
      Length =     word(buf[3],buf[2]);
      vBatTX =     word(buf[5],buf[4]);
      npacket =    word(buf[7],buf[6]);      
      nRSSI   =   word(-1*rf95.lastRssi());
      Serial.print(" nRSSI = ");Serial.println(nRSSI);
      if(len != Length){
        if(ECHO){
         Serial.println(" Length not permitted ");
        }
        Received = 0;
        return Received;
      }
      for (i = 8; i < Length; i++){
        minni.bufVar[i-8] = buf[i];
      } 
      if(ECHO){
         Serial.println("  bufVar content ");
        for (i = 8; i < Length; i++){
           Serial.print(minni.bufVar[i-8],HEX); Serial.print(" ");
        }    
        Serial.println(); 
        Serial.print("ID_TX ");Serial.print(ID_TX);
        Serial.print(" Length ");Serial.print(Length);
        Serial.print(" vBatTX ");Serial.print(vBatTX);
        Serial.print(" npacket ");Serial.print(npacket); 
        Serial.print(" nRSSI ");Serial.print(nRSSI);
        Serial.println();
      }
    }else{   
         if(ECHO){
           Serial.println("Receive failed");
         }         
    } 
    //  Display OLED
    display.clearDisplay();
    delay(500);
    display.setTextSize(2);  //  2 x 10 character
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(ID_TX);display.print(" ");
//
  if(npacket > 9999){
    npacket = npacket%10000;
  }
   word vB = Nword(float(vBatTX)/100.0);
   display.print("N");display.print(npacket);
//   display.setCursor(0,16);
   display.print(" ");display.print("B");display.print(vB);
   display.print(" ");display.print("R");display.print(nRSSI);
   display.display(); 
 }
  delay(1000);    
  return Received;
}
