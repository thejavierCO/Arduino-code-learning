#include "Arduino.h"
#include "AsyncDelay.h"
#include "JCO.h"

//-------------------------------------
/*
    Basic Class
*/
//-------------------------------------
Pin::Pin(int pin){
    this->_pin = pin;
}
Pin::Pin(void){}
int getPin(){
    return this->_pin;
}
void Pin::setPin(int pin){
    this->_pin = pin;
}
void Pin::Out(){
    pinMode(this->_pin,OUTPUT);
}
void Pin::In(){
    pinMode(this->_pin,INPUT);
}

DigitalPin::DigitalPin():Pin(){}
DigitalPin::DigitalPin(int pin):Pin(pin){};
bool DigitalPin::Read(){
    return digitalRead(this->getPin());
}
void DigitalPin::Write(bool state){
    digitalWrite(this->getPin(),state);
}
bool DigitalPin::If(bool value){
    return this->Read()==value;
}

AnalogPin::AnalogPin(int pin):Pin(pin){};
long AnalogPin::Read(){
    return analogRead(this->getPin());
}
void AnalogPin::Write(int state){
    analogWrite(this->getPin(),state);
}
bool AnalogPin::If(int value){
    return this->Read()==value;
}

//-------------------------------------
/*
    Tools
*/
//-------------------------------------

DigitalActuator::DigitalActuator(int pin):DigitalPin(pin){}
void DigitalActuator::On(){
    this->Write(true);
}
void DigitalActuator::Off(){
    this->Write(false);
}
void DigitalActuator::Switch(){
    if(this->If(true))this->Off();
    else if(this->If(false))this->On();
}

AnalogActuator::AnalogActuator(int pin):AnalogPin(pin){}
void AnalogActuator::Set(int number){
    this->Write(number);
}
bool AnalogActuator::If(int value){
    return this->_state==value;
}
void AnalogActuator::Switch(int rangeOn, int rangeOff){
    if(this->If(false))this->Set(rangeOn);
    else if(this->If(true))this->Set(rangeOff);
}
//-------------------------------------
/*
    Actuadores
*/
//-------------------------------------

Led::Led(int pin):DigitalActuator(pin){}
void Led::useTimeBlink(unsigned long time){
    this->TimerLed.start(time, AsyncDelay::MILLIS);
}
void Led::blink(){
    if(this->TimerLed.isExpired()){
    this->Switch();
    this->TimerLed.repeat();
    }
}

LedPWM::LedPWM(int pin):AnalogActuator(pin){}
void LedPWM::to(int time, int start = 0,int end = 0){
    if(start==0&&end==0)Serial.println("test");
    else{
    unsigned long TimeDelay;
    TimeDelay = time/end;
    this->TimerLed.start(TimeDelay,AsyncDelay::MILLIS);
    while(start<end){
        if(this->TimerLed.isExpired()){
        this->Set(start);
        start++;
        this->TimerLed.repeat();
        }
    }
    TimeDelay = time/start;
    this->TimerLed.start(TimeDelay,AsyncDelay::MILLIS);
    while(start>end){
        if(this->TimerLed.isExpired()){
        this->Set(start);
        start--;
        this->TimerLed.repeat();
        }
    }
    this->TimerLed.restart();
    }
}
void LedPWM::blink(int time, int max = 255){
    this->to(time/2,0,max); 
    this->to(time/2,max,0);
}

Motor::Motor(){}
Motor::Motor(int pinLeft,int pinRight){
    this->pinLeft.setPin(pinLeft);
    this->pinRight.setPin(pinRight);
}
void Motor::use(int pinLeft,int pinRight){
    this->pinLeft.setPin(pinLeft);
    this->pinRight.setPin(pinRight);
}
void Motor::init(){
    this->pinLeft.Out();
    this->pinRight.Out();
}
void Motor::left(){
    this->pinLeft.On();
    this->pinRight.Off();
}
void Motor::right(){
    this->pinLeft.Off();
    this->pinRight.On();
}
void Motor::stop(){
    this->pinLeft.Off();
    this->pinRight.Off();
}

Move::Move(Motor ML,Motor MR){
    this->MA = ML;
    this->MB = MR;
}
void Move::init(){
    this->MA.init();
    this->MB.init();
}
void Move::Run(){
    this->MA.left();
    this->MB.left();
}
void Move::Back(){
    this->MA.right();
    this->MB.right();
}
void Move::Stop(){
    this->MA.stop();
    this->MB.stop();
}
void Move::Left(){
    this->MA.left();
    this->MB.right();
}
void Move::Right(){
    this->MA.right();
    this->MB.left();
}

//-------------------------------------
/*
 * Sensors
*/
//-------------------------------------

UltrasonidoSensor::UltrasonidoSensor(int Tpin,int Epin){
    this->TriggerPin.setPin(Tpin);
    this->EchoPin.setPin(Epin);
}
void UltrasonidoSensor::init(){
    this->TriggerPin.Out();
    this->EchoPin.In();
}
void UltrasonidoSensor::SendPulse(){
    this->TriggerPin.Write(false);
    delayMicroseconds(2);
    this->TriggerPin.Write(true);
    delayMicroseconds(10);
    this->TriggerPin.Write(false);
}
unsigned long UltrasonidoSensor::StatePulse(){
    return pulseIn(this->EchoPin.getPin(), HIGH);
}
float UltrasonidoSensor::cm(){
    return this->StatePulse() * 0.000001 * this->VelocidadSonido / 2.0;
}

LineSensor::LineSensor(int pin){
    this->PinS.setPin(pin);
}
void LineSensor::init(){
    this->PinS.In();
}
bool LineSensor::Value(){
    return this->PinS.Read();
}

//-------------------------------------
/*
    Debug
*/
//-------------------------------------

SerialConsole::SerialConsole(){}
SerialConsole::SerialConsole(int baud){
    if(baud==0)this->_baud = 9600;
    else this->_baud = baud;
}
void SerialConsole::init(){
    Serial.begin(this->_baud);
}
void SerialConsole::ReadDigital(DigitalActuator obj){
    Serial.println(obj.Read());
}
void SerialConsole::ReadAnalog(AnalogActuator obj){
    Serial.println(obj.Read());
}