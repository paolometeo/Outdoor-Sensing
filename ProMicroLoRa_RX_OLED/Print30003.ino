//  SHT21
void Print30003(){
      if(ECHO){
         Serial.print(minni.Data30003.Temp);Serial.print(" "); 
         Serial.print(minni.Data30003.Humi);Serial.print(" ");
         Serial.println();
      }
//  Display OLED
    display.clearDisplay();
    delay(500);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("#");display.print(ID_TX);
//
  if(npacket > 9999){
    npacket = 0;
  }
   display.print(" N");display.print(npacket);
   display.print(" R");display.print(nRSSI,0);
   display.setCursor(0,16);
//   float VV = float(vBatTX/1000)
   display.print("V");display.print(vBatTX);
   display.print(" T"); 
   display.print(minni.Data30003.Temp,1);
   display.print(" U"); 
   display.print(minni.Data30003.Humi,1);
   display.display();      
}
