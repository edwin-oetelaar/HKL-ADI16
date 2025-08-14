/*HANKERILA ADI16  read the  digital input and record the times*/
/*install  “PCF8574 library" by Renzo Mischianti*/
#include "Arduino.h"
#include "PCF8574.h"

#define SDA  4
#define SCL  5
// Set i2c address
PCF8574 pcf8574(0x23,SDA,SCL);  //the address is 0x23(100011)  SDA is GPIO4 SCL is GPIO5
PCF8574 pcf8574_2(0x26,SDA,SCL);  //the address is 0x26(100110)  SDA is GPIO4 SCL is GPIO5

int i=0;
int j=0;
/**
 * Setup function
 */
void setup() {
    Serial.begin(9600);  //set the serial port baud rate to 9600
    Serial.println(__FILE__);  //Print the file storage path
    delay(1000);  //Delay for 1000 milliseconds

    pcf8574.pinMode(P0, INPUT);  //Set pin P0 as input
    pcf8574.pinMode(P1, INPUT);  //Set pin P1 as input
    pcf8574.pinMode(P2, INPUT);  //Set pin P2 as input
    pcf8574.pinMode(P3, INPUT);  //Set pin P3 as input
    pcf8574.pinMode(P4, INPUT);  //Set pin P4 as input
    pcf8574.pinMode(P5, INPUT);  //Set pin P5 as input
    pcf8574.pinMode(P6, INPUT);  //Set pin P4 as input
    pcf8574.pinMode(P7, INPUT);  //Set pin P5 as input
    pcf8574_2.pinMode(P0, INPUT);  //Set pin P0 as input
    pcf8574_2.pinMode(P1, INPUT);  //Set pin P1 as input
    pcf8574_2.pinMode(P2, INPUT);  //Set pin P2 as input
    pcf8574_2.pinMode(P3, INPUT);  //Set pin P3 as input
    pcf8574_2.pinMode(P4, INPUT);  //Set pin P4 as input
    pcf8574_2.pinMode(P5, INPUT);  //Set pin P5 as input
    pcf8574_2.pinMode(P6, INPUT);  //Set pin P4 as input
    pcf8574_2.pinMode(P7, INPUT);  //Set pin P5 as input
 
    pcf8574.begin();  //Start the PCF8574
    pcf8574_2.begin();
}

/**
 * Loop function
 */
void loop() {

     //create a variable to store the value
    uint8_t val1 = pcf8574.digitalRead(P0);  //Read digital value at pin P0
    uint8_t val2 = pcf8574.digitalRead(P1);  //Read digital value at pin P1
    uint8_t val3 = pcf8574.digitalRead(P2);  //Read digital value at pin P2
    uint8_t val4 = pcf8574.digitalRead(P3);  //Read digital value at pin P3
    uint8_t val5 = pcf8574.digitalRead(P4);  //Read digital value at pin P4
    uint8_t val6 = pcf8574.digitalRead(P5);  //Read digital value at pin P5
    uint8_t val7 = pcf8574.digitalRead(P6);  //Read digital value at pin P6
    uint8_t val8 = pcf8574.digitalRead(P7);  //Read digital value at pin P7

    uint8_t val9 = pcf8574_2.digitalRead(P0);  //Read digital value at pin P0
    uint8_t val10 = pcf8574_2.digitalRead(P1);  //Read digital value at pin P1
    uint8_t val11 = pcf8574_2.digitalRead(P2);  //Read digital value at pin P2
    uint8_t val12 = pcf8574_2.digitalRead(P3);  //Read digital value at pin P3
    uint8_t val13 = pcf8574_2.digitalRead(P4);  //Read digital value at pin P4
    uint8_t val14 = pcf8574_2.digitalRead(P5);  //Read digital value at pin P5
    uint8_t val15 = pcf8574_2.digitalRead(P6);  //Read digital value at pin P6
    uint8_t val16 = pcf8574_2.digitalRead(P7);  //Read digital value at pin P7

    if (val1==LOW) {
      Serial.println("KEY1 PRESSED");  //If value at P0 is LOW, print "KEY1 PRESSED"
      i++;
      Serial.printf("Triggered:%d times\n",i);  
    }

    if (val2==LOW) Serial.println("KEY2 PRESSED"); 
    if (val3==LOW) Serial.println("KEY3 PRESSED");  
    if (val4==LOW) Serial.println("KEY4 PRESSED");  
    if (val5==LOW) Serial.println("KEY5 PRESSED");  
    if (val6==LOW) Serial.println("KEY6 PRESSED");  
    if (val7==LOW) Serial.println("KEY7 PRESSED");  
    if (val8==LOW) Serial.println("KEY8 PRESSED");  

    if (val9==LOW) {
      Serial.println("KEY9 PRESSED");  //If value at P0 is LOW, print "KEY9 PRESSED"
      j++;
      Serial.printf("Triggered:%d times\n",j);  
    }
    if (val10==LOW) Serial.println("KEY10 PRESSED");
    if (val11==LOW) Serial.println("KEY11 PRESSED");
    if (val12==LOW) Serial.println("KEY12 PRESSED");
    if (val13==LOW) Serial.println("KEY13 PRESSED");
    if (val14==LOW) Serial.println("KEY14 PRESSED");
    if (val15==LOW) Serial.println("KEY15 PRESSED");
    if (val16==LOW) Serial.println("KEY16 PRESSED");


    delay(300);  //Delay for 300 milliseconds
}