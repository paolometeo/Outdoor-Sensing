//  Vibration
void http30002(){
   String writeString1 = "VIBR_vBatTX_1=";
   String writeString2 = "&VIBR_npacket_1=";
   String writeString3 = "&VIBR_npulse_1=";
   String writeString4 = "&VIBR_sPeriod_1=";

//  trasformazione da formato numerico a carattere parte fissa
   String SvBatTX = String(vBatTX);
   String Snpacket = String(npacket);


//  trasformazione da formato numerico a carattere parte variabile
   String SVIBRnpulse = String(minni.Data30002.npulse);
   String SVIBRsPeriod = String(minni.Data30002.sPeriod);
//
  if(ECHO){
    Serial.print( " npulse ");Serial.print(minni.Data30002.npulse);
    Serial.print( " sPeriod ");Serial.print(minni.Data30002.sPeriod);
    Serial.println();
  }
   TotalString = "";
   TotalString = writeString1 + SvBatTX +  writeString2 + Snpacket + 
   writeString3 + SVIBRnpulse  +  writeString4 + SVIBRsPeriod ;
   
    readString =  writeString1 + writeString2 + writeString3 + writeString4;
   if(ECHO){
     Serial.println(); Serial.println(" String transmitted to Exosite");
     Serial.println(TotalString);
   }

        Influxdb influx(INFLUXDB_HOST);
        influx.setDbAuth(INFLUXDB_DB, INFLUXDB_USER, INFLUXDB_PASS);
        InfluxData row(INFLUXDB_ROW);
        row.addTag("sensore", "30002");
        row.addTag("type", "vibrazione");
        row.addValue("vbat", vBatTX);
        row.addValue("pacchetto", npacket);
        row.addValue("npulse", minni.Data30002.npulse);
        influx.write(row);
        
}
