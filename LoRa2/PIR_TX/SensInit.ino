//  put here instructions for initializing sensors 
void SensInit(){
  pinMode(PIRpin,INPUT);
  digitalWrite(PIRpin,HIGH);
  minni.Data30001.PIRstatus = 0;
}
