/*#include <Conceptinetics.h>
#include <Stepper.h>
#include <Arduino.h>


#define DMX_SLAVE_CHANNELS   3 
#define DMX_START_ADRESS     1
#define DEBUG                true
#define DEBUG_SPEED          255
#define DEBUG_SENS           LOW
#define DMX                  false

const int ledPin = 53;
const int entreeA = 44;
const int entreeB = 46;

const int brakeMotorA[] = {28, 30};
const int directionMotorA[] = {24,22};
const int speedMotorA[] = {32, 26};

const int brakeMotorB[] = {27,25};
const int directionMotorB[] = {31,33};
const int speedMotorB[] = {23,29};


DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

int motorSpeedA = DEBUG_SPEED;
int motorSpeedB = DEBUG_SPEED;
int sensMotorA = LOW;
int sensMotorB = LOW;


void setupMotors() {
  for (int i=0; i < 2; i++) {
    pinMode(directionMotorA[i], OUTPUT); //Initiates Motor A Channel A-B pin
    pinMode(brakeMotorA[i], OUTPUT); //Initiates Brake A Channel A-B pin
  }

  for (int i=0; i < 2; i++) {
    pinMode(directionMotorB[i], OUTPUT); //Initiates Motor B Channel A-B pin
    pinMode(brakeMotorB[i], OUTPUT); //Initiates Brake B Channel A-B pin
  }
  //pinMode(entreeA, INPUT);
  //pinMode(entreeB, INPUT);

}

void setup() {
  if(DEBUG) {
    Serial.begin(9600);
  }
  if(DMX) {
    dmx_slave.enable();
    dmx_slave.setStartAddress(DMX_START_ADRESS);
  }  
  pinMode(entreeA, INPUT);  
  pinMode(entreeB, INPUT);   
  setupMotors();  
}

void loop() 
{

  if(digitalRead(entreeA) == HIGH) {
    Serial.println("HIGH");
    for (int i=0; i < 2; i++) {
      digitalWrite(directionMotorA[i], HIGH); //Establishes forward direction of Channel A
      digitalWrite(brakeMotorA[i], LOW);   //Disengage the Brake for Channel A
      analogWrite(speedMotorA[i], 255);   //Spins the motor on Channel A at full speed
    }

  } else if(digitalRead(entreeB) == HIGH) {
    Serial.println("LOW");
    for (int i=0; i < 2; i++) {
      digitalWrite(directionMotorA[i], LOW); //Establishes forward direction of Channel A
      digitalWrite(brakeMotorA[i], LOW);   //Disengage the Brake for Channel A
      analogWrite(speedMotorA[i], 255);   //Spins the motor on Channel A at full speed
    }
  } else {
    for (int i=0; i < 2; i++) {
      digitalWrite(directionMotorA[i], LOW); //Establishes forward direction of Channel A
      digitalWrite(brakeMotorA[i], LOW);   //Disengage the Brake for Channel A
      analogWrite(speedMotorA[i], 0);   //Spins the motor on Channel A at full speed
    }
  }
  
}
*/