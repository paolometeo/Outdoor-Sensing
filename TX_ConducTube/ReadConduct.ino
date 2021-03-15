void ReadConduct(){
  /*
Collegamenti hardware

pin1 ------O  O----pin2-----R1--------pin3     Lato sensore

D3                 A0       2200        D5      Lato ProMicroLoRa
 +                  <---------Vo1-------GND
 GND--------Vo2----->                    +
                    
*/
float runningAvg1 = 0;  // sum of the voltage values at PIN1 and their average
float runningAvg2 = 0;  // sum of the voltage values at PIN2 and their average
float runningAvg3 = 0;  // sum of the voltage values at PIN3 and their average
int   i = 0;
int   nmilli = 50;  // time laspse between power on and measure
int   n = 10;
float R1 = 3266.;  // ohm da adattare
float RS = 0.;
float RS1 = 0.;
float RS2 = 0.;
float VCC = 3.3;
float Vconv = VCC/1023.;
float Vo1=0.;
float Vo2=0.;
float VSG=0.;
float fact = 0;
float temperC = 0;
float CS = 0;
float CSspec = 0;

         //  MISURA DELL CONDUCIBILITA'
       runningAvg1 = 0;
       runningAvg2 = 0;
       runningAvg3 = 0;
       
        for(i = 0; i < n; i++){
        // sensor power supply for measuring Vo1: PIN1 on and PIN3 off
           digitalWrite(PIN1,HIGH);
           digitalWrite(PIN3,LOW);
           delay(nmilli);
           runningAvg1 =  runningAvg1 + Vconv*analogRead(PIN2);
        //  misura la galvanica
           digitalWrite(PIN1,LOW);
           delay(nmilli);
           runningAvg2 =  runningAvg2 + Vconv*analogRead(PIN2);
        // sensor power supply for measuring Vo2: PIN1 off and PIN3 on
           digitalWrite(PIN3,HIGH);
           delay(nmilli);
           runningAvg3 =  runningAvg3 + Vconv*analogRead(PIN2);
       }
           digitalWrite(PIN1,LOW);
           digitalWrite(PIN3,LOW);
       
         VSG = runningAvg2/n;
         Vo1 = runningAvg1/n;      
         Vo2 = runningAvg3/n;   
         
          if(ECHO){
          Serial.println(" -----------------Misure--------------- ");
          Serial.print("  Galvanica: ");
          Serial.print(VSG);
          Serial.print("  Vo1 = ");
          Serial.print(Vo1,2);
          Serial.print(" Vo2 = ");
          Serial.println(Vo2,2);
        }               
 //  compute RS1
        if(Vo1 < 0.004){
            RS1 = 99999.;
         }
    else{
//  correggo con la galvanica
        Vo1 = Vo1-VSG;
//  primo calcolo di RS
        RS1 = R1*(VCC-Vo1)/Vo1;
       } 
       
//  secondo calcolo di RS e media con il precedente
        Vo2 = Vo2-VSG;
        if(abs(VCC-Vo2) < 0.004){
          RS2 = 99999.;
        }else{
          RS2 = R1*Vo2/(VCC-Vo2);
        }
        
//  fa la media tra i due valori
        if(RS1 < 40000. && RS2 < 40000.){
          RS = (RS1 + RS2)/2; 
          if(RS < 50.){
            CS = 0;
            CSspec = 0;
          }
          else{
            
 //  temperatura:  se manca il dato lo pone a 20.0 per un fattore di correzione = 1
              temperC = minni.Data16133.WTemp;
              if(temperC == 999)temperC = 20.0;
 
// calcola la conducibilità in uS e la corregge per la temp
//            fact = 0.0007*pow(temperC,2)-0.0509*temperC+1.7221;
              fact = 1/(1.111 +0.0222*(temperC - 25));   //  approssimazione lineare, va bene tra 10 e 30 gradi
              CS = fact*1000000/RS;
              CSspec = 0.000008*pow(CS,3)-0.0023*pow(CS,2)+0.8438*CS; // taratura del 22/9/2015
          }
          minni.Data16133.WCS = Nword(CS);
          minni.Data16133.WCSspec = Nword(CSspec);
        }
        else{
          RS = 99999.;
          CS = 99999.;
          CSspec = 99999.;     
          minni.Data16133.WCS = 65000;
          minni.Data16133.WCSspec = 65000;    
        }
    if(ECHO){    
         Serial.print("  RS1 = ");
         Serial.print(RS1,0);
         Serial.print("  RS2 = ");
         Serial.print(RS2,0);
         Serial.print("  RS = ");
         Serial.print(RS,0);
         Serial.print("  CS = ");
         Serial.print(CS,0);  
         Serial.print(" CSspec = ");
         Serial.println(CSspec); 
      }
}
