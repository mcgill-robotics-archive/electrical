/* 
  SPI code for encoder interface board- SLAVE side. Used with AMT203-V 
  
  **Removing print statements in either Master or Slave code causes timing 
  differences due to read and write overheads.
  Each clock cycle is supposed to be 0.25us, unless delayed.**
*/

#include <SPI.h>
#include <Encoder.h>

long newPosition;
Encoder myEncoder(2,3);
byte buffer[4];
boolean process_it;
byte Svalrecieved;

void setup() {
  Serial.begin (9600); 
  
  //Setting to slave mode
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  SPCR|=_BV(SPE);
  
  process_it=false;
  //SPI.setClockDivider(SPI_CLOCK_DIV128);    //Slowing clock speed:decreases frequency of random 
                                             //values due to hicks in rotation of encoder
  SPI.attachInterrupt();
}

ISR(SPI_STC_vect)
{
  Svalrecieved=SPDR;                        //Reads value sent by Master
  process_it=true; 
}

void loop() {
   
  if (process_it=true) {                    //Ensures completion of ISR
      newPosition= myEncoder.read();        //Reads encoder value
      
      // Bit shifting and conversion of encoder value from long 
      // to four bytes and stored in byte array
      buffer[3] = (byte)((newPosition & 0xFF000000) >> 24);
      buffer[2] = (byte)((newPosition & 0x00FF0000) >> 16);
      buffer[1] = (byte)((newPosition & 0x0000FF00) >> 8);
      buffer[0] = (byte)(newPosition & 0x000000FF);
      
      //Sending each byte of encoder value to Master
      for (int i=3; i>=0;i--) {
        byte data = buffer[i];
        SPDR= data;                          //Overwriting the SPI Data Register
        Serial.println(data); 
    }
    Serial.println(((long)(buffer[3]) << 24) | ((long)(buffer[2]) << 16) | ((long)(buffer[1]) << 8) | ((long)(buffer[0])));
    process_it=false;  
  }
}
