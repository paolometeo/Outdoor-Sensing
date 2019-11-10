void pHInit(){
  AcidStep = (voltagePH400 - voltagePH700) / (7.0 - 4.0);
  BasicStep = (voltagePH700 - voltagePH918) / (9.18 - 7.0);
  if(ECHO){
     Serial.print(" voltagePH700 = ");Serial.println(voltagePH700);
     Serial.print(" voltagePH686 = ");Serial.println(voltagePH686);
     Serial.print(" voltagePH400 = ");Serial.println(voltagePH400);
     Serial.print(" voltagePH918 = ");Serial.println(voltagePH918);
     Serial.print(" AcidStep = ");Serial.println(AcidStep);
     Serial.print(" BasicStep = ");Serial.println(BasicStep);
  }
}
