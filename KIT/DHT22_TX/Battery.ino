void Battery(){
//  Battery Power  Legge la tensione della pila e la converte in mV interi
word outanalog = analogRead(VBATPIN);
//Serial.println(outanalog);
float measuredvbat = 3300.0 * 2 * float(outanalog)/1023.0;
vBatTX = Nword(measuredvbat);
}
