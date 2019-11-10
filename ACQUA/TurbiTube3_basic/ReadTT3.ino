 void ReadTT3(){
  
//sample light, return reading in frequency
//higher number means brighter
  int readings = 0;
  float duration = 0;
  
  digitalWrite(OEpin,LOW);  //  accende sensore
  delay(100);

//  take measure with LED off
  digitalWrite(Gatepin,LOW);  
  delay(10);
  duration = 0;
  readings = 0;
  while(readings < samples){
      
   // Works on pulses from 10 microseconds to 3 minutes in length. 
   //  restituisce il tempo in microsecondi tra il primo impulso HIGH 
   //  e il successivo LOW
         duration = duration + pulseIn(OUTpin, HIGH);
         readings ++;
   }
   lightLevel1 = 1000000/ (duration / samples);
   
//  take measure with LED on
    digitalWrite(Gatepin,HIGH);  
    word iniz = millis();
//    Serial.println(iniz);
    delay(10);
    duration = 0;
    readings = 0;
    while(readings < samples){
      
   // Works on pulses from 10 microseconds to 3 minutes in length. 
   //  restituisce il tempo in microsecondi tra il primo impulso HIGH 
   //  e il successivo LOW
         duration = duration + pulseIn(OUTpin, HIGH);
         readings ++;
     }
     word tempo = millis()-iniz;
//     Serial.print("  Tempo accensione ");Serial.println(tempo);
     lightLevel2 = 1000000/ (duration / samples);
     Ratio = lightLevel2 / lightLevel1;   
}
