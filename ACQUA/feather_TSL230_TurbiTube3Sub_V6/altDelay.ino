void altDelay(int Period){
     float TimePassed = 0;
     float TimeOld = 0;
     
     int Per = Period;
       TimeOld = millis();
       TimePassed = millis()-TimeOld;
       while(TimePassed < Period){
         TimePassed = millis()-TimeOld;
       }
}
