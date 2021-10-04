// StarWars
//

const int kDebug = 0;

const int kBuzzerPin = 9;
const int kFirstLedPin = 10;
const int kLedPinCount = 3;

int noteIndex = 0;

void setup()
{
  if (kDebug) {
    Serial.begin(9600);

    Serial.print("Star Wars\n");
  }

  pinMode(kBuzzerPin, OUTPUT);

  for (int i = 0; i < kLedPinCount; ++i)
  {
    pinMode(kFirstLedPin + i, OUTPUT);
  }
}

void playNote(int buzzerPin, int note, int duration)
{
  int ledPin = kFirstLedPin + (noteIndex % kLedPinCount);

  duration = (duration * 1000) / 32;
  if (note)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, note, duration);
  }

  delay(duration - 5);

  if (note)
  {
    digitalWrite(ledPin, LOW);

    delay(5);
    ++noteIndex;
  }
}

void playSong(int buzzerPin, const char *song)
{
  int head = 0;
  unsigned int len = strlen(song);

  while (head < len)
  {
    int err = 0;

    int note = 0;
    int sharp = 0;
    int octave = 0;
    int duration = 0;

    char c = ' ';
    while (head < len && (c == ',' || c == ' ')) c = song[head++];

    if (c >= 'A' && c <= 'G')
    {
      note = c - 'A';
      c = song[head++];
      if (c == '#')
      {
        sharp = 1;
        c = song[head++];
      }
      if (c >= '0' && c <= '9')
      {
        octave = c - '0';
        c = song[head++];
      }
    }

    if (c == '-')
    {
      while ((c = song[head++]) && c != ',' && err == 0)
      {
          if (c >= '0' && c <= '9')
          {
            duration = (duration * 10) + c - '0';
          }
          else err = 1;
      }
    } else err = 1;

    if (err == 0)
    {
      //                           A    A#   B   -   C    C#   D    D#   E   -   F    F#   G    G#
      int frequenciesTable[] = {  110, 116, 123, 0, 130, 138, 147, 155, 164, 0, 175, 185, 196, 207, // 2
                                  220, 233, 247, 0, 261, 277, 293, 311, 329, 0, 349, 370, 392, 415, // 3
                                  440, 466, 494, 0, 523, 554, 587, 622, 659, 0, 698, 740, 784, 830, // 4
                                  880, 932, 988, 0 };
      
      int frequency = 0;
      if (octave >= 2 && octave <= 5)
      {
        int index = (octave - 2) * 14 + note * 2 + sharp;
        frequency = frequenciesTable[index];
      }
          
      playNote(buzzerPin, frequency, duration);

      if (kDebug)
      {
        char sNote[4];
        int k = 0;
        sNote[k++] = 'A' + note;
        if (sharp == 1)
          sNote[k++] = '#';
        sNote[k++] = '0' + octave;
        sNote[k] = 0x00;

        Serial.print(sNote);
        Serial.print("-");
        Serial.print(duration);
        Serial.print("\n");
      }
    }
    else
    {
      if (kDebug)
      {
        char preview[5];
        strncpy((char *)&preview, (const char *)&song[head], 4);
        preview[4] = 0x00;

        Serial.print("Wrong note! Error in: '");
        Serial.print(preview);
        Serial.print("'\n");
      }
    }
  }
}

// ronde = 32           // 40
// blanche = 16         // 20
// noire pointée = 12   // 15
// noire = 8            // 10
// croche = 4           // 5
// double croche = 2    // 2.5
// triple croche = 1    // 1.25

const char kStarWarsSong[] = 
    "A2-20, A2-20, A2-10, A2-5, A2-5, A2-5, F2-10, F2-10, "
    "A2-20, A2-20, A2-10, A2-5, A2-5, A2-5, F2-10, F2-10, "
    
    "A4-20, A4-20, A4-20, F3-15, C4-5, A4-20, F3-15, C4-5, A4-40, "
    "E4-20, E4-20, E4-20, F4-15, C4-5, G#3-20, F3-15, C4-5, A4-40, "
    
    "A5-20, A4-10, A4-5, A5-20, G#4-15, G4-5, F#4-5, F4-5, F#4-10, -15, "
    "A#4-10, D#4-20, D4-15, C#4-5, C4-5, B4-5, C4-10, -15, "
    "F3-10, G#3-20, F3-15, A4-5, C4-20, A4-15, C4-5, E4-25, -20, "
    "";

void loop()
{
  playSong(kBuzzerPin, kStarWarsSong);
  delay(1000);
}
