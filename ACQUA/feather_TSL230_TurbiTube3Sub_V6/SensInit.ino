void SensInit(){
    pinMode(OEpin,OUTPUT);
    pinMode(OUTpin,INPUT);
    pinMode(Gatepin,OUTPUT); 
//
    ID_TX = 51515;
    Length = 16;
    digitalWrite(Gatepin, LOW);  // spegne LED
    digitalWrite(OEpin,HIGH);  //  spegne sensore
}
