#include<LiquidCrystal.h>
#define triPin 7
#define echoPin 6
int led1=13;
int led2=12;
LiquidCrystal lcd(11,10,5,4,3,2);
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("ultrasonic dist.");
  pinMode(triPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop()
{
  int distance, duration;
  digitalWrite(triPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(triPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration/58;
  Serial.print(distance);
  Serial.println("cm");
  lcd.print(distance);
  lcd.print("CM");
  lcd.setCursor(0,3);
  delay(50);
  lcd.clear();
  
  if((distance) > 15){
  
     digitalWrite(led1,HIGH);
  
     digitalWrite(led2,HIGH);
     
  }
  else if(distance < 15)
  {
    digitalWrite(led1,LOW);
  }
  
}
     
  
  
