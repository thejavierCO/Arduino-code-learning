int state = 0;

void setup() {
  msg.init();
  M.init();
  Start.Out();
}

void loop() {
  if(Start.Read()==true){
    while(true){
      state==0?M.left():M.rigth();
      delay(2000);
      state=!state;
      break;
    }
  }
  M.stop();
}
