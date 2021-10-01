
// Traffic Light
//

int LedRed = 8;
int LedYellow = 9;
int LedGreen = 10;

int blinkingTime = 300;
int phaseTime = 5000;

void setup() {
  pinMode(LedGreen, OUTPUT);
  pinMode(LedYellow, OUTPUT);
  pinMode(LedRed, OUTPUT);

  digitalWrite(LedGreen, LOW);
  digitalWrite(LedYellow, LOW);
  digitalWrite(LedRed, LOW);
}

void blinkingLight(int light) {
  digitalWrite(light, LOW);
  delay(blinkingTime);
  digitalWrite(light, HIGH);
  delay(blinkingTime);
  digitalWrite(light, LOW);
  delay(blinkingTime);
  digitalWrite(light, HIGH);
  delay(blinkingTime);
  digitalWrite(light, LOW);
  delay(blinkingTime);
  digitalWrite(light, HIGH);
  delay(blinkingTime);
}

void loop() {
  // red
  digitalWrite(LedRed, HIGH);
  delay(phaseTime);
  blinkingLight(LedRed);
  digitalWrite(LedRed, LOW);

  // green
  digitalWrite(LedGreen, HIGH);
  delay(phaseTime);
  blinkingLight(LedGreen);
  digitalWrite(LedGreen, LOW);

  // yellow
  digitalWrite(LedYellow, HIGH);
  delay(phaseTime);
  digitalWrite(LedYellow, LOW);
}
