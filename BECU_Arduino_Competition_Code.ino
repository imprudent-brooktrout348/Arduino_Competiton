#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// Pin definitions
const int pressureSensorPin = A0;   // Pressure sensor connected to analog pin A0
const int buzzerPin = 9;	// Buzzer pin

const int led1 = 8;
const int led2 = 13;
const int led3 = 12;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize pins
  pinMode(pressureSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
 }

void loop() {
  // Read pressure sensor value
  int pressureValue = analogRead(pressureSensorPin);
  digitalWrite(led1, HIGH); //Turn on the alert LED

  digitalWrite(led2, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite (led3, LOW);

  PressureChecker(pressureSensorPin);

  delay(500);// wait for a half second

  pressureValue = analogRead(pressureSensorPin);
  digitalWrite(led1, HIGH); //Turn on the alert LED

  digitalWrite(led2, LOW);
  digitalWrite (led3, HIGH);   // turn the LED off by making the voltage LOW

  PressureChecker(pressureSensorPin);
  delay(500); 

  PressureChecker(pressureValue);

 }

void PressureChecker(int pressureValue){
  // Print pressure value to serial monitor
  Serial.print("Pressure: ");
  Serial.println(pressureValue);

  if (pressureValue > 60) {
  Serial.print("TOO MUCH"); //Alert the person
  }
   
  else if(pressureValue <= 15){
    digitalWrite(led1, HIGH); //Alert the person
  }

  //If the pressure is within the pressure range
  else {
    digitalWrite(led1, LOW); //Turn off the alert LED
    Serial.print("The pressure is within the range"); //Tell us its in the range
  }
  
 }
  