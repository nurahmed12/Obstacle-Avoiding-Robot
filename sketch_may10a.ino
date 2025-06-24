#include "AFMotor.h"
#include <Servo.h>

// Pin definitions
const int ECHO_PIN = A0;  // echo pin
const int TRIG_PIN = A5;  // Trigger pin

// Motor definitions
const int MOTOR_1 = 3;
const int MOTOR_2 = 4;
const int MOTOR_3 = 2;
const int MOTOR_4 = 1;

// Servo object
Servo myservo;

// Motor objects
AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ);  // create motor object, 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ);  // create motor object, 64KHz pwm
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ);  // create motor object, 64KHz pwm
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ);  // create motor object, 64KHz pwm

// Distance variables
int distanceLeft, distanceFront, distanceRight;

// Set distance threshold
const int SET_DISTANCE = 40;

void setup() {
  Serial.begin(9600);  // Initialize serial port
  Serial.println("Start");

  myservo.attach(10);
  delay(500);  // Allow servo to initialize
  myservo.write(90);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize motor speeds
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  motor4.setSpeed(180);
}

void loop() {
  distanceFront = getDistance();
  while (distanceFront > SET_DISTANCE) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    delay(10);
    distanceFront = getDistance();
  }
  stopMotors();
  scanAndAvoid();
}

// Get distance using ultrasonic sensor
int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration / 58.2;  // Correct distance calculation
}

// Move forward
void moveForward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

// Stop motors
void stopMotors() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

// Scan and avoid obstacles
void scanAndAvoid() {
  myservo.write(180);
  delay(500);
  distanceRight = getDistance();
  delay(500);
  myservo.write(0);
  delay(900);
  distanceLeft = getDistance();
  delay(500);
  myservo.write(90);
  delay(500);

  if (distanceRight <= SET_DISTANCE && distanceLeft <= SET_DISTANCE) {
    turnAround();
  } else if (distanceRight > distanceLeft) {
    turnRight();
  } else if (distanceLeft > distanceRight) {
    turnLeft();
  }
}

// Turn left
void turnLeft() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(500);
  stopMotors();
}

// Turn right
void turnRight() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
  stopMotors();
}

// Turn around
void turnAround() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(300);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(1000);
}