#include <Keyboard.h>
// these constants won't change:
const int ledPin = 13;       // LED connected to digital pin 13
const int knockSensor = A3;  // the piezo is connected to analog pin 0
const int knockSensor2 = A2;  // the piezo is connected to analog pin 1
const int knockSensor3 = A1;  // the piezo is connected to analog pin 2
const int knockSensor4 = A0;  // the piezo is connected to analog pin 3
const int threshold = 40;   // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;
int sensorReading2 = 0;
int sensorReading3 = 0;
int sensorReading4 = 0;  // variable to store the value read from the sensor pin
int ledState = LOW;     // variable used to store the last LED status, to toggle the light
bool key1 = false;
bool key2 = false;
bool key3 = false;
bool key4 = false;

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
  if (sensorReading >= threshold && !key1) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading);
    //Keyboard.write('a');
    Keyboard.press('j');
    key1 = true;
  }

  if (sensorReading2 >= threshold && !key2) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading2);
    Keyboard.press('k');
    key2 = true;
  }

  if (sensorReading3 >= threshold && !key3) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading3);
    Keyboard.press('l');
    key3 = true;
  }

  if (sensorReading4 >= threshold && !key4) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println(sensorReading4);
    Keyboard.press(';');
    key4 = true;
  }
  
  if(sensorReading <= 0 && key1){
    Keyboard.release('j');
    key1 = false;
  }

  if(sensorReading2 <= 0 && key2){
    Keyboard.release('k');
    key2 = false;
  }

  if(sensorReading3 <= 0 && key3){
    Keyboard.release('l');
    key3 = false;
  }

  if(sensorReading4 <= 0 && key4){
    Keyboard.release(';');
    key4 = false;
  }
  delay(20);
}
