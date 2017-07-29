#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
char c[8]="",d[8]="";
int i=0,j=0;
String msg;
String Person1="16305538";
String Person2="19012423";
String Person3="xxxxxxxx"

void setup()  
{
  Serial.begin(9600);
  pinMode(7,INPUT_PULLUP);

  Serial.println("SECURITY SYSTEMS");
  finger.begin(57600);
  if (finger.verifyPassword()) 
  {
    Serial.println("Found fingerprint sensor!");
    Serial.println("PLACE UR ID-CARD :)\n ");
  } else {
    Serial.println("Sorry no fingerprint sensor :(");
  }
  
}
void loop()
{
  while(Serial.available()>0)
  {
    c[i]=Serial.read();
    i++;
    if(i==10)
    {
      for(j=0;j<8;j++)
      {
        d[j]=c[j];
        msg+=d[j];
      }
      Serial.print("RFID:");Serial.println(msg);
      if(msg==Person1)
      {
        while(getFingerprintIDez1()==-1)
        {
        }
        Serial.println("ACCESS GRANTED\n");
        digitalWrite(13,HIGH);
        while(1)
        {
          int sw=digitalRead(7);
          if(sw==LOW)
          {
            digitalWrite(13,LOW);
            goto exit1;
          }
          
        }
      }
      else if(msg==Person2)
      {
        while(getFingerprintIDez2()==-1)
        {
        }
        Serial.println("ACCESS GRANTED\n");
        digitalWrite(13,HIGH);
        while(1)
        {
          int sw=digitalRead(7);
          if(sw==LOW)
          {
            digitalWrite(13,LOW);
            goto exit1;
          }
        }
      }
      else if(msg==Person3)
      {
        while(getFingerprintIDez3()==-1)
        {
        }
        Serial.println("ACCESS GRANTED\n");
        digitalWrite(13,HIGH);
        while(1)
        {
          int sw=digitalRead(7);
          if(sw==LOW)
          {
            digitalWrite(13,LOW);
            goto exit1;
          }
        }
      }
    exit1:
    i=0;
    msg="";
    Serial.print("PLACE UR ID :) \n");
    }
  }
}
int getFingerprintIDez1() 
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;
  
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK || finger.fingerID != 38)  
      { 
        Serial.println("UNAUTHORIZED PERSON");
        return -1;
      }
  Serial.print("PERSON-1:ID.NO="); Serial.println(finger.fingerID); 
  return finger.fingerID; 
}
int getFingerprintIDez2()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK || finger.fingerID != 23)  
      { 
        Serial.println("UNAUTHORIZED PERSON");
        return -1;
      }
  
  Serial.print("PERSON-2:ID.NO="); Serial.println(finger.fingerID); 
  return finger.fingerID; 
}
int getFingerprintIDez3()
{
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK || finger.fingerID != xx)  
      { 
        Serial.println("UNAUTHORIZED PERSON");
        return -1;
      }
  
  Serial.print("PERSON-3:ID.NO="); Serial.println(finger.fingerID); 
  return finger.fingerID; 
}
