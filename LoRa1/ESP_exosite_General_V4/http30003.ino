//  Temp Humi
void http30003(){
  
//  filtro il dato sulla base di quello precedente

   float diff = abs(minni.Data30003.Temp - TempOld);
   if(diff > 10
   String writeString1 = "SH_vBatTX_1=";
   String writeString2 = "&SH_npacket_1=";
   String writeString3 = "&SH_Temp_1=";
   String writeString4 = "&SH_Humi_1=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);

//  trasformazione da formato numerico a carattere parte variabile
   String SH_Temp = String(minni.Data30003.Temp);
   String SH_Humi = String(minni.Data30003.Humi);
//
  if(ECHO){
    Serial.print( " Temp ");Serial.print(minni.Data30003.Temp);
    Serial.print( " Humi ");Serial.print(minni.Data30003.Humi);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SH_Temp  +  writeString4 + SH_Humi ;
    readString =  writeString1 + writeString2 + writeString3 + writeString4;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }
}
