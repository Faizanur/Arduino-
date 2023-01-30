// Master code for wall-e to be upload in Nano Only

#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); // RX | TX
int it = 0;
char flag = it;

#define LM 6 // LEFT MOTOR alternate pins that can be used are pin 9,10,11
#define RM 7 // RIGHT MOTOR alternate pins that can be used are pin 9,10,11
#define IR A1

void reading()
{
  it = analogRead(IR);
  Serial.println("IR vslue");
  Serial.println(it);
}

void forward()
{
  digitalWrite(LM, HIGH);
  digitalWrite(RM, HIGH);
}
void left()
{
  digitalWrite(LM, HIGH);
  digitalWrite(RM, LOW);
}
void right()
{
  digitalWrite(LM, LOW);
  digitalWrite(RM, HIGH);
}

// analogRead function controls pitch of the motor but only supports with PWM pins that are 3,5,6,9,10,11 in Nano
void leftturn()
{
  analogWrite(LM, 1023);
  analogWrite(RM, 500);
}
void rightturn()
{
  analogWrite(LM, 1023);
  analogWrite(RM, 500);
}

void boot()
{
  forward();
  delay(3000);
  left();
  delay(3000);
  right();
  delay(3000);
  leftturn();
  delay(3000);
  rightturn();
  delay(3000);
}

void decide()
{
  if (it < 50)
  {
    leftturn();
  }
  else
  {
    forward();
  }
}
void setup()
{
  Serial.begin(38400);
  BT.begin(38400);
  Serial.println("Ready");
  pinMode(LM, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(IR, INPUT);
  boot();
}
void loop()
{
  if (Serial.available())  
  it = analogRead(IR);
    flag = it;
  BT.write(flag);
  Serial.println("BT");
  Serial.println(flag);
  decide();
  Serial.println(it);
}
