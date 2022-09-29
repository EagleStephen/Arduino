/*
 ---------------------------------------------------------------------
 * Projet : Système de détection de pantograph
 * Composé de : DECA PETER - MILLET SEBASTIEN - NEOPANE MANJIL 
 * Classe : SESF 3 (18-21)
 * Nom du programme : Arduino_1_LCD_Ultrasonic_Pantograph
 * Composants cablé : Alimentation 5 V
 *                    Ecran LCD
 *                    HC-SR04 Ultrasonic
 *                    Relais 4 Channel avec alimentaion externe 5 V
 *                    Test Bench / Bread Board
 *                    Transofmateur avec potentionmètre 12.5 V
 ---------------------------------------------------------------------               
 
     Branchemnt LCD sur la carte Arduino 1
 -------------------------------------------
 * LCD RS pin sur digital pin 12
 * LCD Enable pin sur digital pin 11
 * LCD D4 pin sur digital pin 5
 * LCD D5 pin sur digital pin 4
 * LCD D6 pin sur digital pin 3
 * LCD D7 pin sur digital pin 2
 * LCD R/W pin sur ground
 * LCD VSS pin sur ground
 * LCD VzCC pin sur 5V
 
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
/* ----Utilisation des bibliothèques---*/
#include <LiquidCrystal.h>    // Librairie pour l'écran LCD
/* ----Configuration détecteur ultrasonic HC-SR04----*/
#define echoPin 26            // Pin Echo du capteur est branché comme sortie sur le pin Digital 26 
#define trigPin 28            // Pin Trig du capteur est branché comme sortie sur le pin Digital 28 
/* ----Configuration Relais----*/
#define relais 9              // Assignation relais sur la pin digital 9 
/* ----Déclaration des variables----*/
long duration;                // variable pour la durée d'un aller-retour d'une onde 
int distance;                 // variable pour mesurer la distance

/* ---Configuration des Infrarouges et les Leds pour le TCO----*/
int IR1  = 43;                // Assignation de variable IR sur pin Digital 43   
int IR2  = 45;                // Assignation de variable IR sur pin Digital 45         
int IR3  = 47;                // Assignation de variable IR sur pin Digital 47     
int IR4  = 49;                // Assignation de variable IR sur pin Digital 49      
int IR5  = 51;                // Assignation de variable IR sur pin Digital 51    

int Led1 = 38;                // Assignation de variable Led pour la zone 1 sur pin Digital 38 
int Led2 = 39;                // Assignation de variable Led pour la zone 2 sur pin Digital 39  
int Led3 = 40;                // Assignation de variable Led pour la zone 3 sur pin Digital 40  
int Led4 = 41;                // Assignation de variable Led pour la zone 4 sur pin Digital 41  

/* ----Initiation des flags pour les zones----*/
int zone_1 = 0;               // Flag pour mémoriser l'impulsion de détection sur l'infrarouge 1
int zone_2 = 0;               // Flag pour mémoriser l'impulsion de détection sur l'infrarouge 2
int zone_3 = 0;               // Flag pour mémoriser l'impulsion de détection sur l'infrarouge 3
int zone_4 = 0;               // Flag pour mémoriser l'impulsion de détection sur l'infrarouge 4


/* ----Initialisation de librairie avec les numéros de pin d'interface----*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Configuration des pins utilisé de LCD sur pin digital 12, 11 , 5, 4, 3 et 2
void setup() {
  
  /* ------------------------ Assignation des pins entrées-sorties ------------------------ */
  /* ---- Configuration pin détecteur ultrasonic ----*/
  pinMode(trigPin, OUTPUT);    // Assignation de trigPin en OUTPUT (sortie)
  pinMode(echoPin, INPUT);     // Assignation de echoPin en INPUT (entrée)

  /* ---- Configuration pin E/S pour les infrarouges et le TCO ---- */
 
  pinMode(Led1, OUTPUT);       // Configuration de la led 1 en sortie 
  pinMode(IR1, INPUT);         // Configuration de IR 1 en entrée
  
  pinMode(Led2, OUTPUT);
  pinMode(IR2, INPUT);
  
  pinMode(Led3, OUTPUT);
  pinMode(IR3, INPUT);
  
  pinMode(Led4, OUTPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  
  /* ---- Configuration relais en sortie ----*/
  pinMode(relais,OUTPUT);     // Configuration du relais en sortie <=> OUTPUT 

  /* ---- Fonction pour monitoriser ---- */
  Serial.begin(9600);          // Série de communication qui démarre avec 9600 vitesse de baudrate
 
  /* -------------- -- Message au démarrage du programme sur le montieur sérial -------------- */
  Serial.println("Bienvenue sur le test prototype : detection des pantographes"); 
  Serial.println("avec notre groupe");
  Serial.println("composé de");
  Serial.println("Monsieur DECA Peter");
  Serial.println("Monsieur MILLET Sebastien");
  Serial.println("et Monsieur NEOPANE Manjil");

  /* --------------------------------------- Message sur LCD ----------------------------------- */

  /* ---- Configuration de LCD : quantité de colonne et lignes ---- */ 
  lcd.begin(16, 2);                 // Notre LCD a pour un nombre max : 16 colonnes (blocs) et 2 lignes 
 
  /* -------------- Relais  High/Haut = Circuit ouvert et Relais  Low/Bas = Circuit fermé -------*/
   digitalWrite(relais,LOW); // Etat initiale de notre relais : circuit fermé  et brachement en NO ( Normally OPEN ) 
  }
