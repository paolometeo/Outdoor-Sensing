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
;
    readString =  writeString1 + writeString2 + writeString3 + writeString4;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }

        Influxdb influx(INFLUXDB_HOST);
        influx.setDbAuth(INFLUXDB_DB, INFLUXDB_USER, INFLUXDB_PASS);
        InfluxData row(INFLUXDB_ROW);
        row.addTag("sensore", "30005");
        row.addTag("type", "polvere");
        row.addValue("vbat", vBatTX);
        row.addValue("pacchetto", npacket);
        row.addValue("PM10", minni.Data30005.Conc10);
        row.addValue("PM2.5", minni.Data30005.Conc25);
        row.addValue("temperatura", minni.Data30005.TEMP);
        row.addValue("umidita", minni.Data30005.UMID);
        influx.write(row);
   
}
