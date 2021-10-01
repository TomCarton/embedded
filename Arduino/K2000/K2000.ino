// K2000
//

const int kDebug = 0;

const int kLedPins[] = { 3, 5, 6, 9, 10, 11 };
const int kLedCount = sizeof(kLedPins) / sizeof(kLedPins[0]);
const int kLedIntensity[] = { 0, 1, 7, 15, 31, 63, 127, 255 };
const int kLedIntensityCount = sizeof(kLedIntensity) / sizeof(kLedIntensity[0]);

int ledIntensityIndex[] = { 0, 0, 0, 0, 0, 0 };

void setup() {
  if (kDebug) {
    Serial.begin(9600);

    Serial.print("Led count: ");
    Serial.print(kLedCount, DEC);
    Serial.print("\n");
  }
    
  for(int i = 0; i < kLedCount; ++i) {
    pinMode(kLedPins[i], OUTPUT);
    digitalWrite(kLedPins[i], LOW);
  }
}

void updateIntensity() {
  if (kDebug)
    Serial.print("> ");

  for(int i = 0; i < kLedCount; ++i) {
    if (ledIntensityIndex[i] > 0)
    {
      ledIntensityIndex[i] -= 1;
    }

    if (kDebug) {
      Serial.print(ledIntensityIndex[i], DEC);
      Serial.print(" ");
    }

    analogWrite(kLedPins[i], kLedIntensity[ledIntensityIndex[i]]);
  }

  if (kDebug)
    Serial.print("\n");
}

int current = -2;
int delta = -1;

void animate() {
  current += delta;
  
  if (current < 1) {
    current = 0;
    delta = 1;
  } else if (current >= kLedCount - 1) {
    current = kLedCount - 1;
    delta = -1;
  }
}

const int kAnimMaxStep = 3;
int animStep = kAnimMaxStep;

void loop() {

  if (kDebug)
    Serial.print(current, DEC);

  updateIntensity();
  if (--animStep < 1) {
    animate();
    animStep = kAnimMaxStep;
  }

  ledIntensityIndex[current] = kLedIntensityCount - 1;

  delay(75);
}
