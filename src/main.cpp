
#include <Conceptinetics.h>
#include <Stepper.h>
#include <Arduino.h>


#define DMX_SLAVE_CHANNELS   2
#define DMX_START_ADRESS     1
#define DEBUG                true
#define DEBUG_SPEED          255
#define DEBUG_SENS           LOW
#define DMX                  true

const int brakeMotorA[] = {28, 30};
const int directionMotorA[] = {24,22};
const int speedMotorA[] = {32, 26};

/*const int brakeMotorB[] = {27,25};
const int directionMotorB[] = {31,33};
const int speedMotorB[] = {23,29};*/

const int entreeA = 44;
const int entreeB = 46;


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

}

void setup() {
  if(DEBUG) {
    //Serial.begin(9600);
  }
  if(DMX) {
    dmx_slave.enable();
    dmx_slave.setStartAddress(DMX_START_ADRESS);
  }  
  setupMotors();  
}

void loop() 
{
    delay(100);
  
    if(analogRead(A11) == 1023) {
        for (int i=0; i < 2; i++) {
        analogWrite(speedMotorA[i], 255);
        digitalWrite(directionMotorA[i], HIGH); 
        digitalWrite(brakeMotorA[i], LOW);   //Disengage the Brake for Channel A
        }
    } else if (analogRead(A12) == 1023) {
        for (int i=0; i < 2; i++) {
        analogWrite(speedMotorA[i], 255);
        digitalWrite(directionMotorA[i], LOW); 
        digitalWrite(brakeMotorA[i], LOW);   //Disengage the Brake for Channel A
        }
    } else {
        for (int i=0; i < 2; i++) {
          if(dmx_slave.getChannelValue(1) < 255) {
              analogWrite(speedMotorA[i], 0);
              digitalWrite(brakeMotorA[i], HIGH);   //Disengage the Brake for Channel A
          } else if(dmx_slave.getChannelValue(1) == 255) {
              analogWrite(speedMotorA[i], 255);
              digitalWrite(brakeMotorA[i], LOW);   //engage the Brake for Channel A
          }
          if(dmx_slave.getChannelValue(2) == 0) {
              digitalWrite(directionMotorA[i], LOW);
          } else if(dmx_slave.getChannelValue(2) == 255) {
              digitalWrite(directionMotorA[i], HIGH);
          }
        }
    }
}