void loop() {

  /* ------------------------------- TCO -------------------------------------------*/ 
  // Etat intiale des leds : Mise hors tension des Leds lors de non présence du train
  // --------------------------------------------------------------------------------
     digitalWrite(Led1,LOW); // Led Zone 1 
     digitalWrite(Led2,LOW); // Led Zone 2 
     digitalWrite(Led3,LOW); // Led Zone 3
     digitalWrite(Led4,LOW); // Led Zone 4

  /* ----------------------- Occupation des zones ---------------------------------  
              Déclarations des zones et initialisation des zones 
     -----------------------------------------------------------------------------*/
  /* --------------------------------------------------------------------------------
                                       Zone 1
     ----------------------------------------------------------------------------- */
    int detection_IR_1 = digitalRead(IR1);    // Lecture de la valeur de Infrarouge 1 
       if (detection_IR_1 == LOW)             // S'il y a une détection sur le IR alors on assigne zone 1 par la valeur 1
        {           
          zone_1 = 1;                         // Flag qui permet d'mémorier l'impulsion de détection sur l'infrarouge 1 
        }
       if (zone_1 ==1)                        // Si le flag de la zone 1 vaut 1 la led 1 reste allumée 
        { 
          digitalWrite(Led1,HIGH);            // Allumage de la led 1 
        }
      if(zone_1 == 0)                         // Si le flag de la zone 1 vaut 0 la led 1 s'éteint
        {
          digitalWrite(Led1,LOW);             // Extinction de la led 1
        }
   /* --------------------------------------------------------------------------------
                                       Zone 2
   ----------------------------------------------------------------------------- */
  
    int detection_IR_2 = digitalRead(IR2);   // Lecture de la valeur de Infrarouge 2 
        if (detection_IR_2 == LOW)             // S'il y a une détection sur IR alors on assigne zone 2 par la valeur 1
        {
         zone_1 = 0;                         // Le flag de zone 1 passe à 0                  
         zone_2 = 1;                         // Ce flag permet d'mémorier l'impulsion de détection sur l'infrarouge 2 
        }
         if (zone_2 == 1)
           { 
            digitalWrite(Led2,HIGH);        // Allumage de la led 2 
           }
       if(zone_2 == 0)                      // Si le flag de la zone 2 vaut 0 la led 2 s'éteint
        {
          digitalWrite(Led2, LOW);          // Extinction de la led 2
        }       
   /* --------------------------------------------------------------------------------
                                       Zone 3
     ----------------------------------------------------------------------------- */
    int detection_IR_3 = digitalRead(IR3);                // Lecture de la valeur de IR3
    if (detection_IR_3 == LOW) 
      {
       zone_2 = 0;
       zone_3 = 1;
    }
    if (zone_3 ==1)
         { 
          digitalWrite(Led3,HIGH);
         }
    if (zone_3 ==0)
         { 
          digitalWrite(Led3,LOW);
         }
  /* --------------------------------------------------------------------------------
                                       Zone 4
     ----------------------------------------------------------------------------- */
     int detection_IR_4 = digitalRead(IR4);                // Lecture de la valeur de IR4
     if (detection_IR_4 == LOW) 
      {
         zone_3 = 0;
         zone_4 = 1;
      }
        if (zone_4 ==1)
           { 
            digitalWrite(Led4,HIGH);
           }
 /* --------------------------------------------------------------------------------
                                       Zone 5
     ----------------------------------------------------------------------------- */
   int detection_IR_5 = digitalRead(IR5);                // Lecture de la valeur de IR5
   
   if (detection_IR_5 == LOW)                       
     {
      zone_4 = 0;                                      // On utilise cet dernier IR pour mettre le flag 4 à 0 et éteindre la led sur le voyant du TCO
     }
   if (zone_4 == 0)
      {
        digitalWrite(Led4, LOW);                        // Extinction de la led 4 
            /* En axe d'amélioration si on ne veut pas que le train sort de la table(erreur humaine on coupe son alimentation 
               digitalWrite(relais,LOW);                                                                                    */
      }
    
  /*----- Procesus de mesurer la distance à l'aide du détecteur ultrasonic ----*/
   
  // Vidage de condition de trigPin 
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2);
  
  // Activation de tigPin pendant 10 microseconds 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lecture sur echoPin et retourner de temps en microseconde d'arrivé de l'onde sur la varialble duration
  duration = pulseIn(echoPin, HIGH);
  
  // Calcul de distance à l'aide de la formule de la vitesse de propagation d'une onde sonore dans l'aire et la distance v=d/t donc d= v*t 
  distance = duration * 0.034 / 2;   // vitesse d'une onde sonore divisé par 2 car on a un allé et un retour 
  
  // Affichange de la distance sur le moniteur en série - Displays the distance on the Serial Monitor
  Serial.println("Distance:");
  Serial.println(distance);
     
  //Serial.read(duration); - Lecture distance 

  /*----- Procesus d'arret de cirulation si pantograph en position haute et affichage d'un message sur l'écran LCD ----*/
  
  if (distance <= 10) {                 // Si la distance est inférieure ou égale à 10cm
    lcd.clear();
    lcd.print("Pantograph:haut");       // Affichage du message "Pantographe Haut" sur l'écran LCD
    lcd.setCursor(0, 1);            
    lcd.print("Train en arret");
    digitalWrite(relais,HIGH);          // Relais Haut = Circuit ouvert 
  }else if (distance > 10){             // Sinon si la distance est supérieure à 10cm 
    lcd.clear();
    lcd.print("Pantograph:bas");        // Affichage du message "Pantographe Bas" sur l'ecran LCD
    digitalWrite(relais,LOW);           //Relais bas = Circuit fermé
    lcd.clear();
  }

    Serial.print(" cm");                // ajout de "cm" à la fin de la valeur de distance sans unité
  }
