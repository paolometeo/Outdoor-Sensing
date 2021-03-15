void Print30003(){
      if(ECHO){
          Serial.print(" Temp ");
          Serial.print(minni.Data30003.Temp);
          Serial.print(" Humi ");
          Serial.print(minni.Data30003.Humi);
         Serial.println();
      }
}
