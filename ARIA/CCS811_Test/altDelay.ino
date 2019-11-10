void altDelay(int Period, byte CD){
  //  Period in sec
     float TimeNow;
     float TimePassed;
     int ii;
     
     int Per = Period;
     if(CD){
      Serial.print(" Wait for ");Serial.print(Per); Serial.println(" seconds ");
     }
     for(ii = Per; ii >=0; ii--){
       int MM = ii/60;
       int XX = ii - MM*60;
       if(CD){
          Serial.print(MM);Serial.print(" ");Serial.println(XX);
       }
       TimeNow = millis();
       TimePassed = 0;
       while(TimePassed < 983.3){
         TimePassed = millis()-TimeNow;
       }
     }
}
