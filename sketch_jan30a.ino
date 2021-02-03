// distancial sensor
int trig = 2;
int echo = 3;
long lecture_echo;
long cm = 1023;

// motor controller
const int enaPin = 7;
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

void setup(){
Serial.begin(9600);

// distancial sensor
pinMode(trig, OUTPUT);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);

pinMode(enaPin, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
//distanceCalculation();
}

void loop(){
analogWrite(enaPin, 1000);
 Serial.println(cm);

  if (cm > 7){
    mouv(5);
  }else{
    mouv(1);
   }
   distanceCalculation();
}

void distanceCalculation(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo,HIGH);
  cm = lecture_echo /58;
  delay(100);
}

void mouv(int where){
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
    break;
    case 3: // left align
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
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
  
