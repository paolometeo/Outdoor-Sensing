
void ReadDHT() {
 float t = dht.readTemperature(); // Gets the values of the temperature
 float h = dht.readHumidity(); // Gets the values of the humidity
    minni.Data30003.UMID = h;
    minni.Data30003.TEMP = t;
    if(ECHO){    
    // Now print the values:
    Serial.println("Humidity: " + String(minni.Data30003.UMID, 1) + " %");
    Serial.println("Temp (C): " + String(minni.Data30003.TEMP, 1) + " deg C");
    }
}
