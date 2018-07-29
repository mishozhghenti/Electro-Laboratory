#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int GAS_DO = 7; 
int STATE = 0;
bool changed = false;

int servoPin = 8;
Servo Servo1;

int trigPin = 9;    //Trig - green Jumper
int echoPin = 10;    //Echo - yellow Jumper
long duration, cm, inches;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();
  pinMode(GAS_DO, INPUT);  
  Servo1.attach(servoPin);
  Servo1.write(0);

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  STATE = digitalRead(GAS_DO);
  lcd.setCursor(0,0);
  if (STATE != HIGH) {  
    lcd.print("CO2: HIGH ");
//    changed = true;
    if(!changed) {
      changed = true;
      for (int pos = 0; pos <= 170; pos += 1) {
        Servo1.write(pos);
        delay(5);
      }
    }
  } else {
    lcd.print("CO2: NORMAL ");
    if(changed) {
      changed = false;
      for (int pos = 170; pos >=0; pos -= 1) {
        Servo1.write(pos);
        delay(5);
      }
    }
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  lcd.setCursor(0,1);
  lcd.print("DISTANCE: ");
  lcd.print(cm);
  delay(1000);
  lcd.clear();
}
