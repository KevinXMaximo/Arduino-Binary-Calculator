#include <string.h>

// delay contants
const int delayTime = 300;
const int loopTime = 2;

// display Pins
int pinA = 2; /* Atmega port 2 is connected to display port 11 */
int pinB = 3; /* Atmega port 3 is connected to display port 7 */
int pinC = 4; /* Atmega port 4 is connected to display port 4 */
int pinD = 5; /* Atmega port 5 is connected to display port 2 */
int pinE = 6; /* Atmega port 6 is connected to display port 1 */
int pinF = 7; /* Atmega port 7 is connected to display port 10 */
int pinG = 8; /* Atmega port 8 is connected to display port 5 */
int D1 = 9; /* Atmega port 9 is connected to display port 12 */
int D2 = 10; /* Atmega port 10 is connected to display port 9 */
int D3 = A4; /* Atmega port 11 is connected to display port 8 */
int D4 = A5; /* Atmega port 12 is connected to display port 6 */

// button pins
int Button1 = 13;
int Button2 = 12;
int Button3 = 11;

// digit variables (these will store the users input for each binary digit)
String digit1;
String digit2;
String digit3;
String digit4;

//converted digit variables (these will store the individual user's digits convereted to int)
int convertedDigit1;
int convertedDigit2;
int convertedDigit3;
int convertedDigit4;
int convertedDigit5;
int convertedDigit6;
int convertedDigit7;
int convertedDigit8;

// variables to store the two values to be added
int binary1;
int binary2;

// variable which the operation to be performed and its result
int operation;
int result;

// constants used as a placeholder for numbers, arduino refuses to evaluate "if" conditions as true without them
String zero = "0";
String one = "1";

// placeholder variable to hold a while loop
int holdState = 0;

// main setup function
void setup() {

  /* make all of the digital pins connected to the display output */
  pinMode(pinA, OUTPUT); /* pins A through B represent different segments of the display */
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT); /* D1 through D4 represent each of the four digits of the display */
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  // sets the three button pins to input
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);

}

