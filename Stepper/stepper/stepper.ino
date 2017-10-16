const int stepperPin[] = {8, 9, 10, 11};
int loopLoop = 0;
int currStep = 0;
int delayTime = 0;
int stepDirection = 0;

void setup() {
    Serial.begin(9600);      // open the serial port at 9600 bps:
  for(int i=0;i<4;i++)
    pinMode(stepperPin[i], OUTPUT);
}

void loop() {
  loopLoop++;

  if (loopLoop == 10) {
    delayTime = map(analogRead(0), 0, 1023, 8, 100);
    loopLoop = 0;
    Serial.println(delayTime);
  }

  stepDirection = (digitalRead(2) == LOW) ? 1 : -1;

  stepStepper(delayTime, currStep);

  currStep += stepDirection;
  if (currStep < 0)
    currStep = 3;
  if (currStep > 3)
    currStep = 0;
}

void stepStepper(int delayTime, int currStep) {
  switch (currStep) {
    case 0:
    digitalWrite(stepperPin[0], LOW);
    digitalWrite(stepperPin[1], HIGH);
    digitalWrite(stepperPin[2], HIGH);
    digitalWrite(stepperPin[3], HIGH);
    break;
    case 1:
    digitalWrite(stepperPin[0], HIGH);
    digitalWrite(stepperPin[1], LOW);
    digitalWrite(stepperPin[2], HIGH);
    digitalWrite(stepperPin[3], HIGH);
    break;
    case 2:
    digitalWrite(stepperPin[0], HIGH);
    digitalWrite(stepperPin[1], HIGH);
    digitalWrite(stepperPin[2], LOW);
    digitalWrite(stepperPin[3], HIGH);
    break;
    case 3:
    digitalWrite(stepperPin[0], HIGH);
    digitalWrite(stepperPin[1], HIGH);
    digitalWrite(stepperPin[2], HIGH);
    digitalWrite(stepperPin[3], LOW);
    break;
  }
  delay(delayTime);
}
