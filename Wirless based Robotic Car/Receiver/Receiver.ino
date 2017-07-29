
#include <VirtualWire.h>
int L1=12,L0=11,R1=10,R0=9;
void setup()
{
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(2);
    vw_setup(4000);  // Bits per sec
    pinMode(L1,OUTPUT);
    pinMode(L0,OUTPUT);
    pinMode(R1,OUTPUT);
    pinMode(R0,OUTPUT);
    
    vw_rx_start();       // Start the receiver PLL running
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      if(buf[0]=='1')
      {
        digitalWrite(L1,HIGH);
        digitalWrite(L0,LOW);
        digitalWrite(R1,HIGH);
        digitalWrite(R0,LOW);
      }
      else if(buf[0]=='2')
      {
        digitalWrite(L1,LOW);
        digitalWrite(L0,HIGH);
        digitalWrite(R0,HIGH);
        digitalWrite(R1,LOW);
      }
      else if(buf[0]=='3')
      {
        digitalWrite(L1,LOW);
        digitalWrite(L0,LOW);
        digitalWrite(R0,HIGH);
        digitalWrite(R1,LOW);
      }
      else if(buf[0]=='4')
      {
        digitalWrite(L1,HIGH);
        digitalWrite(L0,LOW);
        digitalWrite(R0,LOW);
        digitalWrite(R1,LOW);
      }
      else if(buf[0]=='5')
      {
        digitalWrite(L1,LOW);
        digitalWrite(L0,LOW);
        digitalWrite(R0,LOW);
        digitalWrite(R1,LOW);
      }
    }
}
   
