const int RANGE = 36;
const int ledPin = 22 ;

const int MIN_DIST = 15;
const int MAX_DIST = 30;

float range_val;
float range_volt;
float range_cm;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  range_val = analogRead(RANGE);
  range_volt = range_val/1240.9;
  if (range_volt > 0) {
    range_cm = 60.0/range_volt - 6;
  }
  
  if (range_cm > MIN_DIST && range_cm < MAX_DIST) {
    digitalWrite(ledPin, HIGH);
    Serial.write("high");
  } else {
    digitalWrite(ledPin, LOW);
  }
}
