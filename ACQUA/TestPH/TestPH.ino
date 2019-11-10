/*
 * TestPH
 * Hardware pH Probe DF-SEN 0161 con scheda BNC a due trimmer e uscita con 6 pin maschi
 * Stampa in uscita le tensioni che legge sul piedino P0, serve per le calibrazioni.
 * 
 * Piedinatura scheda (vista dall'alto, piedini da sinistra)
 * T0:  Should be the temperature but I can't make it works.
 * D0:  High/Low 3.3v adjustable limit.
 * P0:  Analog Output to A0
 * GND: Probe ground. It is useful when the ground is not the same as your Arduino. 
 *      In some circumstances the ground voltage of the liquid to measure can be different.
 * GND: Power ground (direct from Arduino).
 * VCC: + 5 V
 */

const int analogInPin = A0; 
unsigned long int avgValue; 
float phVol = 0;
int buf[10];
int temp = 0;


void setup() {
 Serial.begin(9600);
 delay(100);
 Serial.println(" TestPH.ino ");
}
 
void loop() {

//  Acquisisce 10 valori e li mette nel vettore buf[]
 for(int i=0;i<10;i++){ 
    buf[i]=analogRead(analogInPin);
    delay(30);
 }
 
 // Put them in increasing order
 for(int i=0;i<9;i++){
      for(int j=i+1;j<10;j++){
         if(buf[i]>buf[j]){
            temp=buf[i];
            buf[i]=buf[j];
            buf[j]=temp;
          }
      }
 }
 
 // average  for the inner 6 values (through away the first (min) and the last (Max) values)
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 phVol=(float)avgValue*5.0/(1023.0*6);
 Serial.print("sensor = ");
 Serial.println(phVol);
 delay(500);
}
