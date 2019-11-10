void ReadPH(){
    int measure = analogRead(ph_pin);
    voltage = 5.0 / 1023.0 * measure; //classic digital to voltage conversion
    if(ECHO){
       Serial.print("Measure: ");
       Serial.print(measure);
       Serial.print(voltage, 3);
    }
    if(voltage >=2.5 ){
   
    //  acid
       PH_probe = 7.0 - (voltage - voltagePH700) /AcidStep;
    }else{
    
    //  Basic
       PH_probe = 7.0 + (voltagePH700 - voltage) /BasicStep;
  }
  if(ECHO){
     Serial.print(" Voltage: ");
     Serial.print(voltage, 3);Serial.print(" PH_probe ");Serial.println(PH_probe);
  }
}
