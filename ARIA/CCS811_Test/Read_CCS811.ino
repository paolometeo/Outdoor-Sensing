void Read_CCS811(){
    if(ccs.available()){
    Temp811 = ccs.calculateTemperature();
    if(!ccs.readData()){
       ppmCO2 = ccs.geteCO2();
       ppbVOC = ccs.getTVOC();  
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
}
