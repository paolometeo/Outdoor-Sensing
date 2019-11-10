//  put here instructions for initializing sensors and values for ID_TX and Length
void SensInit(){
  pinMode(LedPin,OUTPUT);
  pinMode(SoundPin,OUTPUT);
  digitalWrite(LedPin,LOW);
  period = period2;
}
