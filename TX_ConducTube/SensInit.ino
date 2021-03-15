  void SensInit(){
  pinMode     (PIN1,OUTPUT);
  pinMode     (PIN3,OUTPUT);
  pinMode     (TmpPinVcc,OUTPUT);
  
    //  Initializing the Temperature sensor
        digitalWrite(TmpPinVcc,HIGH);
  sensors.begin();
  delay(2000);
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
  if(ECHO){
     // locate devices on the bus
    Serial.print("Locating devices..."); 
    Serial.print("Found ");
    Serial.print(numberOfDevices, DEC);
    Serial.println(" devices.");

  // report parasite power requirements
    Serial.print("Parasite power is: "); 
    if (sensors.isParasitePowerMode()) Serial.println("ON");
    else Serial.println("OFF");
  }
  
  // Loop through each device, print out address
  for(int i=0;i<numberOfDevices; i++){
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)){
    if(ECHO){
      Serial.print("Found device ");
      Serial.print(i, DEC);
      Serial.print(" with address: ");
      printAddress(tempDeviceAddress);
      Serial.println();
      Serial.print("Setting resolution to ");
      Serial.println(TEMPERATURE_PRECISION, DEC);
    }
    // set the resolution to TEMPERATURE_PRECISION bit (Each Dallas/Maxim device is capable of several different resolutions)
    sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
    if(ECHO){
       Serial.print("Resolution actually set to: ");
       Serial.print(sensors.getResolution(tempDeviceAddress), DEC); 
       Serial.println();
    }
  }else{
    if(ECHO){
      Serial.print("Found ghost device at ");
      Serial.print(i, DEC);
      Serial.print(" but could not detect address. Check power and cabling");
    }
  }  
  }
      digitalWrite(TmpPinVcc,LOW);

}
