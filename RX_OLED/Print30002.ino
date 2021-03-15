//Put here instruction if you must display or print received message  
void Print30002(){
      if(ECHO){
         Serial.print(" npulse "); 
         Serial.print(minni.Data30002.npulse);
         Serial.print("  sPeriod ");
         Serial.print(minni.Data30002.sPeriod);
         Serial.println();
      }

//  Display OLED
//    display.clearDisplay();
    delay(500);
/*
    display.setTextSize(2);  //  2 x 11 character
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(ID_TX);
//
  if(npacket > 9999){
    npacket = npacket%10000;
  }
  
   word vB = Nword(float(vBatTX)/100.0);
   display.print("N");display.print(npacket);
   display.setCursor(0,16);
   display.print("B");display.print(vB);
   display.print("R");display.print(nRSSI);

   display.print(" ");display.print(minni.Data30002.npulse);
   display.display();   
   */
}
