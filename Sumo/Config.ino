// Config

Motor MotorA(12,11);
Motor MotorB(10,9);

UltrasonidoSensor US(4,3);

LineSensor L0(8);// Ad L
LineSensor L1(7);// Ad R

LineSensor L2(6);// At L
LineSensor L3(5);// At R

Move MoveRobot(MotorA,MotorB);

AsyncDelay TimerAtaque;
