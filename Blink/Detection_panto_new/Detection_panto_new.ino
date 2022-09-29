
 // Définition du port du detecteur ultrasonic sur la carte 
#define echoPin 26 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 28 //attach pin D3 Arduino to pin Trig of HC-SR04

// Definition des variables pour le detecteur ultrasonic
long duration; // variable pour la durée du trajet aller-retour d'une onde
int distance; // variable pour mésurer la distance 

// Définiton du port du relais
#define relais 9 // Digital output 9 on Arduino 


// Librairie utilisé pour l'ecran LCD:
#include <LiquidCrystal.h>

// Initialisation de librairie avec les numéros de pin de l'interface 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/*
 BRANCHEMENT DE L'ECRAN :
 * LCD RS pin à digital pin 12
 * LCD Enable pin à digital pin 11
 * LCD D4 pin à digital pin 5
 * LCD D5 pin à digital pin 4
 * LCD D6 pin à digital pin 3
 * LCD D7 pin à digital pin 2
 * LCD R/W pin à ground
 * LCD VSS pin à ground
 * LCD VCC pin à 5V
 * 10K resistance:
 * ends à +5V et ground
 * wiper à LCD VO pin (pin 3)
 */

void setup() {
  
  
  pinMode(trigPin, OUTPUT); // Définir trigPin comme sortie
  pinMode(echoPin, INPUT);  // Définir echoPin comme entrée

  
  Serial.begin(9600); // Serial Communication commence à 9600 (vitesse d'affichage) 
  Serial.println("Test Ultrasonic Sensor"); // Test d'affichage sur le serial moniteur
  Serial.println("avec Arduino UNO R3");

  // Configuration de l'ecran LCD avec les nombres de colonnes et de lignes
  lcd.begin(16, 2);
  
  // Test d'affichage sur l'ecran (forcé)
  // lcd.print("Pantograph:haut");


  //Information Relais

  pinMode(relais,OUTPUT);   // Définir Relais comme une sortie 
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
 // if (distance <=5)
  
  
