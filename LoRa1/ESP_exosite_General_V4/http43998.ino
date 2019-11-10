//  Geiger
void http43998(){
  
   String writeString1 = "Geiger_vBatTX_1=";
   String writeString2 = "&Geiger_npacket_1=";
   String writeString3 = "&Geiger_uSvh_1=";
   String writeString4 = "&Geiger_countPeriod_1=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);

//  trasformazione da formato numerico a carattere parte variabile
   String SuSvh = String(minni.Data43998.uSvh);
   String ScountPeriod = String(minni.Data43998.countPeriod);
//
  if(ECHO){
    Serial.print( " uSv/h ");Serial.print(minni.Data43998.uSvh);
    Serial.print( " count Period (s) ");Serial.print(minni.Data43998.countPeriod);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SuSvh + writeString4 + ScountPeriod;
    readString =  writeString1 + writeString2 + writeString3;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }
}
