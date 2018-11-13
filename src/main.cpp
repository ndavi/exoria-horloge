
#include <Conceptinetics.h>
#include <Stepper.h>

#define DMX_SLAVE_CHANNELS   3 

const int ledPin = 53;
const int stepsPerRevolution = 23;

const int brakeMotorA[] = {28, 30};
const int directionMotorA[] = {24,22};
const int speedMotorA[] = {32, 26};

const int brakeMotorB[] = {27,25};
const int directionMotorB[] = {31,33};
const int speedMotorB[] = {23,29};

const int directionStepper[] = {12,13};
const int brakeStepper[] = {9,8};
const int speedStepper[] = {3,11};

Stepper myStepper(stepsPerRevolution, directionStepper[0],directionStepper[1]);     

int step = 0;


DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );

void setupLedpins() {
  for (int i=0; i < 2; i++) {
    pinMode(directionMotorA[i], OUTPUT); //Initiates Motor A Channel A-B pin
    pinMode(brakeMotorA[i], OUTPUT); //Initiates Brake A Channel A-B pin
  }

  for (int i=0; i < 2; i++) {
    pinMode(directionMotorB[i], OUTPUT); //Initiates Motor B Channel A-B pin
    pinMode(brakeMotorB[i], OUTPUT); //Initiates Brake B Channel A-B pin
  }

  // set the PWM and brake pins so that the direction pins  // can be used to control the motor:
  pinMode(speedStepper[0], OUTPUT);
  pinMode(speedStepper[1], OUTPUT);
  pinMode(brakeStepper[1], OUTPUT);
  digitalWrite(speedStepper[0], HIGH);
  digitalWrite(speedStepper[1], HIGH);
  pinMode(brakeStepper[0], OUTPUT);
  digitalWrite(brakeStepper[0], LOW);
  digitalWrite(brakeStepper[1], LOW);
}

void setup() {
  setupLedpins();           
  dmx_slave.enable ();  
  dmx_slave.setStartAddress (1);
  pinMode ( ledPin, OUTPUT );
  myStepper.setSpeed(20);
}

void loop() 
{
  for (int i=0; i < 2; i++) {
    digitalWrite(directionMotorA[i], HIGH); //Establishes forward direction of Channel A
    digitalWrite(brakeMotorA[i], LOW);   //Disengage the Brake for Channel A
    analogWrite(speedMotorA[i], dmx_slave.getChannelValue (1));   //Spins the motor on Channel A at full speed
  }

  for (int i=0; i < 2; i++) {
    digitalWrite(directionMotorB[i], HIGH); //Establishes forward direction of Channel A
    digitalWrite(brakeMotorB[i], LOW);   //Disengage the Brake for Channel A
    analogWrite(speedMotorB[i], dmx_slave.getChannelValue (1));   //Spins the motor on Channel A at full speed
  }
  
  if ( dmx_slave.getChannelValue (1) > 200 )
    digitalWrite ( ledPin, HIGH );
  else
    digitalWrite ( ledPin, LOW );  

  myStepper.step(stepsPerRevolution);
  delay(5000);

  myStepper.step(-stepsPerRevolution);
  delay(5000);
}