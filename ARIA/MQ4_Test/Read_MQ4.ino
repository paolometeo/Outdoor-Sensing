void Read_MQ4(byte pin, byte air){
//  pin is the analog pin you connect the sensor output
//  air = 1 if you need to compute R0; air = 0 if you need to compute ppm
//  This routine puts output in the global variables R0_CH4 and ppmCH4

  // CH4 in the atmosphere  1800 ppb = 1.8 ppm
  //  we see from the sensor sensitivity characteristics graph that at this concentration  Rs/R0 = 9.49
      float ppmCH4_back = 1.8;
      float RSsuR0_back = 9.49;
      
  //Load Resistance
    float  seriesResistor = 20000;  
    
  // Sensitivity characteristics graph
    float  Coeff =  1030.9; // Concentration (ppm) = Coeff * pow(Rs/R0,esp)
    float  esp  =  -2.822;
    
    int    rawInput = analogRead(pin); 
    Serial.print(" rawInput: ");Serial.println(rawInput);

//    Calculate the resistance of the sensor
    float resistance = seriesResistor * ((1023.0 / rawInput) - 1.0);
    Serial.print(" Rs        ");Serial.println(resistance);

//    Calculate R0 in background or ppm
    if(air){
      R0_CH4 = resistance/RSsuR0_back;
      ppmCH4 = ppmCH4_back;
      Serial.print(" R0: ");Serial.print(R0_CH4,0);Serial.print("   ppmCH4 background: ");Serial.println(ppmCH4_back);
    }else{
      if(R0_CH4 > 0.1){
         float RSsuR0 = resistance/R0_CH4;
         ppmCH4 = Coeff*pow(RSsuR0,esp);
         Serial.print(" RS/R0: ");Serial.print(RSsuR0);Serial.print("   ppmCH4: ");Serial.println(ppmCH4);
      }else{
        Serial.println(" R0_CH4 not valid ");
      }
   }
}
