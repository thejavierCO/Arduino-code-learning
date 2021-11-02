/*
Recuerda que lo que realice el codigo no necesariamente es lo que el robot hara
tendras que modificar tu codigo para que funcione adecuadamente segun lo fisico

Es importante que este bien organizado para que sepas que mover le 
*/


int pinMotorALeft = 0;
int pinMotorARight= 0;
int pinMotorBLeft = 0;
int pinMotorBRight= 0;

// funcion genereal que se encarga del movimiento de los motores 


/*
 * Si lo organizas asi veras que tendras que mover uno por uno los estados de las señales
*/

void Move(int direccion){
  if(direccion=0){          // Stop
    digitalWrite(pinMotorALeft  , LOW);   // -> 0
    digitalWrite(pinMotorARight , LOW);   // -> 0
    digitalWrite(pinMotorBLeft  , LOW);   // -> 0
    digitalWrite(pinMotorBRight , LOW);   // -> 0
  }else if(direccion=1){    // Run
    digitalWrite(pinMotorALeft  , HIGH);  // -> 1
    digitalWrite(pinMotorARight , LOW);   // -> 0
    digitalWrite(pinMotorBLeft  , HIGH);  // -> 1
    digitalWrite(pinMotorBRight , LOW);   // -> 0
  }else if(direccion=2){    // Back
    digitalWrite(pinMotorALeft  , LOW);   // -> 0
    digitalWrite(pinMotorARight , HIGH);  // -> 1
    digitalWrite(pinMotorBLeft  , LOW);   // -> 0
    digitalWrite(pinMotorBRight , HIGH);  // -> 1
  }else if(direccion=3){    // Right
    digitalWrite(pinMotorALeft  , LOW);   // -> 0
    digitalWrite(pinMotorARight , HIGH);  // -> 1
    digitalWrite(pinMotorBLeft  , HIGH);  // -> 1
    digitalWrite(pinMotorBRight , LOW);   // -> 0
  }else if(direccion=4){    //Left
    digitalWrite(pinMotorALeft  , HIGH);  // -> 1
    digitalWrite(pinMotorARight , LOW);   // -> 0
    digitalWrite(pinMotorBLeft  , LOW);   // -> 0
    digitalWrite(pinMotorBRight , HIGH);  // -> 1
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
