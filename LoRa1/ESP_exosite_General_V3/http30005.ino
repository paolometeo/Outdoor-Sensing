//  Dust
void http30005(){
  
   String writeString1 = "DUST_vBatTX_1=";
   String writeString2 = "&DUST_npacket_1=";
   String writeString3 = "&DUST_Conc10=";
   String writeString4 = "&DUST_Conc25=";
   String writeString5 = "&DUST_TEMP=";
   String writeString6 = "&DUST_UMID=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);

//  trasformazione da formato numerico a carattere parte variabile
   String SConc10 = String(minni.Data30005.Conc10,0);
   String SConc25 = String(minni.Data30005.Conc25,0);
   String STEMP = String(minni.Data30005.TEMP,1);
   String SUMID = String(minni.Data30005.UMID,1);
//
  if(ECHO){
    Serial.print( " Conc10 ");Serial.print(minni.Data30005.Conc10);
    Serial.print( " Conc25 ");Serial.print(minni.Data30005.Conc25);
    Serial.print( " TEMP ");Serial.print(minni.Data30005.TEMP);
    Serial.print( " UMID ");Serial.print(minni.Data30005.UMID);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SConc10 + writeString4 + SConc25 +  writeString5 + STEMP + writeString6 + SUMID;
    readString =  writeString1 + writeString2 + writeString3 + writeString4;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }
}
