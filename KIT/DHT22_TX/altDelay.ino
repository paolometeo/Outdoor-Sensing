void altDelay(int Period){
     float TimePassed = 0;
     float TimeOld2 = 0;
     
     int Per = Period;
       TimeOld2 = millis();
       TimePassed = millis()-TimeOld2;
       while(TimePassed < Period){
         TimePassed = millis()-TimeOld2;
       }
}
