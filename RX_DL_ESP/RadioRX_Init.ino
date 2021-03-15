void RadioRX_Init(){
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);

  pinMode(LEDpin, OUTPUT);    
  if(LEDpin == 17){ 
     digitalWrite(LEDpin,HIGH);
  else{
     digitalWrite(LEDpin,LOW);
  }
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

// Init Serial Monitor
if(ECHO){
  while (!Serial);  
  Serial.begin(57600);
  delay(100);
  Serial.println("ProMicroLora_RX_OLED.ino");
}
  // manual reset of Radio Module
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

//  Serial initialization (don't use lower speed)
// mySerial1  to ESP 
  mySerial1.begin(57600); 
  delay(1000);
  
//  mySerial2  to Iteaduino or Arduino Datalogger
  mySerial2.begin(57600);  
  delay(1000);
  
// radio initialization
  while (!rf95.init()) {
    if(ECHO){
    Serial.println("LoRa radio init failed");
    }
    while (1);
  }
  
    if(ECHO){
      Serial.println("LoRa radio init OK!");
    }
  
// Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
// The default transmitter power is 13dBm, using PA_BOOST.
// If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then 
// you can set transmitter powers from 5 to 23 dBm:

/*  
 *   rf95.setTxPower(23, false); 
 *   rf95.setModemConfig(rf95.Bw31_25Cr48Sf512);
 *   rf95.setModemConfig(rf95.Bw125Cr45Sf128);
 *   rf95.setModemConfig(rf95.Bw125Cr48Sf4096);
 
Bw125Cr45Sf128   Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on. Default medium range. 
Bw500Cr45Sf128  Bw = 500 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on. Fast+short range. 
Bw31_25Cr48Sf512  Bw = 31.25 kHz, Cr = 4/8, Sf = 512chips/symbol, CRC on. Slow+long range. 
Bw125Cr48Sf4096   Bw = 125 kHz, Cr = 4/8, Sf = 4096chips/symbol, CRC on. Slow+long range. 
*/
}
