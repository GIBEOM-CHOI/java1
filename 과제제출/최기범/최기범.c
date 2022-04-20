// 최기범

int PIN_LED1 = 2;
int PIN_LED2 = 3;
int PIN_LED3 = 4;
int PIN_LED4 = 5;
int PIN_ECHO = 7;
int PIN_TRIGGER = 6;

void setup()
{
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);
 
  distance = pulseIn(PIN_ECHO, HIGH)/57;
  
  Serial.println(distance);
  
  if(distance>150 && distance<=200){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
  } else if(distance>100 && distance<=150) {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
  } else if(distance>50 && distance<=100) {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, LOW);
  } else if(distance<=50) {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, HIGH);
  } else {
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, LOW);
}
}