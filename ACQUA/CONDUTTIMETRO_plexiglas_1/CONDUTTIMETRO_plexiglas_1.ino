/*
 Programma per Conduttimetro fatto da due bulloni e involucro plexiglas
Collegamenti hardware

rosso    bulloni  blu    resistenza  bianco
PIN1------O  O----PIN2-----RRRRR-----PIN3     Lato sensore

D3                 A0     1000 ohm    D5      Lato ProMicroLoRa

Paolo Bonelli 12/06/2019
 */


#define PIN1  3
#define PIN2  A0
#define PIN3  5

float CS =       0.;
float CSspec =   0.;
float Temp =     0.;

/////////////////////////////////////////////
void setup() {
  pinMode     (PIN1,OUTPUT);
  pinMode     (PIN3,OUTPUT);

  //  Initializing the serial monitor
    Serial.begin(9600);
    delay(100);
    Serial.println(" CONDUTTIMETRO_plexiglas_1.ino ");
    Serial.println(" Misura la conducibilità corretta con la temperatura")
    Serial.println(" ma non la specifica");
  }
//////////////////////////////////////////////////////////////////////////////
void loop() {
    
  //  take measures
    ReadConduct();
    delay(1000);
  }
