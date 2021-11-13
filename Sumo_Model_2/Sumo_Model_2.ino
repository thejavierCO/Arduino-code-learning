#include <AsyncDelay.h>

class Pin{
  private:
    int _pin = 13;
  public:
    Pin(void){}
    Pin(int pin){
      this->_pin = pin;
    }
    int get(){
      return this->_pin;
    }
    void set(int pin){
      this->_pin = pin;
    }
    void out(){
      pinMode(this->_pin,OUTPUT);
    }
    void in(){
      pinMode(this->_pin,OUTPUT);
    }
};

class Digital: public Pin{
  private:
    AsyncDelay Timer;
  public:
    Digital():Pin(){}
    Digital(int pin):Pin(pin){}
    void write(bool data){digitalWrite(this->get(),data);}
    bool read(){return digitalRead(this->get());}
    void setDelay(int Time){
      this->Timer.start(Time,AsyncDelay::MILLIS);
    }
    bool await(){
      if(this->Timer.isExpired())this->Timer.restart();
      return !this->Timer.isExpired();
    }
};

class Analog: public Pin{
  private:
    AsyncDelay Timer;
  public:
    Analog():Pin(){}
    Analog(int pin):Pin(pin){}
    void write(int data){analogWrite(this->get(),data);}
    int read(){return analogRead(this->get());}
    void setDelay(int Time){
      this->Timer.start(Time,AsyncDelay::MILLIS);
    }
    bool await(){
      if(this->Timer.isExpired())this->Timer.restart();
      return !this->Timer.isExpired();
    }
};

class ActuatorAnalog:public Analog{
  public:
    ActuatorAnalog(int pin):Analog(pin){}
    void send(int data){
      this->write(data);
    }
    int state(){
      return this->read();
    }
};

class ActuatorDigital:public Digital{
  public:
    ActuatorDigital(int pin):Digital(pin){}
    void on(){
      this->write(HIGH);
    }
    void off(){
      this->write(LOW);
    }
    int state(){
      return this->read();
    }
};
