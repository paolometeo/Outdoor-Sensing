void ReadSensor(int samples){
  float lightLevel1;
  float lightLevel2;

      //  swith off LED and sensor
    digitalWrite(Gatepin, LOW);  // spegne LED
    altDelay(100);
    lightLevel1 = readTSL230(samples);  // misura la luce di fondo
    altDelay(1000);

     //  with LED on
    digitalWrite(Gatepin, HIGH);                     //  accende il LED
    altDelay(100);
    lightLevel2 = readTSL230(samples);  // misura la luce diffusa dal led

  //  elabora i dati
    minni.Data51515.Ratio = lightLevel2 /lightLevel1;
    minni.Data51515.Level1 = Nword(lightLevel1);
    minni.Data51515.Level2 = Nword(lightLevel2);

    if (ECHO) {
      Serial.println();
      Serial.println(" New Sample ");
      Serial.print(" Spento "); Serial.print(lightLevel1);
      Serial.print(" Acceso "); Serial.println(lightLevel2);
      Serial.print(" word "); Serial.print(minni.Data51515.Level1); Serial.print(" "); Serial.println(minni.Data51515.Level2);
      Serial.print(" Ratio "); Serial.println(minni.Data51515.Ratio); 
    }

}
////////////////////////////////////////////////
float readTSL230(int samples){
//sample light, return reading in frequency
//higher number means brighter

  float start = micros();  
  int readings = 0;
  while(readings < samples){
   // Works on pulses from 10 microseconds to 3 minutes in length. 
   //  restituisce il tempo in microsecondi tra il primo impulso HIGH 
   //  e il successivo LOW
   pulseIn(OUTpin, HIGH);
   readings ++;
  }
  float length = micros() - start;
  float freq = (1000000 / (length / samples));
  return freq;
}
