#include <VirtualWire.h>
#include <VirtualWire_Config.h>

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
int xaxis=A0;
int yaxis=A1;
int value=0;
int value1=0;
///int 12;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  vw_set_ptt_inverted(true); // Required for DR3100
vw_set_rx_pin(12);
vw_setup(4000); // Bits per sec
vw_rx_start(); // Start the receiver PLL running
 //Serial.begin(9600);
}
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;  
 if (vw_get_message(buf, &buflen)) // Non-blocking
{
  if(buf[0]=='1')
  {
 digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  //analogWrite(enA,256);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
   
  analogWrite(enB,255);
  //Serial.println("left side");
  }
  else if(buf[0]=='2')
{
   
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enA,255);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
  analogWrite(enB,255);
 // Serial.println("right side");
}
else if(buf[0]=='3')
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enA,255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  analogWrite(enB,255); 
  //Serial.println("forward");
}
else if(buf[0]=='4')
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  analogWrite(enA,255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  analogWrite(enB,255);
  
  //Serial.println("backward");
}
else if(buf[0]=='5')
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  //analogWrite(enA,255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
  //analogWrite(enB,255);
  
  //Serial.println("stable");
}
}
}
