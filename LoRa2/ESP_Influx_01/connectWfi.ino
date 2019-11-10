/*==============================================================================
* connectWifi
*
* Use in setup to connect to local Wifi network
*=============================================================================*/
void connectWifi() {

// Create MAC Address String in the format FF:FF:FF:FF:FF:FF
byte macData[WL_MAC_ADDR_LENGTH];
char macString[18];  

//  Memorizza le credenziali delle varie reti
wifiMulti.addAP("WeMake00", "wemakemilano!");

// Connessione alla rete mediante la ricerca di quella più forte
  if(ECHO)Serial.println("Connecting ...");
  i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { 
    // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(1000);
    if(ECHO)Serial.print('.');
  }
  if(ECHO){
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer
  }

// Used to store a formatted version of the MAC Address 
WiFi.macAddress(macData);
snprintf(macString, 18, "%02X%02X%02X%02X%02X%02X",
         macData[5], macData[4], macData[3], macData[2], macData[1], macData[0]);
           
// Print Some Useful Info
  if(ECHO){
    Serial.print(F("wifi: MAC Address: "));
    Serial.println(macString);
  }
}
