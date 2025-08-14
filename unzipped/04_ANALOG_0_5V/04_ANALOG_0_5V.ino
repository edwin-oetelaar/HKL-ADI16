// ADI16 measure analog input use pin A0 A1 A2 A3
/*
A0 and A1 measure 0-5V analog sensor
A2 and A3 measure 0-20mA analog sensor
*/
/*install  ADS1X15 library*/
/*HANKERILA CONTROLLER STORE : https://www.aliexpress.com/store/1103673574*/
#include "ADS1X15.h"
ADS1115 ADS(0x49);
const float shuntResistor = 200.0; 
void setup() 
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println("Welcome Use HANKERILA ADI16");

  Wire.begin(4,5);
  ADS.begin();
}


void loop() 
{
  ADS.setGain(0);  //Set gain  Default MaxVoltage 6.14V

  int16_t val_1 = ADS.readADC(0);  // measure PIN A0  0-5v
  int16_t val_2 = ADS.readADC(1);  // measure PIN A1  0-5v
  int16_t val_3 = ADS.readADC(2);  // measure PIN A2 4-20ma
  int16_t val_4 = ADS.readADC(3);  // measure PIN A3 4-20ma

  float f = ADS.toVoltage(1);  //  voltage factor MaxVoltage/32767
  float g= ADS.getMaxVoltage();

  float  Voltage_A2 = (float)val_3 *f;
  float CurrentA2 = Voltage_A2 / shuntResistor * 1000; 

  float  Voltage_A3 = (float)val_4 *f;
  float CurrentA3 = Voltage_A3 / shuntResistor * 1000; 


  //Serial.print("g="); Serial.println(g);  
  //Serial.print("f="); Serial.println(f,5); 
  
  if(val_1 >=0){
    Serial.print("Analog01: "); 
    Serial.print(val_1);
    Serial.print("\t");
    Serial.print(val_1 * f, 2); 
    Serial.println("V");
  }
 if(val_2 >=0){
    Serial.print("Analog02: "); 
    Serial.print(val_2);
    Serial.print("\t");
    Serial.print(val_2 * f, 2); 
    Serial.println("V");
  }
 if(val_3 >=0){
    Serial.print("Analog03: "); 
    Serial.print(val_3);
    Serial.print("\t");
    Serial.print(CurrentA2); 
    Serial.println("mA");
  }
 if(val_4 >=0){
    Serial.print("Analog04: "); 
    Serial.print(val_4);
    Serial.print("\t");
    Serial.print(CurrentA3); 
    Serial.println("mA");
    Serial.println();
  }
  delay(1000);
}


