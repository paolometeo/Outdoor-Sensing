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

        Influxdb influx(INFLUXDB_HOST);
        influx.setDbAuth(INFLUXDB_DB, INFLUXDB_USER, INFLUXDB_PASS);
        InfluxData row(INFLUXDB_ROW);
        row.addTag("sensore", "30001");
        row.addTag("type", "pir");
        row.addValue("vbat", vBatTX);
        row.addValue("pacchetto", npacket);
        row.addValue("status", minni.Data30001.PIRstatus);
        influx.write(row);
}  
