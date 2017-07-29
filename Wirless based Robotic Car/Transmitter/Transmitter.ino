 #include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorvalue;
#include <VirtualWire.h>
char *controller;

// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  // Print a message to the LCD.
  lcd.print("SENSOR VALUE");
  vw_set_ptt_inverted(true); //
vw_set_tx_pin(7);
vw_setup(4000);// speed of data transfer Kbps
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int x= analogRead(A0);
   int y = analogRead(A1);
    int z = analogRead(A2);
  lcd.clear();
   lcd.setCursor(0,0);
  // print out the value you read:
  Serial.println(x);
      lcd.print("X:");
      lcd.setCursor(3,0);
  lcd.print(x);
  
    lcd.setCursor(8,0);
   lcd.print("Y:");
      lcd.print(y);
    Serial.println(y);
    
  lcd.setCursor(0,1);
   lcd.print("Z:");
      lcd.print(z);
      
    Serial.println(z);
   delay(100);        // delay in between reads for stability
  if(x<350 && y>380) //Forward
  {
 controller="1";
 vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
digitalWrite(13,HIGH);
}
else if(x<330 && y<300) // Backward
{
  controller="2";
 vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
digitalWrite(13,HIGH);
}
  
else if(x<300 && y<350) // Left
{
   controller="3";
 vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
digitalWrite(13,HIGH);
}
else if(x>380 && y<350) // right
{  
 controller="4";
 vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx(); 
digitalWrite(13,HIGH);
}
else if(z>400) // stop
{
  controller="5";
 vw_send((uint8_t *)controller, strlen(controller));
vw_wait_tx();
digitalWrite(13,HIGH);
}
}


