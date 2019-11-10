//  put here instructions for initializing sensors and values for ID_TX and Length
void SensInit(){
  pinMode(PINpower,OUTPUT);
  pinMode(PINLED,OUTPUT);
  pinMode(PIN25,INPUT);
  pinMode(PIN10,INPUT);
  digitalWrite(PINpower,HIGH);
  digitalWrite(PINLED,LOW);
     // Call rht.begin() to initialize the sensor and our data pin
  dht.begin();
  altDelay(1000);
}
