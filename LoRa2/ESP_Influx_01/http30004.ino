//  Dist
void http30004(){
  
   String writeString1 = "DIST_vBatTX_1=";
   String writeString2 = "&DIST_npacket_1=";
   String writeString3 = "&DIST_1=";
   String writeString4 = "&DIST_Durat_1=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);

//  trasformazione da formato numerico a carattere parte variabile
   String SDIST = String(minni.Data30004.Dist);
   String SDIST_Durat = String(minni.Data30004.Duration);
//
  if(ECHO){
    Serial.print( " Dist ");Serial.print(minni.Data30004.Dist);
    Serial.print( " Duration ");Serial.print(minni.Data30004.Duration);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SDIST  +  writeString4 + SDIST_Durat ;

    readString =  writeString1 + writeString2 + writeString3 + writeString4;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }

        Influxdb influx(INFLUXDB_HOST);
        influx.setDbAuth(INFLUXDB_DB, INFLUXDB_USER, INFLUXDB_PASS);
        InfluxData row(INFLUXDB_ROW);
        row.addTag("sensore", "30004");
        row.addTag("type", "distanza");
        row.addValue("vbat", vBatTX);
        row.addValue("pacchetto", npacket);
        row.addValue("distanza", minni.Data30004.Dist);
        row.addValue("durata", minni.Data30004.Duration);
        influx.write(row);
}
