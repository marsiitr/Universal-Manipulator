#include<Servo.h>
Servo servo1, servo2;

#define md1Pin1 7
#define md1Pin2 8
#define md1pwm  9     //must be pwm
#define en1PhaseA  2  //must be either 2 or 3 
#define en1PhaseB  4  //any other digital pin

#define md2Pin1 12
#define md2Pin2 13
#define md2pwm  11    //must be pwm    
#define en2PhaseA  3  //must be either 2 or 3 
#define en2PhaseB  5  //any other digital pin

int kp1 = 3, kd1 = 1, kp2 = 3, kd2 = 1;
volatile  int counter1 = 0, counter2 = 0;
int error1, error2, diff_error1 = 0, diff_error2 = 0;
int last_error1 = 0, last_error2 = 0, corr1 = 0, corr2 = 0;
int max_corr = 100, least_error = 20, pos1 = 0, pos2 = 0;
int req_position1 = 0, req_position2 = 0;

void setup()
{
  pinMode(md1Pin1, OUTPUT);
  pinMode(md1Pin2, OUTPUT);
  pinMode(md1pwm, OUTPUT);
  pinMode(en1PhaseA, INPUT);
  pinMode(en1PhaseB, INPUT);
  pinMode(md2Pin1, OUTPUT);
  pinMode(md2Pin2, OUTPUT);
  pinMode(md2pwm, OUTPUT);
  pinMode(en2PhaseA, INPUT);
  pinMode(en2PhaseB, INPUT);

  servo1.attach(6);
  servo1.write(10);
  servo2.attach(10);
  servo2.write(10);

  digitalWrite(en1PhaseA, HIGH);       // turn on pullup resistors
  digitalWrite(en1PhaseB, HIGH);       // turn on pullup resistors
  digitalWrite(en2PhaseA, HIGH);       // turn on pullup resistors
  digitalWrite(en2PhaseB, HIGH);       // turn on pullup resistors

  for (pos1 = 10; pos1 <= 30; pos1 += 1)   //Gripper actuate
  { servo1.write(pos1);
    delay(20);
  }
  delay(1000);
  
  enc_init();
  Serial.begin(9600);
  digitalWrite(md2Pin1, HIGH);
  digitalWrite(md2Pin2, LOW);

  req_position1 = 80;
  req_position2 = 400;
  
  analogWrite(md2pwm, 50);
  delay(100);

  pid2();
  while (corr2 != 0)
  {
    Serial.print(counter2);
    Serial.print( "   ");
    Serial.println(corr2);
    run_motor2();
  }

  pid1();
  while (corr1 != 0)
  {
    Serial.print(counter1);
    Serial.print( "   ");
    Serial.println(corr1);
    run_motor1();
  }

  for (pos1 = 30; pos1 <= 60; pos1 += 1)   //Gripper actuate
  { servo1.write(pos1);
    delay(20);
  }
  delay(1000);

  req_position1 = 110;

  pid1();
  while (corr1 != 0)
  {
    Serial.print(counter1);
    Serial.print( "   ");
    Serial.println(corr1);
    run_motor1();
  }

  delay(1000);

  for (pos2 = 20; pos2 <= 90; pos2 += 1)   //Gripper actuate
  { servo2.write(pos2);
    delay(10);
  }
  delay(1000);

  req_position1 = 80;

  pid1();
  while (corr1 != 0)
  {
    Serial.print(counter1);
    Serial.print( "   ");
    Serial.println(corr1);
    run_motor1();
  }

  delay(1000);

  req_position2 = 150;

  analogWrite(md2pwm, 50);
  delay(100);

  pid2();
  while (corr2 != 0)
  {
    Serial.print(counter2);
    Serial.print( "   ");
    Serial.println(corr2);
    run_motor2();
  }

  for (pos1 = 60; pos1 >= 10; pos1 -= 1)   //Survo actuate
  { servo1.write(pos1);
    delay(20);
  }
  delay(1000);

  for (pos2 = 90; pos2 >= 20; pos2 -= 1)   //Gripper actuate
  { servo2.write(pos2);
    delay(20);
  }

  //delay(20000);

  req_position1 = 0;
  pid1();

  while (corr1 != 0)
  {
    Serial.print(counter1);
    Serial.print( "   ");
    Serial.println(corr1);
    run_motor1();
  }


}    // Setup Ends

void loop()
{

}
