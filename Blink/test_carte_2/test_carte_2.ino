void setup() {

  Serial.begin(9600);
  int IRO  = 13;
  int IR1  = 12;
  int IR2  = 11; // AC
  int IR3  = 10; // AC
  int IR4  = 9;  // AC
  int IR5  = 8;  
  
  
  int Led0 = 3; // AC
  int Led1 = 2;
  int Led2 = 4; 
  int Led3 = 5; // AC
  int Led4 = 6; // AC
  int Led5 = 7; 
  
  // Configuration des capteurs infrarouges comme entrée et LED comme sorties

    pinMode(Led0, OUTPUT);
    pinMode(IRO, INPUT); 

    pinMode(Led1, OUTPUT);
    pinMode(IR1, INPUT);

    pinMode(Led2, OUTPUT);
    pinMode(IR2, INPUT);
    
    pinMode(Led3, OUTPUT);
    pinMode(IR3, INPUT);

    pinMode(Led4, OUTPUT);
    pinMode(IR4, INPUT);

    pinMode(Led5, OUTPUT);
    pinMode(IR5, INPUT);
    

 }

void loop() {

 
  // Dectection des trains
  // ------------------------------------------------------------------------- 

  // Initialisation des LEDS sur le TCO
  // ----------------------------------
   
    int ledO;
  // Mise hors tension des Leds lors de non présence du train
  // ------------------------------------------------
     digitalWrite(3,LOW);
     digitalWrite(2,LOW);
     digitalWrite(4,LOW);
     digitalWrite(5,LOW);
     digitalWrite(6,LOW);
     digitalWrite(7,LOW);
      
  // --- Zone 0 --- 
    int detection0 = digitalRead(13);                // Lecture de la valeur de IR0
    
    if (detection0 == LOW) 
      {
        digitalWrite(3,HIGH);
      }


  // --- Zone 1 ---  
 
    int detection1 = digitalRead(12);                // Lecture de la valeur de IR1
  
    if (detection1 == LOW) 
      {
       digitalWrite(2,HIGH);
      }

  // --- Zone 2 --- 
    int detection2 = digitalRead(11);                // Lecture de la valeur de IR2
 
    if (detection2 == LOW) 
      {
       digitalWrite(4,HIGH);
    }

  // --- Zone 3 --- 
  int detection3 = digitalRead(10);                // Lecture de la valeur de IR3
  
  if (detection1 == LOW) 
    {
       digitalWrite(5,HIGH);
    }

  // --- Zone 4 --- 
  int detection4 = digitalRead(9);                // Lecture de la valeur de IR4
  
  if (detection4 == LOW) 
    {
       digitalWrite(6,HIGH);
    }
    
  // --- Zone 5 --- 
  int detection5 = digitalRead(8);                // Lecture de la valeur de IR4
  
  if (detection5 == LOW) 
    {
       digitalWrite(7,HIGH);
    }
    
    
}
