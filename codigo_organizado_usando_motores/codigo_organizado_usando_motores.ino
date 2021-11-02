/*
Recuerda que lo que realice el codigo no necesariamente es lo que el robot hara
tendras que modificar tu codigo para que funcione adecuadamente segun lo fisico

Es importante que este bien organizado para que sepas que mover le 
*/


int pinMotorALeft = 0;
int pinMotorARight= 0;
int pinMotorBLeft = 0;
int pinMotorBRight= 0;

// funcion individial que se encarga de usar las direcciones del motor

void Motor(int pinLeft,int pinRight, int estado){
  if(esatdo=0){                       //Stop
    digitalWrite(pinLeft  , LOW);
    digitalWrite(pinRight , LOW);
  }else if(estado=1){                 // Left
    digitalWrite(pinLeft  , HIGH);
    digitalWrite(pinRight , LOW);
  }else if(estado=2){                 // Right
    digitalWrite(pinLeft  , HIGH);
    digitalWrite(pinRight , LOW);
  }
}

// funcion indivual que se encarga del moviemiento general 
// del motor reutilizando tu funcion anterior

/*
 * Si lo organizas asi veras que solo tendras que cambiar unos numero y ya
*/


void Move(int direccion){
  if(direccion=0){          // Stop
    Motor(pinMotorALeft,0);
    Motor(pinMotorARight,0);
  }else if(direccion=1){    // Run
    Motor(pinMotorALeft,1);
    Motor(pinMotorARight,1);
  }else if(direccion=2){    // Back
    Motor(pinMotorALeft,2);
    Motor(pinMotorARight,2);
  }else if(direccion=3){    // Right
    Motor(pinMotorALeft,0);
    Motor(pinMotorARight,1);
  }else if(direccion=4){    //Left
    Motor(pinMotorALeft,1);
    Motor(pinMotorARight,0);
  }
}
void setup() {// funcion interna de inicializacion de componentes
  pinMode(pinMotorALeft,OUTPUT);
  pinMode(pinMotorARight,OUTPUT);
  pinMode(pinMotorBLeft,OUTPUT);
  pinMode(pinMotorBRight,OUTPUT);
}

void loop() {// funcion interna de arranque de ejecucion del programa
  Move(1);// Run
  delay(1000);
  Move(3);// Left
  delay(1000);
  Move(4);// Right
  delay(1000);
  Move(0);// Stop
  delay(1000);
}
