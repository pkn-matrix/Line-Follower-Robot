// --- Motor Driver Pins ---
#define ENA 10   // Enable Motor 1 (Left)
#define IN1 11   // Motor 1 Control Pin 1
#define IN2 12   // Motor 1 Control Pin 2

#define ENB 9    // Enable Motor 2 (Right)
#define IN3 8    // Motor 2 Control Pin 1
#define IN4 7    // Motor 2 Control Pin 2

// --- IR Sensor Pins ---
#define IR_LEFT  3   // Left IR Sensor
#define IR_RIGHT 4   // Right IR Sensor

// --- Speed Settings ---
#define FULL_SPEED  200  // Forward speed (0-255)
#define TURN_SPEED  150  // Turning speed (0-255)

void setup() {
  Serial.begin(9600);

  // Motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // IR sensor pins as input
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  Serial.println("Line Follower Robot Started.");
}

void loop() {
  int leftSensor  = digitalRead(IR_LEFT);
  int rightSensor = digitalRead(IR_RIGHT);

  Serial.print("Left IR: ");
  Serial.print(leftSensor);
  Serial.print("  |  Right IR: ");
  Serial.println(rightSensor);

  /*
   * IR Sensor Logic:
   * 0 = Black line detected
   * 1 = White surface detected
   */

  if (leftSensor == 1 && rightSensor == 1) {
    // Both on white — move forward
    moveForward();
  }
  else if (leftSensor == 0 && rightSensor == 1) {
    // Left on black — turn left
    turnLeft();
  }
  else if (leftSensor == 1 && rightSensor == 0) {
    // Right on black — turn right
    turnRight();
  }
  else if (leftSensor == 0 && rightSensor == 0) {
    // Both on black — stop
    stopMotors();
  }
}

// --- Motor Control Functions ---

void moveForward() {
  analogWrite(ENA, FULL_SPEED);
  analogWrite(ENB, FULL_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Action: Moving Forward");
}

void turnLeft() {
  analogWrite(ENA, TURN_SPEED);
  analogWrite(ENB, FULL_SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Action: Turning Left");
}

void turnRight() {
  analogWrite(ENA, FULL_SPEED);
  analogWrite(ENB, TURN_SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Action: Turning Right");
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Action: Stopped");
}
