void Read_MICS(byte pin, byte air){

//  pin is the analog pin you connect the sensor output
//  air = 1 if you need to compute R0; air = 0 if you need to compute ppm
//  This routine puts output in the global variables R0_NO2 and ppmNO2
// 
//  The background concentration of NO2 for  Milano is 50 ug/m3 = 0.03 ppm 
//  we see from the sensor sensitivity characteristics graph (data-sheet) that at that concentration  Rs/R0 = 0.2
//
      float RSsuR0_back = 0.2;
      float ppmNO2_back = 0.03;
      
//  Load Resistance connected to the sensor
    float  seriesResistor = 22000;  
    
//  Sensitivity characteristics graph
    float  Coeff =  0.1504; // Concentration (ppm) = Coeff * Rs/R0
    
    int    rawInput = analogRead(pin); 
    Serial.print(" rawInput: ");Serial.println(rawInput);
    
//    Calculate the resistance of the sensor
    float resistance = seriesResistor * ((1023.0 / rawInput) - 1.0);
    Serial.print(" Rs        ");Serial.println(resistance);

//    Calculate R0 from background or ppm
    if(air){
      R0_NO2 = resistance/RSsuR0_back;
      ppmNO2 = ppmNO2_back;
      Serial.print(" R0: ");Serial.print(R0_NO2,0);Serial.print("   ppmNO2 background: ");Serial.println(ppmNO2_back);
    }else{
          if(R0_NO2 > 0.1){
             float RSsuR0 = resistance/R0_NO2;
             ppmNO2 = Coeff*RSsuR0;
             Serial.print(" RS/R0: ");Serial.print(RSsuR0);Serial.print("   ppmNO2: ");Serial.println(ppmNO2);
      }else{
        Serial.println(" R0_NO2 not valid ");
      }
   }
}
