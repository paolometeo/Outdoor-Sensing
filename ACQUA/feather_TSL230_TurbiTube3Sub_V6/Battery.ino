void Battery(){
  //  Battery Power  Legge la tensione della pila e la converte in mV interi
float measuredvbat = analogRead(VBATPIN);
//Serial.println(measuredvbat);
measuredvbat *= 2; // we divided by 2, so multiply back
measuredvbat *= 3.3; // Multiply by 3.3V, our reference voltage
measuredvbat /= 1024; // convert to voltage
measuredvbat = measuredvbat *1000;
vBatTX = nword(measuredvbat);
}
