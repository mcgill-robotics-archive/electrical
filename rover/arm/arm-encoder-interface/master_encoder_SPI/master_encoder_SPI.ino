/* 
  SPI code for encoder interface board- MASTER side. Used with AMT203-V 
  
  **Removing print statements in either Master or Slave code causes timing 
  differences due to read and write overheads.
  Each clock cycle is supposed to be 8us, unless delayed.**
*/

#include <SPI.h>

void setup() {
  Serial.begin(9600);
  digitalWrite(SS,HIGH);                     //Slave select set high to ensure no communication
  SPI.begin();
  //SPI.setClockDivider(SPI_CLOCK_DIV128);   //Slowing clock speed:decreases frequency of random 
                                             //values due to hicks in rotation of encoder
}

void loop() {
  byte Mvalsent;
  byte buffer[4];
  
  digitalWrite(SS,LOW);                      // Slave select set low to begin communication
 // Mvalsent= 1;                             // commented out because not necessary to initialize
  
  for (int i= 3; i>=0; i--) {                //Set up to capture 32 bit long. One byte at a time. MSB first.
    buffer[i]= SPI.transfer(Mvalsent);       //SPI transfer sends one byte for each byte recieved
    Serial.println(buffer[i]);               
  }
               
  // Reconstructing long from byte array
  Serial.println(((long)(buffer[3]) << 24) | ((long)(buffer[2]) << 16) | ((long)(buffer[1]) << 8) | ((long)(buffer[0])));
  digitalWrite(SS,HIGH);                      // Stopping slave communication
}
