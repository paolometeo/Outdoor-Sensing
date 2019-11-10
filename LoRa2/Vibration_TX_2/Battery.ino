void Battery(){
//  Read the battery voltage in mV 
float measuredvbat = analogRead(VBATPIN);

//  Rapporto del partitore 2
measuredvbat *= 3.3; // Multiply by 3.3V, our reference voltage
measuredvbat /= 1024; // convert to voltage
measuredvbat *= 2.0; // we divided by 2, so multiply back
measuredvbat = measuredvbat *1000;  //  convert in mV
vBatTX = Nword(measuredvbat);
}