void loop() {

  // prints prompt "DIG1" and registers first user input, runs until user presses button 3 (ENTER)
  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    // if user presses button 1 they will input a 0
    if (digitalRead(Button1) == HIGH)
    {
      digit1 = '0';
      delay(delayTime); // delays like these are used as a cooldown for button input
    }

    // if user presses button 2 they will input a 1
    if (digitalRead(Button2) == HIGH)
    {
      digit1 = '1';
      delay(delayTime);
    }

  }

  // delays are placed in order to cool down button inputs
  delay(delayTime);

  // prints the number(s) the user has input so far
  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit2 = '0';
      delay(delayTime);
    }

    if (digitalRead(Button2) == HIGH)
    {
      digit2 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit3 = '0';
      delay(delayTime);

    }

    if (digitalRead(Button2) == HIGH)
    {
      digit3 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit4 = '0';
      delay(delayTime);
    }

    if (digitalRead(Button2) == HIGH)
    {
      digit4 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit4 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, HIGH);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit4 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, HIGH);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  // stores user input into the appropriate variables which will later be turned to decimal values and added into binary1
  convertedDigit1 = digit4.toInt();
  convertedDigit2 = digit3.toInt();
  convertedDigit3 = digit2.toInt();
  convertedDigit4 = digit1.toInt();

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    // if user presses button 1 they will input a 0
    if (digitalRead(Button1) == HIGH)
    {
      operation = 0;
      delay(delayTime); // delays like these are used as a cooldown for button input
    }

    // if user presses button 2 they will input a 1
    if (digitalRead(Button2) == HIGH)
    {
      operation = 1;
      delay(delayTime);
    }

  }

  Serial.println(operation);

  delay(delayTime);

  // repeats the process to ask user for input
  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit1 = '0';
      delay(delayTime);
    }

    if (digitalRead(Button2) == HIGH)
    {
      digit1 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit2 = '0';
      delay(delayTime);
    }

    if (digitalRead(Button2) == HIGH)
    {
      digit2 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit3 = '0';
      delay(delayTime);

    }

    if (digitalRead(Button2) == HIGH)
    {
      digit3 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, HIGH);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, HIGH);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);

    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, HIGH);

    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(loopTime);

    if (digitalRead(Button1) == HIGH)
    {
      digit4 = '0';
      delay(delayTime);
    }

    if (digitalRead(Button2) == HIGH)
    {
      digit4 = '1';
      delay(delayTime);
    }

  }

  delay(delayTime);

  while (digitalRead(Button3) == LOW)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit4 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, HIGH);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit4 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, HIGH);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }

  delay(delayTime);

  // stores second user input into the appropriate variables to be added into binary2
  convertedDigit5 = digit4.toInt();
  convertedDigit6 = digit3.toInt();
  convertedDigit7 = digit2.toInt();
  convertedDigit8 = digit1.toInt();

  // converts the binary values into what will become decimal, by multiplying the value of each house
  convertedDigit2 *= 2; // for example, convertedDigit2 is in the second binary house, therefore it needs to be multiplied by 2
  convertedDigit3 *= 4;
  convertedDigit4 *= 8;
  convertedDigit6 *= 2;
  convertedDigit7 *= 4;
  convertedDigit8 *= 8;

  // adds the values together to get a definitive decimal value
  binary1 = convertedDigit1 + convertedDigit2 + convertedDigit3 + convertedDigit4;
  binary2 = convertedDigit5 + convertedDigit6 + convertedDigit7 + convertedDigit8;

  // performs the correct operation on the two values to obtain a result
  if (operation == 0) {
    result = binary1 * binary2;
  }

  if (operation == 1) {
    result = binary1 + binary2;
  }

  // these check the result of the operation and save the appropriate digits
  if (result == 15) {
    digit1 = '1';
    digit2 = '1';
    digit3 = '1';
    digit4 = '1';

  }

  if (result == 14) {
    digit1 = '1';
    digit2 = '1';
    digit3 = '1';
    digit4 = '0';
  }

  if (result == 13) {
    digit1 = '1';
    digit2 = '1';
    digit3 = '0';
    digit4 = '1';
  }

  if (result == 12) {
    digit1 = '1';
    digit2 = '1';
    digit3 = '0';
    digit4 = '0';
  }

  if (result == 11) {
    digit1 = '1';
    digit2 = '0';
    digit3 = '1';
    digit4 = '1';
  }

  if (result == 10) {
    digit1 = '1';
    digit2 = '0';
    digit3 = '1';
    digit4 = '0';
  }

  if (result == 9) {
    digit1 = '1';
    digit2 = '0';
    digit3 = '0';
    digit4 = '1';
  }

  if (result == 8) {
    digit1 = '1';
    digit2 = '0';
    digit3 = '0';
    digit4 = '0';
  }

  if (result == 7) {
    digit1 = '0';
    digit2 = '1';
    digit3 = '1';
    digit4 = '1';
  }

  if (result == 6) {
    digit1 = '0';
    digit2 = '1';
    digit3 = '1';
    digit4 = '0';
  }

  if (result == 5) {
    digit1 = '0';
    digit2 = '1';
    digit3 = '0';
    digit4 = '1';
  }


  if (result == 4) {
    digit1 = '0';
    digit2 = '1';
    digit3 = '0';
    digit4 = '0';
  }


  if (result == 3) {
    digit1 = '0';
    digit2 = '0';
    digit3 = '1';
    digit4 = '1';
  }


  if (result == 2) {
    digit1 = '0';
    digit2 = '0';
    digit3 = '1';
    digit4 = '0';
  }


  if (result == 1) {
    digit1 = '0';
    digit2 = '0';
    digit3 = '0';
    digit4 = '1';
  }

  // displays final result and keeps displaying it until microcontroller is reset
  while (holdState == 0)
  {

    if (digit1 == zero)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit1 == one)
    {
      pinMode(D1, HIGH);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit2 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, HIGH);
      pinMode(D3, LOW);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit3 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, HIGH);
      pinMode(D4, LOW);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit4 == zero)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, HIGH);

      /* 0 */
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

    if (digit4 == one)
    {
      pinMode(D1, LOW);
      pinMode(D2, LOW);
      pinMode(D3, LOW);
      pinMode(D4, HIGH);

      /* 1 */
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      delay(loopTime); /* wait for a second */
    }

  }
  
}
