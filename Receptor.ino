#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include<Servo.h>


#define ESC1_pino 5 
#define ESC2_pino 6 
#define ESC3_pino 7 
#define ESC4_pino 8 

int motor1=0,motor2=0,motor3=0,motor4=0;
int acel;
int vel1,vel2,vel3,vel4;
 
Servo esc1,esc2,esc3,esc4;

int joystick[5];

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void)
{
  pinMode(2, OUTPUT);
  
  esc1.attach(ESC1_pino);
  esc2.attach(ESC2_pino);
  esc3.attach(ESC3_pino);
  esc4.attach(ESC4_pino);
  
  //Configuracao NRF24
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  //Final da Configuracao
}

void loop(void)
{
   
        
        if ( radio.available() ){
          bool done = false;
            while (!done){
                done = radio.read( &joystick, sizeof(joystick) );
                digitalWrite(2, HIGH);
                acel=joystick[0];
                }
        }
        else {digitalWrite(2, LOW);}

       vel1=motor1+acel;
       vel2=motor2+acel;
       vel3=motor3+acel;
       vel4=motor4+acel;
                    

        esc1.write(vel1);
        esc2.write(vel2);
        esc3.write(vel3);
        esc4.write(vel4);

}

