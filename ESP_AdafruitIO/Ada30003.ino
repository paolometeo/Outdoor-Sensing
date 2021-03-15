void Ada30003(){
    if(ECHO){
           Serial.print("sending -> ");
           Serial.print(minni.Data30003.Temp,1);  Serial.print(" ");  
           Serial.print(minni.Data30003.Humi,1);Serial.print(" ");  
           Serial.println();
    }   
           Temp->    save(minni.Data30003.Temp);
           Humi->    save(minni.Data30003.Humi);
}
