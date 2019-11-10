void ReadConduct(){

float Avg1 = 0;
float Avg2 = 0;
float Avg3 = 0;
int   i = 0;
int   nmilli = 50;  //50
int   n = 10;       // number of samples for the average
float R1 = 1000.;  // Constant resistance in ohm
float RS = 0.;
float RS1 = 0.;
float RS2 = 0.;

//   logical voltage of the board
float VCC = 5.0;
float Vconv = VCC/1023.;

float Vo1=0.;
float Vo2=0.;
float VSG=0.;
float fact = 0;
float temperC = 0;

         //  MISURA DELL CONDUCIBILITA'
     Avg1 = 0; 
     Avg2 = 0;
     Avg3 = 0;
       
        for(i = 0; i < n; i++){
          
        // sensor power supply for measuring Vo1: PIN1 on and PIN3 off
           digitalWrite(PIN1,HIGH);
           digitalWrite(PIN3,LOW);
           delay(nmilli);
           Avg1 =  Avg1 + Vconv*analogRead(PIN2);
           
        // no power supply for measuring VSG: PIN1 on and PIN3 off
           digitalWrite(PIN1,LOW);
           delay(nmilli);
           Avg2 = Avg2 + Vconv*analogRead(PIN2);
           
        // sensor power supply for measuring Vo2: PIN1 off and PIN3 on
           digitalWrite(PIN3,HIGH);
           delay(nmilli);
           Avg3 =  Avg3 + Vconv*analogRead(PIN2);
       }

       //  switch off the power to both electrodes
           digitalWrite(PIN1,LOW);
           digitalWrite(PIN3,LOW);

       //   compute averages
         VSG = Avg2/n;
         Vo1 = Avg1/n;      
         Vo2 = Avg3/n; 
           
 //  temperatura
    temperC = Temp;
          Serial.println(" -----------------Misure--------------- ");
          Serial.print("  Galvanica: ");
          Serial.print(VSG);
          Serial.print("  Vo1 = ");
          Serial.print(Vo1,2);
          Serial.print(" Vo2 = ");
          Serial.println(Vo2,2);
                 
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
            
// calcola la conducibilità in uS e la corregge per la temp
            fact = 0.0007*pow(temperC,2)-0.0509*temperC+1.7221;
            CS = fact*1000000/RS;

//  Compute specific conductivity by means a calibration graph
//            CSspec = 0.000008*pow(CS,3)-0.0023*pow(CS,2)+0.8438*CS; // taratura del 22/9/2015
          }
        }
        else{
          RS = 99999.;
          CS = 99999.;
          CSspec = 99999.;     
        }
         Serial.print("  RS1 = ");
         Serial.print(RS1,0);
         Serial.print("  RS2 = ");
         Serial.print(RS2,0);
         Serial.print("  RS = ");
         Serial.print(RS,0);
         Serial.print("  CS = ");
         Serial.print(CS,0);  
//         Serial.print(" CSspec = ");
//         Serial.println(CSspec); 
}
