/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
int ledgreen = 7;
int ledred = 5;
int ledyellow = 3;
void setup() {
  Serial.begin(9600);
  //green = 22;
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(4,INPUT);
  
}

// the loop function runs over and over again forever
void loop() {

  if(digitalRead(4)==LOW){
  digitalWrite(ledgreen,HIGH);
                          }
  else{
  digitalWrite(ledgreen,LOW);
      }

  //digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(150);                       // wait for a second
  
 // digitalWrite(ledgreen, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);                       // wait for a second

  //digitalWrite(ledred, HIGH);
  //delay(150);

  //digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);  

  //digitalWrite(ledyellow, HIGH);
  //delay(150);

  //digitalWrite(ledyellow, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);  
  
  
  
}
