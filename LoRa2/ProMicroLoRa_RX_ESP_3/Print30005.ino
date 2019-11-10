void Print30005(){
  //  Dust
      if(ECHO){
         Serial.print(minni.Data30005.Conc10,0);Serial.print(" "); 
         Serial.print(minni.Data30005.Conc25,0);Serial.print(" ");
         Serial.print(minni.Data30005.TEMP,1);Serial.print(" ");
         Serial.print(minni.Data30005.UMID,1);Serial.print(" ");
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
      lcd.print(minni.Data30005.Conc10,0);lcd.print(" ");lcd.print(minni.Data30005.Conc25,0);
      lcd.print(" ");lcd.print(minni.Data30005.TEMP,0);lcd.print(" ");lcd.print(minni.Data30005.UMID,0);
}
