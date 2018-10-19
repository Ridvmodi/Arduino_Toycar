#include <LiquidCrystal.h>
#include <VirtualWire.h>
#include <VirtualWire_Config.h>
LiquidCrystal lcd(11,10,5,4,3,2);
int xaxis=A0;
int yaxis=A1;
int value=0;
int value1=0;
char *controller;
void setup() 
{ 
  pinMode(xaxis,INPUT);
  pinMode(yaxis,INPUT);
  lcd.begin(16,2);
  lcd.print("a b c d e f g h");
  delay(3000);
  lcd.clear();
  lcd.print("i j k l m n o p");
  delay(3000);
  lcd.clear();
  lcd.print("q r s t u v w x");
  delay(3000);
  lcd.clear();
  lcd.print("y z");
  delay(2000);
  vw_set_ptt_inverted(true); 
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
 // pinMode(13,OUTPUT);
 // vw_rx_start();
  //Serial.begin(9600);
  
}

void loop() {
  lcd.setCursor(0,1);
  value=analogRead(xaxis);
  value1=analogRead(yaxis);
if(value<=400)
{
  //Serial.println("left side");
  controller="1" ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  //digitalWrite(13,1);
  //delay(2000);
 }
else if(value>=600)
{
  //Serial.println("right side");
    controller="2" ;
  vw_send((uint8_t *)controller, strlen(controller));
  
  vw_wait_tx(); // Wait until the whole message is gone
  //digitalWrite(13,1);
 // delay(2000);
}
if(value1<=400)
{
  //Serial.println("forward");
    controller="3" ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  //digitalWrite(13,1);
  //delay(2000);
}
else if(value1>=600)
{
  //Serial.println("backward");
    controller="4" ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx();
  
  // Wait until the whole message is gone
  //digitalWrite(13,1);
  //delay(2000);
}
else
{
  //Serial.println("stable");
    controller="5" ;
  vw_send((uint8_t *)controller, strlen(controller));
  
  vw_wait_tx(); // Wait until the whole message is gone
  //digitalWrite(13,1);
 // delay(2000);
}
}
