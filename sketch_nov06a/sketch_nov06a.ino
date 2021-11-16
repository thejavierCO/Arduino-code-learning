int Dip1 = 12, Dip2 = 11, Dip3 = 10, Dip4 = 9;
int En1  = 1 ,  En2 = 2,   En3 = 3,   En4 = 4;

void ToBinary(int number){
  switch(number){
    case 0:// 0000
      digitalWrite(En1,LOW);//  0
      digitalWrite(En2,LOW);//  0
      digitalWrite(En3,LOW);//  0
      digitalWrite(En4,LOW);//  0
    break;
    case 1://0001
      digitalWrite(En1,HIGH);// 1
      digitalWrite(En2,LOW);//  0
      digitalWrite(En3,LOW);//  0
      digitalWrite(En4,LOW);//  0
    break;
    case 2://0010
      digitalWrite(En1,LOW);//  0
      digitalWrite(En2,HIGH);// 1
      digitalWrite(En3,LOW);//  0
      digitalWrite(En4,LOW);//  0
    break;
    case 3://0011
      digitalWrite(En1,HIGH);// 1
      digitalWrite(En2,HIGH);// 1
      digitalWrite(En3,LOW);//  0
      digitalWrite(En4,LOW);//  0
    break;
    case 4://0100
      digitalWrite(En1,LOW);
      digitalWrite(En2,LOW);
      digitalWrite(En3,HIGH);
      digitalWrite(En4,LOW);
    break;
    case 5://0101
      digitalWrite(En1,HIGH);
      digitalWrite(En2,LOW);
      digitalWrite(En3,HIGH);
      digitalWrite(En4,LOW);
    break;
    case 6://0110
      digitalWrite(En1,LOW);
      digitalWrite(En2,HIGH);
      digitalWrite(En3,HIGH);
      digitalWrite(En4,LOW);
    break;
    case 7://0111
      digitalWrite(En1,HIGH);
      digitalWrite(En2,HIGH);
      digitalWrite(En3,HIGH);
      digitalWrite(En4,LOW);
    break;
    case 8://1000
      digitalWrite(En1,LOW);
      digitalWrite(En2,LOW);
      digitalWrite(En3,LOW);
      digitalWrite(En4,HIGH);
    break;
    case 9://1001
      digitalWrite(En1,HIGH);
      digitalWrite(En2,LOW);
      digitalWrite(En3,LOW);
      digitalWrite(En4,HIGH);
    break;
  }
}

int ToDecimal(bool en1,bool en2,bool en3,bool en4){
  if(en1==false&&en2==false&&en3==false&&en4==false){
    return 0;
  }else if(en1==false&&en2==false&&en3==false&&en4==!false){
    return 1;
  }else if(en1==false&&en2==false&&en3==!false&&en4==false){
    return 2;
  }else if(en1==false&&en2==false&&en3==!false&&en4==!false){
    return 3;
  }else if(en1==false&&en2==!false&&en3==false&&en4==false){
    return 4;
  }else if(en1==false&&en2==!false&&en3==false&&en4==!false){
    return 5;
  }else if(en1==false&&en2==!false&&en3==!false&&en4==false){
    return 6;
  }else if(en1==false&&en2==!false&&en3==!false&&en4==!false){
    return 7;
  }else if(en1==!false&&en2==false&&en3==false&&en4==false){
    return 8;
  }else if(en1==!false&&en2==false&&en3==false&&en4==!false){
    return 9;
  }
}

void setup() {
  pinMode(Dip1,OUTPUT);
  pinMode(Dip2,OUTPUT);
  pinMode(Dip3,OUTPUT);
  pinMode(Dip4,OUTPUT);
  
  pinMode(En1,OUTPUT);
  pinMode(En2,OUTPUT);
  pinMode(En3,OUTPUT);
  pinMode(En4,OUTPUT);
}

void loop() {
  ToBinary(ToDecimal(digitalRead(Dip1),digitalRead(Dip2),digitalRead(Dip3),digitalRead(Dip4)));
}
