int AllForOne(bool AL ,bool AR,bool invert = 0){
  return AL==invert&&AR==invert?0:AL==invert||AR==invert?1:0;
}

void setup(){
  MoveRobot.init();
  US.init();
  L0.init();
  L1.init();
  L2.init();
  L3.init();
  Serial.begin(9600);
}

void loop(){
  US.SendPulse();
  if(AllForOne(L0.Value(),L1.Value())){
    MoveRobot.Back();
    delay(280);
  }else if(AllForOne(L2.Value(),L3.Value())){
    MoveRobot.Run();
    delay(280);
  }else{
    if(US.cm()<= 45){
      TimerAtaque.start(500,AsyncDelay::MILLIS);
      if(!TimerAtaque.isExpired()){
        MoveRobot.Run();
      }else{
        TimerAtaque.restart();  
      }
    }else{
      MoveRobot.Left();
    }
    
  }
}
