//  Ritarda di Period secondi

void altDelay(int Period, byte cd){
     float TimeNow;
     float TimePassed;
     int ii;
     
     int Per = Period;
     for(ii = Per; ii >=0; ii--){
       int MM = ii/60;
       int XX = ii - MM*60;
       if(cd){
         Serial.print(MM);Serial.print(" ");Serial.println(XX);
       }
       TimeNow = millis();
       TimePassed = 0;
       while(TimePassed < 983.3){
         TimePassed = millis()-TimeNow;
       }
     }
}
