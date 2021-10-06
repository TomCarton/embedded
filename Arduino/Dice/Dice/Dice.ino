// Dice
//

int Led1 = 2;
int Led2 = 3;
int Led3 = 4;
int Led4 = 5;
int Led5 = 6;
int Led6 = 7;
int Led7 = 8;

int ButtonPin = 9;

int blinkingTime = 300;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);

  pinMode(ButtonPin, INPUT);

  randomSeed(analogRead(0));
}   

// at the moment: (7 wires)
// 4   6  - 1, 7      4, 1+2+4+6
// 3 7 5  - 2, 2+6    5, 1+2+4+6+7
// 2   1  - 3, 2+6+7  6, 1+2+3+4+5+6

// but could be: (4 wires)
// 4   2  - 1, 1      4, 2+4
// 3 1 3  - 2, 2      5, 1+2+4
// 2   4  - 3, 1+2    6, 2+3+4

void displayNumber(int number) {
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);

  switch (number) {
    case 1:
      digitalWrite(Led7, HIGH);
      break;
    case 2:
      digitalWrite(Led2, HIGH);
      digitalWrite(Led6, HIGH);
      break;
    case 3:
      digitalWrite(Led2, HIGH);
      digitalWrite(Led6, HIGH);
      digitalWrite(Led7, HIGH);
      break;
    case 4:
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led6, HIGH);
      break;
    case 5:
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led6, HIGH);
      digitalWrite(Led7, HIGH);
      break;
    case 6:
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, HIGH);
      digitalWrite(Led4, HIGH);
      digitalWrite(Led5, HIGH);
      digitalWrite(Led6, HIGH);
      break;
  }
}

void loop() {

  if (digitalRead(ButtonPin) == HIGH) {
    int value;

    for (int i = 0; i < 10; ++i) {
      value = random(0, 6) + 1;
      displayNumber(value);
  
      delay(blinkingTime);
    }

    delay(5000);
    displayNumber(0);
  }
}
