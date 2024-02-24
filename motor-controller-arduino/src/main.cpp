/*
  HighPrecisionStepperJuggler
  Author: T-Kuhn.
  Sapporo, January, 2020. Released into the public domain.
 */

#include "Constants.h"
#include <SineStepper.h>
#include <SineStepperController.h>
#include <MoveBatch.h>
#include <TimerOne.h>

enum Mode
{
  idle,
  doingControlledMovements,
  error
};


Mode currentMode = idle;
char inputBuffer[INPUT_SIZE + 1];


SineStepper sineStepper1(STEPPER1_STEP_PIN, STEPPER1_DIR_PIN, /*id:*/ 0);
// SineStepper sineStepper2(STEPPER2_STEP_PIN, STEPPER2_DIR_PIN, /*id:*/ 1);
// SineStepper sineStepper3(STEPPER3_STEP_PIN, STEPPER3_DIR_PIN, /*id:*/ 2);
// SineStepper sineStepper4(STEPPER4_STEP_PIN, STEPPER4_DIR_PIN, /*id:*/ 3);

SineStepperController sineStepperController(/*endlessRepeat:*/ false);
//IntervalTimer myTimer;
//const int dirPin_M1 = 2;
//const int stepPin_M1 = 3;
//const int enPin_M1 = 4;
const int dirPin_M2 = 5;
const int stepPin_M2 = 6;
const int enPin_M2 = 7;
const int dirPin_M3 = 8;
const int stepPin_M3 = 9;
const int enPin_M3 = 10;
const int dirPin_M4 = 11;
const int stepPin_M4 = 12;
const int enPin_M4 = 13;
const int timeDelay = 100;

void onTimer()
{
  //digitalWrite(EXECUTING_ISR_CODE, HIGH);

  switch (currentMode)
  {
  case idle:
    break;
  case doingControlledMovements:
    //sineStepperController.update();
    break;
  default:
    break;
  }
  //Serial.print(".");
  //digitalWrite(EXECUTING_ISR_CODE, LOW);
}

void setup()
{
  //pinMode(enPin_M1, OUTPUT);
  pinMode(enPin_M2, OUTPUT);
  pinMode(enPin_M3, OUTPUT);
  pinMode(enPin_M4, OUTPUT);
  //pinMode(dirPin_M1, OUTPUT);
  pinMode(dirPin_M2, OUTPUT);
  pinMode(dirPin_M3, OUTPUT);
  pinMode(dirPin_M4, OUTPUT);
  //pinMode(stepPin_M1, OUTPUT);
  pinMode(stepPin_M2, OUTPUT);
  pinMode(stepPin_M3, OUTPUT);
  pinMode(stepPin_M4, OUTPUT);
  //digitalWrite(enPin_M1, LOW);
  digitalWrite(enPin_M2, LOW);
  digitalWrite(enPin_M3, LOW);
  digitalWrite(enPin_M4, LOW);
  Serial.begin(230400);
  //inputBuffer[0] = '\0';
  //Serial.setTimeout(1);
  //myTimer.begin(onTimer, TIMER_US);
  Timer1.initialize(TIMER_US);     // initialize timer with 1 second interval (in microseconds)
  Timer1.attachInterrupt(onTimer); // attach the interrupt function
  
  pinMode(EXECUTING_ISR_CODE, OUTPUT);
  sineStepperController.attach(&sineStepper1);
  /*
  sineStepperController.attach(&sineStepper2);
  sineStepperController.attach(&sineStepper3);
  sineStepperController.attach(&sineStepper4);
  */
}

