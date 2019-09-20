#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


int joystick[5];
RF24 radio(9,10);

int value1;
int value2;
int value3;
int value4;



long int servo1 = 0;
long int servo2 = 0;
long int servo3 = 0;
long int servo4 = 0;

const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() 
{ 

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
 } 

 
void loop() 
{ 
  
  value1 = map(analogRead(A0), 0, 1023, 1, 29);
  value2 = map(analogRead(A1), 0, 1023, 1, 29);
  value3 = map(analogRead(A2), 0, 1023, 1, 29);
  value4 = map(analogRead(A3), 0, 1023, 1, 29);
  
  if(value1  <= 17 && value1 >= 13)
      value1 = 15;
  if(value2  <= 17 && value2 >= 13)
      value2 = 15;
  if(value3  <= 17 && value3 >= 13)
      value3 = 15;
  if(value4  <= 17 && value4 >= 13)
      value4 = 15;
    
  servo2 = servo2 + (value2 - 15);
   
  
  if( servo1  < 1) 
      servo1 = 1;
  if(servo1  > 20000) 
      servo1 = 20000;
  if(servo2  < 1) 
      servo2 = 1;
  if(servo2  > 20000)
      servo2 = 20000;
  if(servo3  < 1) 
      servo3 = 1;
  if(servo3  > 20000)
      servo3 = 20000;
  if(servo4  < 1)
      servo4 = 1;
  if(servo4  > 20000)
      servo4 = 20000;
  
  joystick[1] = value1;
  joystick[0] = map(servo2, 1, 20000, 40, 180);
  joystick[2] = value3;
  joystick[3] = value4;
  
 
  Serial.println(joystick[0]);
  radio.write( &joystick, sizeof(joystick) );
  }

 

