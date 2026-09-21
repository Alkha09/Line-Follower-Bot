// IR Sensors
int leftSensor = 2;
int rightSensor = 3;

// L298N Motor Driver
int ENA = 5;   // Left motor speed
int IN1 = 6;
int IN2 = 7;

int ENB = 9;   // Right motor speed
int IN3 = 10;
int IN4 = 11;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void turnLeft() {
  // Stop left motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Right motor moves
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 160);
}

void turnRight() {
  // Left motor moves
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Stop right motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 160);
  analogWrite(ENB, 0);
}

void stopBot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void loop() {

  int left = digitalRead(leftSensor);
  int right = digitalRead(rightSensor);

  // Both sensors on white
  if (left == HIGH && right == HIGH) {
    forward();
  }

  // Left sensor detects black
  else if (left == LOW && right == HIGH) {
    turnLeft();
  }

  // Right sensor detects black
  else if (left == HIGH && right == LOW) {
    turnRight();
  }

  // Both sensors detect black
  else {
    stopBot();
  }
}