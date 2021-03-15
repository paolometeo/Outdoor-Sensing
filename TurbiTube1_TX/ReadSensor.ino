void ReadSensor(){
  //  take measures
    digitalWrite(MosfetPin,LOW);  // switch on sensor power
    altDelay(100);
    minni.Data17899.Value = analogRead(SensorPin);  // read sensor
    altDelay(10);
    if(ECHO){
      Serial.print(" Value ");Serial.println(minni.Data17899.Value);
    }
    digitalWrite(MosfetPin,HIGH);   // switch off sensor power
}
