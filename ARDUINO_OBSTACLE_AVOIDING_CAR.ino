#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 100  // Adjusted max distance for better sensor accuracy
#define MAX_SPEED 200     // Sets speed of DC motors
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;   

boolean goesForward = false;
int distance = 100;
int speedSet = 0;

void setup() {
  Serial.begin(9600);   // Begin Serial for debugging
  myservo.attach(10);  
  myservo.write(115); 
  delay(2000);

  // Initial distance readings for sensor calibration
  for (int i = 0; i < 5; i++) {  // Taking 5 readings
    distance += readPing();
    delay(100);
  }
  distance /= 5;  // Average reading
  Serial.println("Initial Distance: " + String(distance));
}

void loop() {
  int distanceR = 0;
  int distanceL = 0;
  delay(40);
  
  distance = readPing(); // Read distance every loop
  Serial.println("Distance Ahead: " + String(distance));

  // Increase obstacle detection distance to 25 cm
  if (distance <= 28) {  // Adjusted from 15 to 28
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(200);
    
    distanceR = lookRight();
    Serial.println("Distance Right: " + String(distanceR));
    delay(200);
    
    distanceL = lookLeft();
    Serial.println("Distance Left: " + String(distanceL));
    delay(200);

    if (distanceR >= distanceL + 5) {
      turnRight();
    } else if (distanceL >= distanceR + 5) {
      turnLeft();
    } else {
      moveBackward();  // If both distances are similar
    }
  } else {
    moveForward();
  }
}

int lookRight() {
  myservo.write(50); 
  delay(700);  // Increased delay for servo movement
  int distance = readPing();
  delay(100);
  myservo.write(115); 
  delay(100);  // Added delay to ensure servo returns
  return distance;
}

int lookLeft() {
  myservo.write(170); 
  delay(700);  // Increased delay for servo movement
  int distance = readPing();
  delay(100);
  myservo.write(115); 
  delay(100);  // Added delay to ensure servo returns
  return distance;
}

int readPing() { 
  delay(30); // Reduced delay for faster readings
  int cm = sonar.ping_cm();
  if (cm == 0) {
    Serial.println("No reading detected.");  // Debugging message
    return 250; // Return a high value if no reading
  }
  return cm;
}

void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
} 

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 10) {  // Faster ramp-up
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(3);  // Reduced delay for faster response
    }
  }
}

void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);      
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 10) {  // Faster ramp-up
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(3);  // Reduced delay for faster response
  }
}  

void turnRight() {
  int turnSpeed = MAX_SPEED / 2;  // Set a lower speed for turning
  motor1.setSpeed(turnSpeed);
  motor2.setSpeed(turnSpeed);
  motor3.setSpeed(turnSpeed);
  motor4.setSpeed(turnSpeed);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(800);  // Increased delay for full turn
}

void turnLeft() {
  int turnSpeed = MAX_SPEED / 2;  // Set a lower speed for turning
  motor1.setSpeed(turnSpeed);
  motor2.setSpeed(turnSpeed);
  motor3.setSpeed(turnSpeed);
  motor4.setSpeed(turnSpeed);

  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(800);  // Increased delay for full turn
}
