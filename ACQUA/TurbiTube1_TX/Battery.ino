void Battery(){
//  Battery Power  Legge la tensione della pila e la converte in mV interi
float measuredvbat = analogRead(VBATPIN);
//  Rapporto del partitore 2.09 / 4.23

measuredvbat *= 3.3; // Multiply by 3.3V, our reference voltage
measuredvbat /= 1024; // convert to voltage
measuredvbat *= 2.023; // we divided by 2, so multiply back
measuredvbat = measuredvbat *1000;  //  convert in mV
vBatTX = Nword(measuredvbat);
}
