void enc_init() 
{
  //Setting up interrupt
  //A changing pulse from encoden1 activated ai0(). 
  attachInterrupt(digitalPinToInterrupt(en1PhaseA), ab, CHANGE);
  
  //A changing pulse from encoden2 activated ai1().
  attachInterrupt(digitalPinToInterrupt(en2PhaseA), ba, CHANGE);
}

void ab() 
{
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(en1PhaseB) == digitalRead(en1PhaseA))
  {
    counter1++;
  }
  else if(digitalRead(en1PhaseB) != digitalRead(en1PhaseA))
  {
    counter1--;
  }
}

void ba() 
{
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(en2PhaseA) == digitalRead(en2PhaseB)) 
  {
    counter2++;
  }else if(digitalRead(en2PhaseB) != digitalRead(en2PhaseA))
  {
    counter2--;
  }
}

void pid1()
{
  error1 = req_position1 - counter1;
  diff_error1 = error1 - last_error1;
  corr1 = (kp1 * error1) + (kd1 * diff_error1);
  
  if (corr1 > max_corr && corr1 > 0)
    corr1 = max_corr;
  else  if (corr1 < -max_corr && corr1 < 0)
    corr1 = -max_corr;

  else if (abs(corr1) < least_error)
  {
    corr1 = 0;
    digitalWrite(md1Pin1, HIGH);
    digitalWrite(md1Pin2, HIGH);
  }
  last_error1 = error1;
}


void pid2()
{
  error2 = req_position2 - counter2;
  diff_error2 = error2 - last_error2;
  corr2 = (kp2 * error2) + (kd2 * diff_error2);
  
  if (corr2 > max_corr && corr2 > 0)
    corr2 = max_corr;
  else  if (corr2 < -max_corr && corr2 < 0)
    corr2 = -max_corr;

  else if (abs(corr2) < least_error)
  {
    corr2 = 0;
    digitalWrite(md2Pin1, HIGH);
    digitalWrite(md2Pin2, HIGH);
  }
  last_error2 = error2;
}

void run_motor1()
{
  pid1();
  if (corr1 > 0)
    {
      digitalWrite(md1Pin1, HIGH);
      digitalWrite(md1Pin2, LOW);
    }
  else if (corr1 < 0)
    {
      digitalWrite(md1Pin1, LOW);
      digitalWrite(md1Pin2, HIGH);
    }
  analogWrite(md1pwm, 255 - abs(corr1));
}  

void run_motor2()
{ 
  pid2(); 
  if (corr2 > 0)
  {
      digitalWrite(md2Pin1, HIGH);
      digitalWrite(md2Pin2, LOW);
  }
  else if (corr2 < 0)
  {
      digitalWrite(md2Pin1, LOW);
      digitalWrite(md2Pin2, HIGH);
  }
  analogWrite(md2pwm, 255 - abs(corr2));
}
