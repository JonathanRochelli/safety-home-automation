/*
* Ultrasonic Sensor HC-SR04
*/

// defines pins numbers
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const float SOUND_SPEED = 340.0 / 1000;

// defines variables
long duration;
int distance;

void setup() 
{
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() 
{
  digitalWrite(TRIG_PIN, LOW); // Clears the trigPin
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*SOUND_SPEED/2; // Calculating the distance
  Serial.print(distance / 1000.0, 2); // Prints the distance on the Serial Monitor
  delay(500);
}
