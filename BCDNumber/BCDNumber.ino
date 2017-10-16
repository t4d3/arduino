
// variables will change:
const int BCD[] = {7, 8, 9, 10, 11, 12, 13}; //assign the pins
int BCDNum[][10] = {{0,0,0,0,0,0,1}, //Zero
                    {1,1,0,0,1,1,1}, //One
                    {1,0,0,1,0,0,0}, //Two
                    {1,0,0,0,0,1,0}, //Three
                    {0,1,0,0,1,1,0}, //Four
                    {0,0,1,0,0,1,0}, //Five
                    {0,0,1,0,0,0,0}, //six
                    {1,0,0,0,1,1,1}, //Seven
                    {0,0,0,0,0,0,0}, //Eight
                    {0,0,0,0,0,1,0}};//Nine
void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  Serial.println("Starting up!");
  for(int i=0;i<7;i++)
    pinMode(BCD[i], OUTPUT);

//set a default at 8
  for(int i=0;i<7;i++)
    digitalWrite(BCD[i], 1);
}

void loop() {
  // read the state of the POT value, and print to the BCD
  setBCD(getPotState());
  delay(10);        // delay in between reads for stability

}

int getPotState() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.print("\tValue is: ");
  Serial.println(sensorValue);
  int num = map(sensorValue, 0, 1023, 0, 11);

  // print out the value you will read:
  return num;
}

void setBCD(int number) {
  //error checking displays an 'E'
  if(number <= -1 | 11 <= number) {
      digitalWrite(BCD[0], 0);
      digitalWrite(BCD[1], 0);
      digitalWrite(BCD[2], 1);
      digitalWrite(BCD[3], 1);
      digitalWrite(BCD[4], 0);
      digitalWrite(BCD[5], 0);
      digitalWrite(BCD[6], 0);
  }
  number %= 10; //This is to round off any unwanted numbers
  Serial.print("\tThe number is: ");
  Serial.print(number);

  for(int i=0;i<7;i++)
    digitalWrite(BCD[i], BCDNum[number][i]);
}
