// C++ code
//

#include <Servo.h>

#define SERVO_1 5
#define SERVO_2 6
#define SERVO_3 7
#define BOTAO 13

Servo servo1;
Servo servo2;
Servo servo3;

void upDown(Servo servo);

void setup()
{
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  servo1.attach(SERVO_1);
  servo2.attach(SERVO_2);
  servo3.attach(SERVO_3);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop()
{
   if (Serial.available() > 0) {
    char leitura = Serial.read();
    if (leitura == '1') {
      upDown(servo1);
      upDown(servo2);
      upDown(servo3);
    }
  }
  if (digitalRead(BOTAO) == HIGH) {
    upDown(servo1);
    upDown(servo2);
    upDown(servo3);
  }
}

void upDown(Servo servo){
  servo.write(140);
  delay(3000);
  servo.write(0);
  delay(3000);
}