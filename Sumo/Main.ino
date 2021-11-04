int AllForOne(bool AL ,bool AR){
  return AL&&AR?0:AL||AR?1:0;
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
  if(US.cm()<=15){
      MoveRobot.Stop();
      delay(500);
    while(true){
      US.SendPulse();
      MoveRobot.Run();
      delay(500);
      MoveRobot.Stop();
      delay(500);
      break;
    }
  }
  MoveRobot.Left();
}
