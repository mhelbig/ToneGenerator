#define OUTPUT_PORT 9
#define ANALOG_IN   A0

void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
}

void loop() 
{
  int sensorReading = analogRead(ANALOG_IN);
  Serial.println(sensorReading);

  if (sensorReading > 20)
  {
    int thisPitch = map(sensorReading, 0, 1024, 400, 600);
    tone(OUTPUT_PORT, thisPitch);
  }
  else
  {
    noTone(OUTPUT_PORT);
  }

  delay(1);        // delay in between reads for stability
}
