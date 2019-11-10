void ReadSensor(){
  
//  Send a trigger pulse of 10 microsec
  digitalWrite(TriggerPin,LOW);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds( 10 );
  digitalWrite(TriggerPin,LOW);

// Read the time passed between the trigger pulse and the Echo pulse
  minni.Data30004.Duration = pulseIn(EchoPin,HIGH);  // microsec

// convert the time into the distance
  minni.Data30004.Dist = 0.034 * float(minni.Data30004.Duration)/2.0;  // Distance in cm
  if(minni.Data30004.Duration >= 38000){
    minni.Data30004.Duration = 99999;
    minni.Data30004.Dist = 999.0;
  }
}
