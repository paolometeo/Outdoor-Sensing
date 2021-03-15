void SensInit(){
  pinMode (MosfetPin,OUTPUT);
  digitalWrite(MosfetPin,HIGH); // pullup resistor
}
