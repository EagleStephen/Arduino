/*
 The circuit: Branchemnt LCD 
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
 
#define echoPin 26 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 28 //attach pin D3 Arduino to pin Trig of HC-SR04
#define relais 9 // Digital output 9 on Arduino 
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");

   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("Pantograph:haut");


  //Information Relais

  pinMode(relais,OUTPUT);
  digitalWrite(relais,LOW); // Relais  High/ haut = Circuit ouvert
  
}

void loop() {

    
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  
 // Serial.read(distance);
  
  if (distance <= 10) {
    lcd.clear();
    lcd.print("Pantograph:haut");
    lcd.setCursor(0, 1);
    lcd.println("Train en arret");
    digitalWrite(relais,HIGH); // Relais Haut = Circuit ouvert
  }else if (distance > 10){
    lcd.clear();
    lcd.print("PasdePantograph");
    digitalWrite(relais,LOW);
    lcd.clear();
    digitalWrite(9,LOW);
  }

  
  
    Serial.print(" cm");
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);


  //Relais Low = Relais bas --> Circuit fermé
 
  
  
