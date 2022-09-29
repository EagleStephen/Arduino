
 
 /*----------------------------------------           
    Branchemnt LCD sur la carte Arduino 
 -------------------------------------------
 * LCD RS pin sur digital pin 12
 * LCD Enable pin sur digital pin 11
 * LCD D4 pin sur digital pin 7
 * LCD D5 pin sur digital pin 8
 * LCD D6 pin sur digital pin 9
 * LCD D7 pin sur digital pin 10
 * LCD R/W pin sur ground
 * LCD VSS pin sur ground
 * LCD VzCC pin sur 5V
 * ends sur +5V and ground
 * wiper sur LCD VO pin 3
 */
 
/* ----Initialisation de librairie avec les numéros de pin d'interface----*/
  LiquidCrystal lcd(12, 11, 7, 8, 9, 10);  // Configuration des pins utilisé de LCD sur pin digital 12, 11 , 7, 8, 9 et 10 

/* ----Utilisation de bibliothèque pour le LCD---*/
  #include <LiquidCrystal.h> 

/* ----Assignation de variables ----*/
  #define led_rouge 6;     // Lorsqu'on fait appel à led_rouge le programme utilise le digital port 6
  #define led_vert 5;      // Lorsqu'on fait appel à led_rouge le programme utilise le digital port 5
    

void setup() {

  Serial.begin(9600);     // Baudrate pour le sérial moniteur
  
  /* ---- Configuration des entrées et sorties ---- */
  pinMode(led_rouge,OUTPUT);
  pinMode(led_vert,OUTPUT);

  /* ---- Initiation des variables ---- */
  int Rx = 0;             // Remise à zéro de notre entrée 
  
  /* ---- Configuration de LCD : quantité de colonne et lignes ---- */ 
  lcd.begin(16, 2);       // Notre LCD a pour un nombre max : 16 colonnes (blocs) et 2 lignes 

  /* ---- Etat Initiale de notre LCD ---- */
  lcd.clear();
  lcd.print("Projet Eporte");       // Affichage du message "Projet Eporte" sur l'écran LCD ligne 1
  lcd.setCursor(0, 1);              // Passage sur ligne 2 de l'écran LCD
  lcd.print("Classe 1erSTI2D");     // Affichage du message "Classe 1erSTI2D" sur l'écran LCD ligne 2
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:

}