void loop()
{
  //digitalWrite(dirPin_M1, HIGH); // Enables the motor1 to move in a particular direction
  digitalWrite(dirPin_M2, HIGH); // Enables the motor2 to move in a particular direction
  digitalWrite(dirPin_M3, HIGH); // Enables the motor3 to move in a particular direction
  digitalWrite(dirPin_M4, HIGH); // Enables the motor4 to move in a particular direction
  for (int x = 0; x < 1800; x++)
  {
    //digitalWrite(stepPin_M1, HIGH);
    digitalWrite(stepPin_M2, HIGH);
    digitalWrite(stepPin_M3, HIGH);
    digitalWrite(stepPin_M4, HIGH);
    delayMicroseconds(timeDelay);
    //digitalWrite(stepPin_M1, LOW);
    digitalWrite(stepPin_M2, LOW);
    digitalWrite(stepPin_M3, LOW);
    digitalWrite(stepPin_M4, LOW);
    delayMicroseconds(timeDelay);
  }
  delay(100);               // One second delay
  //digitalWrite(dirPin_M1, LOW); // Changes the direction of rotation of M1
  digitalWrite(dirPin_M2, LOW); // Changes the direction of rotation of M2
  digitalWrite(dirPin_M3, LOW); // Changes the direction of rotation of M3
  digitalWrite(dirPin_M4, LOW); // Changes the direction of rotation of M4
  for (int x = 0; x < 1800; x++)
  {
    //digitalWrite(stepPin_M1, HIGH);
    digitalWrite(stepPin_M2, HIGH);
    digitalWrite(stepPin_M3, HIGH);
    digitalWrite(stepPin_M4, HIGH);
    delayMicroseconds(timeDelay);
    //digitalWrite(stepPin_M1, LOW);
    digitalWrite(stepPin_M2, LOW);
    digitalWrite(stepPin_M3, LOW);
    digitalWrite(stepPin_M4, LOW);
    delayMicroseconds(timeDelay);
  }
  delay(100);
  /*
  if (Serial.available() > 0)
  {
    char inputChar = Serial.read();
    static int s_len;
    if (s_len >= INPUT_SIZE)
    {
      // We have received already the maximum number of characters
      // Ignore all new input until line termination occurs
    }
    else if (inputChar != '\n' && inputChar != '\r')
    {
      inputBuffer[s_len++] = inputChar;
    }
    else
    {
      // We have received a LF or CR character
      Serial.print("RECEIVED MSG: ");
      Serial.println(inputBuffer);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  */
  /*
      inputBuffer[s_len] = 0;

      currentMode = idle;
      int index = 0;
      double instructionData[MAX_NUM_OF_MOVEBATCHES * 6];
      for (int i = 0; i < MAX_NUM_OF_MOVEBATCHES * 6; i++)
      {
        instructionData[i] = 0;
      }

      // Read each command
      char *command = strtok(inputBuffer, ":");
      while (command != 0)
      {
        instructionData[index] = atof(command);

        command = strtok(0, ":");
        index++;
      }

      int numOfMoveBatches = index / 6;
      for (int i = 0; i < numOfMoveBatches; i++)
      {
        int offset = i * 6;
        MoveBatch *mb = &sineStepperController.moveBatches[i];
        if (instructionData[offset] > ((i + 1) * 11.0) - 0.1 && instructionData[offset] < ((i + 1) * 11) + 0.1)
        {
  */
          //mb->addMove(/*id:*/ 0, /*pos:*/ (int32_t)(PULSES_PER_REV * (instructionData[offset + 1] / (M_PI * 2))));
          //mb->addMove(/*id:*/ 1, /*pos:*/ (int32_t)(PULSES_PER_REV * (instructionData[offset + 2] / (M_PI * 2))));
          //mb->addMove(/*id:*/ 2, /*pos:*/ (int32_t)(PULSES_PER_REV * (instructionData[offset + 3] / (M_PI * 2))));
          //mb->addMove(/*id:*/ 3, /*pos:*/ (int32_t)(PULSES_PER_REV * (instructionData[offset + 4] / (M_PI * 2))));
          //mb->moveDuration = instructionData[offset + 5];
  /*
        }
      }

      sineStepperController.resetMoveBatchExecution();
      currentMode = doingControlledMovements;

      memset(inputBuffer, 0, sizeof(inputBuffer));
      s_len = 0;
    }
  }
  */
}