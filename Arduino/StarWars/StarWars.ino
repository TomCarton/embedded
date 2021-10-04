// StarWars
//

const int kBuzzerPin = 9;
const int kFirstLedPin = 10;
const int kLedPinCount = 3;

int noteIndex = 0;

void setup()
{
  pinMode(kBuzzerPin, OUTPUT);

  for (int i = 0; i < kLedPinCount; ++i)
  {
    pinMode(kFirstLedPin + i, OUTPUT);
  }
}

void playNote(int note, int duration)
{
  int ledPin = kFirstLedPin + (noteIndex % kLedPinCount);
  digitalWrite(ledPin, HIGH);
  tone(kBuzzerPin, note, duration);

  delay(duration);
  digitalWrite(ledPin, LOW);

  delay(50);
  ++noteIndex;
}

void loop()
{
  playNote(440, 10 * 50); // A4
  playNote(440, 10 * 50); // A4
  playNote(440, 10 * 50); // A4
  playNote(349, 7 * 50); // F4
  playNote(523, 3 * 50); // C5
  playNote(440, 10 * 50); // A4
  playNote(349, 7 * 50); // F4
  playNote(523, 3 * 50); // C5
  playNote(440, 13 * 50); // A4
 
  delay(500);
 
  playNote(659, 10 * 50); // E5
  playNote(659, 10 * 50); // E5
  playNote(659, 10 * 50); // E5
  playNote(698, 7 * 50); // F5
  playNote(523, 3 * 50); // C5
  playNote(415, 10 * 50); // G#4
  playNote(349, 7 * 50); // F4
  playNote(523, 3 * 50); // C5
  playNote(440, 13 * 50); // A4
 
  delay(500);

  playNote(880, 500); // A5
  playNote(440, 300); // A4
  playNote(440, 150); // A4
  playNote(880, 500); // A5
  playNote(830, 325); // G#5
  playNote(784, 175);  // G5
  playNote(740, 125); // F#5
  playNote(698, 125);  // F5
  playNote(740, 250); // F#5
 
  delay(325);
 
  playNote(466, 250); // A#4
  playNote(622, 500); // D#5
  playNote(587, 325); // D5
  playNote(554, 175); // C#5
  playNote(523, 125); // C5
  playNote(482, 125); // B4
  playNote(523, 250); // C5
 
  delay(350);
  
  playNote(349, 250); // F4
  playNote(415, 500); // G#4
  playNote(349, 350); // F4
  playNote(440, 125); // A4
  playNote(523, 500); // C5
  playNote(440, 375); // A4
  playNote(523, 125); // C5
  playNote(659, 650); // E5
 
  delay(500);
}
