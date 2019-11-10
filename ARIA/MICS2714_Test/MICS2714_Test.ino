/*
 * Test sketch for gas sensor MICS2714 for NO2 and H2
 * 
 * wiring
 * MICS2714     Arduino     R-heater 131ohm   R-load 22Kohm
 *                                            NO2seriesResistor
 * A                             X
 *               GND             X                X
 * B              A0                              X
 * J             +5V
 * H             +5V
 * 
 * Paolo Bonelli  08/02/2019
 * Siddharth D’Souza et al. 2017
 * 
 */

byte   NO2pin = A0;               //Define pin variable
int    NO2seriesResistor = 22000; //Load Resistance
float  RSsuR0 = 0;
float  Coeff = 0.15041;  // Concentration (ppm) = Coeff * Rs/R0
float  PPM = 0;  //Concentration NO2 in ppm
int    nSample = 1;
float  R0_NO2 = 0;
float  ppmNO2 = 0;
/////////////////////////////////////////////////////////
void setup(){
  pinMode(NO2pin, INPUT); //Within the setup set pin A0 as input
  Serial.begin(9600);
  delay(1000);
  Serial.println(" MICS2714 Test ");
  Serial.println(" Wait for heating ");
  altDelay(30,1);
  
//  Measure Sensor Resistance in Clean Air and compute R0_NO2
  Serial.println(" Rs in clean air for computing R0");
  float sum = 0;
  for(int i = 0; i < nSample; i++){
     Read_MICS(NO2pin,1);
     sum = sum + R0_NO2;
     altDelay(1,0);
  }
  Serial.println();
  Serial.print("Valore di fondo di R0: "); Serial.println(R0_NO2,0);
  R0_NO2 = sum/float(nSample);  // valore di fondo che rappresenta R0
  Serial.print("R0: "); Serial.println(R0_NO2,0);
  altDelay(10,0);
  Serial.println(" Now you can measure your air ");
}
///////////////////////////////////////////////////////////////////
void loop() {
Serial.println();
Read_MICS(NO2pin,0);
altDelay(5,0);
}
