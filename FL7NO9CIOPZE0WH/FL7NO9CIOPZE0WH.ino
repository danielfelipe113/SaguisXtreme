#include <Servo.h>


// SoftwareSerial BT(10, 11); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND

Servo ServoMotor;

int MotorLeft1 = 3;
int MotorLeft2 = 9;
int MotorRight1 = 5;
int MotorRight2 = 6;
int ServoMotorPin = 1;
int interval = 100;

void setup() {
  // set digital pin to control as an output
  pinMode(MotorLeft1, OUTPUT);
  pinMode(MotorLeft2, OUTPUT);
  pinMode(MotorRight2, OUTPUT);
  pinMode(MotorRight1, OUTPUT);
  ServoMotor.attach(10);
  ServoMotor.write(10);
  
  // set the data rate for the SoftwareSerial port
  Serial.begin(9600);
  // Send test message to other device
  Serial.println("Hello from Arduino");
}


char a; // stores incoming character from other device

void loop() {
  if (Serial.available()) {
    // if text arrived in from BT serial...
    a=(Serial.read());
    Serial.println("Input was: ");
    Serial.print(a);
    if(a=='9') {
      ServoMotor.write(10);
      Serial.println("Moving servo 0");
    }
    if(a=='8') {
      ServoMotor.write(45);
      Serial.println("Moving servo 45");
    }
    if (a=='1') {
      digitalWrite(MotorLeft1, HIGH);
      digitalWrite(MotorLeft2, LOW);
      
      digitalWrite(MotorRight1, HIGH);
      digitalWrite(MotorRight2, LOW);
      
      Serial.println("Forward");
      delay(interval);
      digitalWrite(MotorLeft1, LOW);
      digitalWrite(MotorRight1, LOW);
      
    }
    if (a=='2') {
      digitalWrite(MotorLeft2, 180);
      digitalWrite(MotorLeft1, 0);
      digitalWrite(MotorRight2, 180);
      digitalWrite(MotorRight1, 0);
      Serial.println("Backwards");
      delay(interval);
      digitalWrite(MotorLeft2, LOW);
      digitalWrite(MotorRight2, LOW);
    }
    if (a=='3') {
      digitalWrite(MotorLeft1, 0);
      digitalWrite(MotorLeft2, 100);
      
      digitalWrite(MotorRight1, 255);
      digitalWrite(MotorRight2, 0);
      Serial.println("Left");
      delay(interval);
      digitalWrite(MotorRight1, 0);
      digitalWrite(MotorLeft2, 0);
    }   
    if (a=='4') {
      digitalWrite(MotorLeft1, 255);
      digitalWrite(MotorLeft2, LOW);
      digitalWrite(MotorRight2, 100);
      digitalWrite(MotorRight1, LOW);
      Serial.println("Right");
      delay(interval);
      digitalWrite(MotorLeft1, LOW);
      digitalWrite(MotorRight2, LOW);
    }
  }

  
}
