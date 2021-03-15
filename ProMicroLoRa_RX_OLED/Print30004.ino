void Print30004(){
  //  SR04  Sonar
      if(ECHO){
         Serial.print(minni.Data30004.Duration);Serial.print(" "); 
         Serial.print(minni.Data30004.Dist,0);Serial.print(" ");
         Serial.println();
      }
//  Display OLED
    display.clearDisplay();
    delay(500);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("#");display.print(ID_TX);
//
  if(npacket > 9999){
    npacket = 0;
  }
   display.print(" ");display.print(npacket);
   display.setCursor(0,16);
   display.print("B");display.print(vBatTX);
   display.print(" V"); 
   display.print(minni.Data30004.Dist);
   display.print(minni.Data30004.Duration);
   display.display();      
}
