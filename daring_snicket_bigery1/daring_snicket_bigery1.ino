#include <Servo.h>
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int steps_left=4095;
boolean Direction = true;
int Steps = 0;                       // Define el paso actual de la secuencia


int Paso [ 8 ][ 4 ] ={  
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void SetDirection()
   {  
      if(Direction)
         Steps++;
      else
         Steps--;

      Steps = ( Steps + 8 ) % 8 ;
   }

void stepper()            //Avanza un paso
   {  digitalWrite( IN1, Paso[Steps][ 0] );
      digitalWrite( IN2, Paso[Steps][ 1] );
      digitalWrite( IN3, Paso[Steps][ 2] );
      digitalWrite( IN4, Paso[Steps][ 3] );

      SetDirection();
   }
   

void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
  while(steps_left>0){ 
     stepper() ;     // Avanza un paso
     steps_left-- ;  // Un paso menos
     delayMicroseconds(810);
  }
  //delay();
  steps_left = 4095;
}
