#include <Servo.h>

// distancial sensor
const unsigned int trig = 2;
const unsigned int echo = 3;
long lecture_echo;
unsigned long cm = 0;

// motor controller
const unsigned int enaPin = 6;
const unsigned int enbPin = 5;
const unsigned int in1 = 8;
const unsigned int in2 = 9;
const unsigned int in3 = 10;
const unsigned int in4 = 11;

// servo
Servo servo;
void setup(){
Serial.begin(9600);

// distancial sensor
pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);

// motor pin
pinMode(enaPin, OUTPUT);
pinMode(enbPin, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
digitalWrite(enaPin, LOW);
digitalWrite(enbPin, LOW);

// servo
servo.attach(A0);
servo.write(80);
}

void loop(){
  distanceCalculation();
  firstInteligence();   
}

void firstInteligence(){
  if (cm > 20){
    mouv(1);
  }else if(lookCheck(2)){
    mouv(3);
  }else if (lookCheck(3)){
    mouv(4);
  }else{
    mouv(2);
    }
}

void distanceCalculation(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo,HIGH);
  cm = lecture_echo /58;
  delay(200);
}

void mouv(int where){
  analogWrite(enaPin, 250);
  analogWrite(enbPin, 250);
  switch(where){
    case 1: // forward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    break;
    case 2: // back
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(500);
    break;
    case 3: // left align
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500);
      mouv(1);
    break;
    case 4: // right align
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    break;
    case 5: // stop
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    break;
    
    }
}

void look(int where){
  switch(where){
      case 1: // center
        servo.write(80);
      break;
      case 2: // left
        servo.write(175);
      break;
      case 3: // right
        servo.write(0);
      break;
    }
    delay(500);
}

bool lookCheck(int where){
  switch(where){
      case 1: // center
        look(1);
      break;
      case 2: // left
        look(2);
      break;
      case 3: // right
        look(3);
      break;
    }
    distanceCalculation();
    look(1);
    if (cm >= 30){
      return true;
    }
    return false;
}
  
