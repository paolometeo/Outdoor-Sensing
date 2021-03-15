void altDelay(uint32_t Period){
     float TimePassed = 0;
     float TimeOld = 0;
     
     uint32_t Per = Period;
       TimeOld = millis();
       TimePassed = millis()-TimeOld;
       while(TimePassed < Period){
         TimePassed = millis()-TimeOld;
       }
}
