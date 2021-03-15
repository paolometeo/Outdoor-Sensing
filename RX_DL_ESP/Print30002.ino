//Put here instruction if you must display or print received message  
void Print30002(){
      if(ECHO){
         Serial.print(" npulse "); 
         Serial.print(minni.Data30002.npulse);
         Serial.print("  sPeriod ");
         Serial.print(minni.Data30002.sPeriod);
         Serial.println();
      }
}
