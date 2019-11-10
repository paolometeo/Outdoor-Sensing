  void WiFi_Transmit(){
      buono = 0;
     
      //   in base all'identificativo chiama la funzione giusta
      if (ID_TX == 30001) {
        http30001();
        buono = 1;
      }
      if (ID_TX == 30002) {
        http30002();
        buono = 1;
      }
      if (ID_TX == 30003) {
        http30003();
        buono = 1;
      }
      if (ID_TX == 30004) {
        http30004();
        buono = 1;
      }
      if (ID_TX == 30005) {
        http30005();
        buono = 1;
      }
      if (ID_TX == 17899) {
        http17899();
        buono = 1;
      }
      if (ID_TX == 43998) {
        http43998();
        buono = 1;
      }
      
      //  scrive su Exosite e l'interroga per avere i dati ricevuti
      if(buono > 0 && TrasmettiExosite){
         if (exosite.writeRead(TotalString, readString, returnString)) {
            if (ECHO) {
                 Serial.println(" OK");
                 Serial.print(" Reply from Exosite: ");
                 Serial.println(returnString);
            }
         }
      }else {
        if (ECHO) {
          Serial.println("Error");
        }
      }
      Serial.println(" sono qui ");    
 }
 
