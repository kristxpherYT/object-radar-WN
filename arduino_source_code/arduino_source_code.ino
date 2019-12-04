// Includes the Servo and NewPing libraries
#include <Servo.h>
#include <NewPing.h>

#define MAX_DISTANCE_POSSIBLE 50
#define MIN_ANGLE 15
#define MAX_ANGLE 165

// Defines Trigger and Echo pins of the Ultrasonic Sensor
#define TRIGGER_PIN 10
#define ECHO_PIN 11

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE_POSSIBLE);

// Variables for the duration and the distance
long duration;
int distance;

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT); // Sets the trigger Pin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echo Pin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}

void loop() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i = MIN_ANGLE; i <= MAX_ANGLE; i++) {  
    myServo.write(i);
    delay(20);
    distance = readPing(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    
    Serial.print(i); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i = MAX_ANGLE; i > MIN_ANGLE; i--) {  
    myServo.write(i);
    delay(30);
    distance = readPing();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

//Our sensor reading in cm.
int readPing() {
  unsigned int cm = sonar.ping_cm();
  return cm;
}
