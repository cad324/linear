const int avoidPin = 16;
const int ledPin = 13;
int avoidVal;

void setup() {
  Serial.begin(9600);

  pinMode(avoidPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  avoidVal = digitalRead(avoidPin);
  if (avoidVal == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("high");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.write("low");
  }
}
