void TT3Init(){
  pinMode(OUTpin,INPUT);
  pinMode(OEpin,OUTPUT);
  pinMode(Gatepin,OUTPUT);
/*configure sensitivity - Can set to
  //S1 LOW  | S0 HIGH: low
  //S1 HIGH | S0 LOW:  med
  //S1 HIGH | S0 HIGH: high
*/
  digitalWrite(Gatepin, LOW);  // spegne LED
  digitalWrite(OEpin,HIGH);  //  spegne sensore

}
