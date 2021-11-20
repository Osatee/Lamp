int Microphone = A0;
int Relay = 10;

int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;

void setup() {
  pinMode(Microphone, INPUT);
  pinMode(Relay, OUTPUT);
 }

void loop() {
int status_sensor = digitalRead(Microphone);
  if (status_sensor == 0)
  {
  if (clap == 0)
  {
detection_range_start = detection_range = millis();
clap++;
  }
else if (clap > 0 && millis()-detection_range >= 100)
  {
detection_range = millis();
clap++;
  }
}

if (millis()-detection_range_start >= 400)
  {
  if (clap == 2)
  {
  if (!status_lights)
  {
  
status_lights = true;
  digitalWrite(Relay, HIGH);
  }
  else if (status_lights)
  {
  status_lights = false;
  digitalWrite(Relay, LOW);
  }

  }
  clap = 0;
  }
}
