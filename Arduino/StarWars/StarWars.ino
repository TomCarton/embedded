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
  playNote(440, 20 * 25); // A4
  playNote(440, 20 * 25); // A4
  playNote(440, 20 * 25); // A4
  playNote(349, 14 * 25); // F4
  playNote(523, 6 * 25); // C5
  playNote(440, 20 * 25); // A4
  playNote(349, 14 * 25); // F4
  playNote(523, 6 * 25); // C5
  playNote(440, 26 * 25); // A4
 
  delay(500);
 
  playNote(659, 20 * 25); // E5
  playNote(659, 20 * 25); // E5
  playNote(659, 20 * 25); // E5
  playNote(698, 14 * 25); // F5
  playNote(523, 6 * 25); // C5
  playNote(415, 20 * 25); // G#4
  playNote(349, 14 * 25); // F4
  playNote(523, 6 * 25); // C5
  playNote(440, 26 * 25); // A4
 
  delay(500);

  playNote(880, 20 * 25); // A5
  playNote(440, 12 * 25); // A4
  playNote(440, 6 * 25); // A4
  playNote(880, 20 * 25); // A5
  playNote(830, 13 * 25); // G#5
  playNote(784, 7 * 25); // G5
  playNote(740, 5 * 25); // F#5
  playNote(698, 5 * 25); // F5
  playNote(740, 10 * 25); // F#5
 
  delay(325);
 
  playNote(466, 10 * 25); // A#4
  playNote(622, 20 * 25); // D#5
  playNote(587, 13 * 25); // D5
  playNote(554, 7 * 25); // C#5
  playNote(523, 5 * 25); // C5
  playNote(482, 5 * 25); // B4
  playNote(523, 10 * 25); // C5
 
  delay(350);
  
  playNote(349, 10 * 25); // F4
  playNote(415, 20 * 25); // G#4
  playNote(349, 14 * 25); // F4
  playNote(440, 5 * 25); // A4
  playNote(523, 20 * 25); // C5
  playNote(440, 15 * 25); // A4
  playNote(523, 5 * 25); // C5
  playNote(659, 26 * 25); // E5
 
  delay(500);
}
