void ReadSensor(){
  //  take measures
    digitalWrite(MosfetPin,HIGH);  // switch on sensor power
    delay(100);
    minni.Data17899.Value = analogRead(SensorPin);  // read sensor
    delay(10);
    if(ECHO){
      Serial.print(" Value ");Serial.println(minni.Data17899.Value);
    }
    digitalWrite(MosfetPin,LOW);   // switch off sensor power
}
