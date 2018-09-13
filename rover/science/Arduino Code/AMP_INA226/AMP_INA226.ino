#include <INA226.h>

INA226_Class INA226;
uint8_t devicesFound = 0; //number of INA226s found

void setup(){
  Serial.begin(115200);
  
  devicesFound = INA226.begin(5,4000); //set expected Amps and resistor (microOhms)                        
  INA226.setAveraging(4); //average each reading n-times
  INA226.setShuntConversion(7); //maximum conversion time 8.244ms
  INA226.setMode(INA_MODE_CONTINUOUS_SHUNT); //shunt measured continuously
}

void loop(){              
  for (uint8_t i=0;i<devicesFound;i++){ //loop through all devices found   
    Serial.print("Device: ");                              
    Serial.println(i+1);
    Serial.print("Amperage: ");                                                   
    Serial.print((float)INA226.getBusMicroAmps()/1000.0f,3); // Convert to milliamp              
    Serial.println("mA");
  }
  delay(2000);
}
