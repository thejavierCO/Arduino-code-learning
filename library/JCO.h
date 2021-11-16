#ifndef JCO_h
#define JCO_h
#include "Arduino.h"
#include "AsyncDelay.h"

//-------------------------------------
/*
    Basic Class
*/
//-------------------------------------
class Pin{
  private:
    int _pin = 0;
  public:
    Pin(int pin);
    Pin(void);
    int getPin();
    void setPin(int pin);
    void Out();
    void In();
};

class DigitalPin: public Pin {
  public:
    DigitalPin();
    DigitalPin(int pin);
    bool Read();
    void Write(bool state);
    bool If(bool value);
};

class AnalogPin: public Pin {
  public:
    AnalogPin(int pin);
    long Read();
    void Write(int state);
    bool If(int value);
};

//-------------------------------------
/*
    Tools
*/
//-------------------------------------

class DigitalActuator: public DigitalPin{
  public:
    DigitalActuator(int pin);
    void On();
    void Off();
    void Switch();
};

class AnalogActuator: public AnalogPin{
    private:
        bool _state;
  public:
    AnalogActuator(int pin);
    void Set(int number);
    bool If(int value);
    void Switch(int rangeOn, int rangeOff);
};

//-------------------------------------
/*
    Actuadores
*/
//-------------------------------------

class Led: public DigitalActuator{
  private:
    AsyncDelay TimerLed;
  public:
    Led(int pin);
    void useTimeBlink(unsigned long time);
    void blink();
};

class LedPWM:public AnalogActuator{
  private:
    AsyncDelay TimerLed;
  public:
    LedPWM(int pin);
    void to(int time, int start = 0,int end = 0);
    void blink(int time, int max = 255);
};

class Motor{
  private:
    DigitalActuator pinLeft;
    DigitalActuator pinRight;
  public:
  Motor(){}
  Motor(int pinLeft,int pinRight);
  void use(int pinLeft,int pinRight);
  void init();
  void left();
  void right();
  void stop();
};

class Move{
  private:
    Motor MA;
    Motor MB;
  public:
    Move(Motor ML,Motor MR);
    void init();
    void run();
    void back();
    void stop();
    void left();
    void right();
};

//-------------------------------------
/*
 * Sensors
*/
//-------------------------------------

class UltrasonidoSensor{
  private:
    const float VelocidadSonido;
    DigitalPin TriggerPin;
    DigitalPin EchoPin;
  public:
    UltrasonidoSensor(int Tpin,int Epin);
    void init();
    void SendPulse();
    unsigned long StatePulse();
    float cm();
};

class LineSensor{
  private:
    DigitalPin PinS;
  public:
    LineSensor(int pin);
    void init();
    bool Value();
};

//-------------------------------------
/*
    Debug
*/
//-------------------------------------

class SerialConsole{
  private:
    int _baud;
  public:
    SerialConsole();
    SerialConsole(int baud);
    void init();
    void ReadDigital(DigitalActuator obj);
    void ReadAnalog(AnalogActuator obj);
};

#endif