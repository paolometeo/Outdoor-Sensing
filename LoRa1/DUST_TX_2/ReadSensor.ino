void ReadSensor(){
  byte  flag = 0;
  byte  stat = 0;
  long  startTime = 0;
  long  stopTime = 0; 
  float sum25 = 0;
  float sum10 = 0;
  int   nsample = 20;
  long diff25 = 0;
  long diff10 = 0;

  sum25 = 0;
  sum10 = 0;
  for(int g = 0; g < nsample; g++){
//
      flag = 0;
      while(1){
           stat = digitalRead(PIN25);
           if(stat == 1 && flag == 0){
                startTime = micros();
                flag = 1;
           }
           if(stat == 0 && flag == 1){
                stopTime = micros();  
                diff25 = stopTime - startTime;
                flag = 0;
                break;
           }
       }
       sum25 = sum25 + float(diff25);
//
      flag = 0;
      while(1){
           stat = digitalRead(PIN10);
           if(stat == 1 && flag == 0){
                startTime = micros();
                flag = 1;
           }
           if(stat == 0 && flag == 1){
                stopTime = micros();  
                diff10 = stopTime - startTime;
                flag = 0;
                break;
           }
       }
       sum10 = sum10 + float(diff10);
  }
  sum25 = sum25/nsample;
  minni.Data30005.Conc25 = sum25/1000.0 - 2;  //Conc in ug/m3
  sum10 = sum10/nsample;
  minni.Data30005.Conc10 = sum10/1000.0 - 2;  //Conc in ug/m3
}
