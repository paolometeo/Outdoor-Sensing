// TurbiTube 1
void http17899(){

   String writeString1 = "Turbi_vBatTX_1=";
   String writeString2 = "&Turbi_npacket_1=";
   String writeString3 = "&TurbiValue_1=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);

//  trasformazione da formato numerico a carattere parte variabile
   String SValue = String(minni.Data17899.Value);
//
  if(ECHO){
    Serial.print( " Value ");Serial.print(minni.Data17899.Value);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SValue ;
    readString =  writeString1 + writeString2 + writeString3;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }
}  
