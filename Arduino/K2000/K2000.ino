// K2000
//

const int kLedPins[] = { 3, 5, 6, 9, 10, 11 };
const int kLedCount = sizeof(kLedPins) / sizeof(kLedPins[0]);
const int kLedIntensity[] = { 0, 1, 7, 15, 63, 255 };
const int kLedIntensityCount = sizeof(kLedIntensity) / sizeof(kLedIntensity[0]);

int ledIntensityIndex[] = { 0, 0, 0, 0, 0, 0 };

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < kLedCount; ++i) {
    pinMode(kLedPins[i], OUTPUT);
    digitalWrite(kLedPins[i], LOW);
  }

  ledIntensityIndex[0] = kLedIntensityCount - 1;
}

void updateIntensity() {

  Serial.print("> ");

  for(int i = 0; i < kLedCount; ++i) {
    if (ledIntensityIndex[i] > 0)
    {
      ledIntensityIndex[i] -= 1;
    }

    Serial.print(ledIntensityIndex[i], DEC);
    Serial.print(" ");

    analogWrite(kLedPins[i], kLedIntensity[ledIntensityIndex[i]]);
  }

  Serial.print("\n");
}

int current = 0;
int delta = -1;

void loop() {

  Serial.print(current, DEC);

  updateIntensity();

  current += delta;
  if (current < 0) {
    current = 0;
    delta = 1;
  } else if (current > kLedCount - 1) {
    current = kLedCount;
    delta = -1;
  }

  ledIntensityIndex[current] = kLedIntensityCount - 1;

  delay(200);
}
