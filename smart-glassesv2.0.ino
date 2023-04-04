#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8); //SIM800L Rx & Tx is connected to Arduino #7 & #8

const int trigPin = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 5; // Echo Pin of Ultrasonic Sensor
const int buzzerpin = 4;
const int buttonpin1=2;
const int buttonpin2=3;


void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   mySerial.begin(9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(buzzerpin, OUTPUT);
   pinMode(buttonpin1, INPUT);
   pinMode(buttonpin2, INPUT);
   pinMode(buttonpin1, HIGH);
   pinMode(buttonpin2, HIGH);
}

void loop() {
   bool buttonstate1 = digitalRead(buttonpin1);
   if(buttonstate1 == HIGH)
    { 
      Serial.println("calling...");
     mySerial.println("AT");
     delay(500);
     mySerial.println("ATD+ +9647706957659;");
      }
    
   bool buttonstate2 = digitalRead(buttonpin2);
   if(buttonstate2 == HIGH)
     mySerial.println("ATH");

   long duration, cm;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   cm = duration / 29 / 2;
   Serial.print(cm);
   Serial.println(" cm");
   if(cm <= 80)
   { 
    digitalWrite(buzzerpin,HIGH);
    Serial.println("high");
    }
   else
    {
      digitalWrite(buzzerpin,LOW);;
      Serial.println("low");
    }
    delay(100);
}
