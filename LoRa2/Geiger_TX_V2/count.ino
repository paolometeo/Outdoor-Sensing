void count(){
  n++;
   digitalWrite(LedPin,HIGH);  
   delay(30);
   digitalWrite(LedPin,LOW);   
   
/* 
    if(CPM <= CPM1){
       altDelay(100);
    }
    */
//    digitalWrite(LedPin,LOW);
    tone(SoundPin,900,100);
  if(n > 65000){
    n = 65000;
  }
}
