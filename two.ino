#include <AFMotor.h>

// Initialize motors pins
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;

const int tdsPin = A5; // Analog pin A0 for TDS sensor

void setup() {
  Serial.begin(9600);  // Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){
    command = Serial.read();
    Stop(); // Initialize with motors stopped
    // Change pin mode only if new command is different from previous.
    // Serial.println(command);
    switch(command){
      case 'U':
        forward();
        break;
      case 'D':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
    }
  }
  
  // Read and display TDS sensor value
  int tdsValue = analogRead(tdsPin);
  Serial.print("TDS Value: ");
  Serial.println(tdsValue);
  delay(1000); // Adjust delay as needed
}

void forward() {
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(FORWARD); // Rotate the motor clockwise
}

void back() {
  motor1.setSpeed(255); // Define maximum velocity
  motor1.run(BACKWARD); // Rotate the motor clockwise
}

void left() {
  motor3.setSpeed(255); // Define maximum velocity
  motor3.run(FORWARD);  // Rotate the motor clockwise
}

void right() {
  motor4.setSpeed(255); // Define maximum velocity
  motor4.run(BACKWARD); // Rotate the motor anti-clockwise   
}

void Stop() {
  motor1.setSpeed(0); // Define minimum velocity
  motor1.run(RELEASE); // Stop the motor when release the button
  motor2.setSpeed(0); // Define minimum velocity
  motor2.run(RELEASE); // Rotate the motor clockwise
  motor3.setSpeed(0); // Define minimum velocity
  motor3.run(RELEASE); // Stop the motor when release the button
  motor4.setSpeed(0); // Define minimum velocity
  motor4.run(RELEASE); // Stop the motor when release the button
}
