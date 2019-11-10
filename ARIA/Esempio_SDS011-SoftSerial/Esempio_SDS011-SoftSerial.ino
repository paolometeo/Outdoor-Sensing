// SDS011 dust sensor example with library
// for use with SoftSerial
// 3 mA mentre dorme e 65 mA quando è sveglio
// -----------------------------

#include <SDS011-select-serial.h>
#include <SoftwareSerial.h>

float p10,p25;
int error;

SoftwareSerial mySerial(5, 7); // RX, TX
SDS011 my_sds(mySerial);

void setup() {
	// initialize normal Serial port
	Serial.begin(9600);
	// initalize SDS Serial Port
	mySerial.begin(9600);
 delay(1000);
  my_sds.wakeup();
  delay(2000);
}

void loop() {
	error = my_sds.read(&p25,&p10);
	if (! error) {
		Serial.print("P2.5: "+String(p25)+ " ");
		Serial.println("P10:  "+String(p10));
	}
	// 
	// by Zappoco
	// vedere le funzioni della libreria

  Serial.println(" Dormo per 10 s");
	my_sds.sleep();
	delay(10000);
  Serial.println(" Mi sveglio per 10 s");
	my_sds.wakeup();
	delay(10000);
}
