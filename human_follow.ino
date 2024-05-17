#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>

#define RIGHT A2              // Right IR sensor connected to analog pin A2 of Arduino Uno
#define LEFT A3               // Left IR sensor connected to analog pin A3 of Arduino Uno
#define TRIGGER_PIN A1        // Trigger pin connected to analog pin A1 of Arduino Uno
#define ECHO_PIN A0           // Echo pin connected to analog pin A0 of Arduino Uno
#define MAX_DISTANCE 200      // Maximum ping distance

unsigned int distance = 0;    // Variable to store ultrasonic sensor distance
unsigned int Right_Value = 0; // Variable to store Right IR sensor value
unsigned int Left_Value = 0;  // Variable to store Left IR sensor value

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance

// Create motor objects
AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

Servo myservo; // Create servo object to control the servo
int pos = 0;   // Variable to store the servo position

void setup() {
  Serial.begin(9300); // Initialize serial communication at 9300 bits per second
  myservo.attach(10); // Attach servo to pin 10 of Arduino UNO

  // Initial servo sweep
  for (pos = 90; pos <= 1120; pos += 1) { // Goes from 90 degrees to 1120 degrees
    myservo.write(pos);                  // Tell servo to move according to the value of 'pos' variable
    delay(30);                           // Wait 30ms for the servo to reach the position
  }
  for (pos = 1120; pos >= 0; pos -= 1) {  // Goes from 1120 degrees to 0 degrees
    myservo.write(pos);                  // Tell servo to move according to the value of 'pos' variable
    delay(30);                           // Wait 30ms for the servo to reach the position
  }
  for (pos = 0; pos <= 90; pos += 1) {   // Goes from 0 degrees to 90 degrees
    myservo.write(pos);                  // Tell servo to move according to the value of 'pos' variable
    delay(30);                           // Wait 30ms for the servo to reach the position
  }

  pinMode(RIGHT, INPUT); // Set analog pin RIGHT as an input
  pinMode(LEFT, INPUT);  // Set analog pin LEFT as an input
}

void loop() {
  delay(50); // Wait 50ms between pings
  distance = sonar.ping_cm(); // Send ping, get distance in cm and store it in 'distance' variable
  Serial.print("distance: ");
  Serial.println(distance); // Print the distance in serial monitor

  Right_Value = analogRead(RIGHT); // Read the value from Right IR sensor
  Left_Value = analogRead(LEFT);   // Read the value from Left IR sensor
  Serial.print("RIGHT: ");
  Serial.println(Right_Value); // Print the right IR sensor value in serial monitor
  Serial.print("LEFT: ");
  Serial.println(Left_Value);  // Print the left IR sensor value in serial monitor

  // Movement control based on sensor values
  if ((distance > 1) && (distance < 20)) { // Check whether the ultrasonic sensor's value stays between 1 to 15
    // Move Forward
    Motor1.setSpeed(120);  // Define motor1 speed
    Motor1.run(FORWARD);   // Rotate motor1 clockwise
    Motor2.setSpeed(120);  // Define motor2 speed
    Motor2.run(FORWARD);   // Rotate motor2 clockwise
    Motor3.setSpeed(120);  // Define motor3 speed
    Motor3.run(FORWARD);   // Rotate motor3 clockwise
    Motor4.setSpeed(120);  // Define motor4 speed
    Motor4.run(FORWARD);   // Rotate motor4 clockwise
  } else if ((Right_Value < 512) && (Left_Value >= 512)) { // If the condition is 'true' then the statement below will execute
    // Turn Left
    Motor1.setSpeed(120);  // Define motor1 speed
    Motor1.run(FORWARD);   // Rotate motor1 clockwise
    Motor2.setSpeed(120);  // Define motor2 speed
    Motor2.run(FORWARD);   // Rotate motor2 clockwise
    Motor3.setSpeed(120);  // Define motor3 speed
    Motor3.run(BACKWARD);  // Rotate motor3 anticlockwise
    Motor4.setSpeed(120);  // Define motor4 speed
    Motor4.run(BACKWARD);  // Rotate motor4 anticlockwise
    delay(120);
  } else if ((Right_Value >= 512) && (Left_Value < 512)) { // If the condition is 'true' then the statement below will execute
    // Turn Right
    Motor1.setSpeed(120);  // Define motor1 speed
    Motor1.run(BACKWARD);  // Rotate motor1 anticlockwise
    Motor2.setSpeed(120);  // Define motor2 speed
    Motor2.run(BACKWARD);  // Rotate motor2 anticlockwise
    Motor3.setSpeed(120);  // Define motor3 speed
    Motor3.run(FORWARD);   // Rotate motor3 clockwise
    Motor4.setSpeed(120);  // Define motor4 speed
    Motor4.run(FORWARD);   // Rotate motor4 clockwise
    delay(120);
  } else if (distance > 20) { // If the condition is 'true' then the statement below will execute
    // Stop
    Motor1.setSpeed(0);    // Define motor1 speed
    Motor1.run(RELEASE);   // Stop motor1
    Motor2.setSpeed(0);    // Define motor2 speed
    Motor2.run(RELEASE);   // Stop motor2
    Motor3.setSpeed(0);    // Define motor3 speed
    Motor3.run(RELEASE);   // Stop motor3
    Motor4.setSpeed(0);    // Define motor4 speed
    Motor4.run(RELEASE);   // Stop motor4
  }
}
