void ReadSensor(){
  //  take measures
  minni.Data30003.Humi = SHT2x.GetHumidity();  // read sensor
  minni.Data30003.Temp = SHT2x.GetTemperature();  // read sensor

  if(ECHO){
       Serial.println();
       Serial.print(" Temp ");
       Serial.print(minni.Data30003.Temp,1);
       Serial.print(" Humi ");
       Serial.print(minni.Data30003.Humi,1);
       Serial.println();
  }
}
