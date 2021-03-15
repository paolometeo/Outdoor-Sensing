void ReadTemp(){
  float Temp = 0;
  digitalWrite(TmpPinVcc,HIGH);
  sensors.requestTemperatures(); // Send the command to get temperatures  
  
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++){
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i)){
    // Output the device ID
       Temp = sensors.getTempC(tempDeviceAddress);
       if(ECHO){
          Serial.print("Temperature for device: ");
          Serial.print(i,DEC); Serial.print(" "); printAddress(tempDeviceAddress);
          Serial.print(" Temp = ");Serial.println(Temp); 
       }
   }
   if(Temp < -10.0 || Temp > 40){
          minni.Data16133.WTemp = 999;
   }else{
       minni.Data16133.WTemp = Nword(Temp*10);
   }
  delay(2000);
  digitalWrite(TmpPinVcc,LOW);
}
}

////////////////////// function to print a device address//////////////////////////////////
void printAddress(DeviceAddress deviceAddress){
  for (uint8_t i = 0; i < 8; i++){
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
  delay(1000);
}
