
#define PIN1  3
#define PIN2  A0
#define PIN3  5
#define TmpPinVcc 2
#define TmpPinData 6

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS TmpPinData
#define TEMPERATURE_PRECISION 12

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
int numberOfDevices; // Number of temperature devices found

DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address
