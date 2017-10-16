
#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:
  servo1.attach(A3);
  servo2.attach(A5);
}

void loop() {
  int pot1 = map(analogRead(1), 0, 1023, 0, 180);
  int pot2 = map(analogRead(0), 0, 1023, 0, 180);
servo1.write(pot1);
servo2.write(pot2);
Serial.print(" pot1: ");
Serial.print(pot1);
Serial.print(" pot2: ");
Serial.println(pot2);
delay(20);

}

int getPotState(int pin) {
  //read the pin state
  Serial.print("Reading Pin ");
  Serial.print(pin);
  return analogRead(pin);
}

