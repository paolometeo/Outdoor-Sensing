// Geiger
void Print43998(){
      if(ECHO){
         Serial.print(minni.Data43998.uSvh);Serial.print(" "); 
         Serial.print(minni.Data43998.countPeriod);Serial.print(" "); 
         Serial.println();
      }
      lcd.clear();
      lcd.print("#");lcd.print(ID_TX);lcd.print(" ");
      if(npacket > 9999){
           npacket = 0;
      }
      lcd.print(npacket);lcd.print(" R");lcd.print(nRSSI,0);
      lcd.setCursor(0, 1);
      lcd.print("B");lcd.print(vBatTX);lcd.print(" ");
// you can change this
      lcd.print(minni.Data43998.uSvh);lcd.print(" uSv/h");
}
