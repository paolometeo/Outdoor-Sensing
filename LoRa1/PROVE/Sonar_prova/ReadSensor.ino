void ReadSensor(){
  //  take measures
  long Tempo;

  Tempo = 0;
  digitalWrite(pinTrigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger,LOW);
  long Start = micros();
  while(digitalRead(pinEcho)){
    break;
  }
      Tempo = micros()-Start;
      Serial.println(Tempo);
  
  minni.Data30004.Dist =   Tempo*34000/2./1000000.0;  // Tempo in microseconds

  if(ECHO){
       Serial.println();
       Serial.print(" Dist ");
       Serial.print(minni.Data30004.Dist,1);
       Serial.println();
  }
}
