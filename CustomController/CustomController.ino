#include <Keyboard.h>
// these constants won't change:
const int ledPin = 13;       // LED connected to digital pin 13
const int knockSensor = A0;  // the piezo is connected to analog pin 0
const int knockSensor2 = A1;  // the piezo is connected to analog pin 1
const int knockSensor3 = A2;  // the piezo is connected to analog pin 2
const int knockSensor4 = A3;  // the piezo is connected to analog pin 3
const int threshold = 20;   // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;
int sensorReading2 = 0;
int sensorReading3 = 0;
int sensorReading4 = 0;  // variable to store the value read from the sensor pin
int ledState = LOW;     // variable used to store the last LED status, to toggle the light

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
  Keyboard.begin();
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  sensorReading2 = analogRead(knockSensor2);
  sensorReading3 = analogRead(knockSensor3);
  sensorReading4 = analogRead(knockSensor4);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading);
    //Keyboard.write('a');
    Keyboard.press('a');
  }

  if (sensorReading2 >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading2);
    Keyboard.press('s');
  }

  if (sensorReading3 >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading3);
    Keyboard.press('d');
  }

  if (sensorReading4 >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading4);
    Keyboard.press('f');
  }
  
  delay(20);  // delay to avoid overloading the serial port buffer
  Keyboard.releaseAll();
}
