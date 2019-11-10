// PIR
void http30001(){

   String writeString1 = "PIR_vBatTX_1=";
   String writeString2 = "&PIR_npacket_1=";
   String writeString3 = "&PIRstatus_1=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);

//  trasformazione da formato numerico a carattere parte variabile
   String SPIR = String(minni.Data30001.PIRstatus);
//
  if(ECHO){
    Serial.print( " PIRstatus ");Serial.print(minni.Data30001.PIRstatus);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SPIR ;
    readString =  writeString1 + writeString2 + writeString3;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }
}  
