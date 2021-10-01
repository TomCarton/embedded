// K2000
//

int LedCount = 6;
int LedPins[] = {3, 5, 6, 9, 10, 11, 12};

int ledIntensity[] = {0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < LedCount; ++i) {
    pinMode(LedPins[i], OUTPUT);
    digitalWrite(LedPins[i], LOW);
  }
}

void apply() {
  for(int i = 0; i < LedCount; ++i) {
    analogWrite(LedPins[i], ledIntensity[i]);
    ledIntensity[i] -= 25;
    if (ledIntensity[i] <= 0)
      ledIntensity[i] = 0; 
  }  
}

int decay = 4;
int current = 1;
int delta = -1;

void loop() {

  apply();
  if (--decay == 0) {
    if (current > 0 && current < 6)
      ledIntensity[current] = 255;
    current += delta;

    if (current == 0 || current == 5) {
      delta = -delta;
    }

    decay = 4;
  }

  delay(40);
}