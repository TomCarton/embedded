
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
  digitalWrite(light, LOW);
  delay(blinkingTime);
}

void phase(int light, bool blinking) {
  int time = blinking ? phaseTime - (6 * blinkingTime) : phaseTime;
  
  digitalWrite(light, HIGH);
  delay(time);

  if (blinking) blinkingLight(light);
  else digitalWrite(light, LOW);
}

void loop() {
  // red
  phase(LedRed, true);

  // green
  phase(LedGreen, true);

  // yellow
  phase(LedYellow, false);
}
