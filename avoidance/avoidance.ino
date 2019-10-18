const int SENSOR = 21;
int sensorVal;

void setup() {
  Serial.begin(9600);

  pinMode(SENSOR, INPUT);
}

void loop() {
  sensorVal = digitalRead(SENSOR);
  Serial.write(sensorVal);
}
