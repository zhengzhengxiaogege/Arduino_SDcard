
#include <SimpleSDAudio.h>
#include <Wire.h>   
const int TrigPin = 2; 
const int EchoPin = 3; 
float cm; 
void setup()
{  
   SdPlay.setSDCSPin(10);
   pinMode(TrigPin, OUTPUT); 
   pinMode(EchoPin, INPUT); 
   pinMode(5,INPUT);
   pinMode(6,INPUT);
   pinMode(7,OUTPUT);
 }
void loop(void) {
   int a=0;
   digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin 
delayMicroseconds(2); 
digitalWrite(TrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(TrigPin, LOW); 

cm = pulseIn(EchoPin, HIGH) / 58.0; //将回波时间换算成cm 
cm = (int(cm * 100.0)) / 100.0; //保留两位小数  
delay(1000); 
   if(digitalRead(5)==HIGH)
    a=2;
    else
    {
      if(digitalRead(6)==HIGH)
      a=3;
    else
   {
    if(cm<20.0)
    a=5;
    else
    {
      a=0;
    }
   }
    }
  switch(a)
  {
    case 2:
    digitalWrite(7,HIGH);
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO);
    SdPlay.setFile("EF.AFM");
    SdPlay.play();
    while(!SdPlay.isStopped()) 
    {
      SdPlay.worker();
    }
    digitalWrite(7,LOW);
    break;

   case 3:
   digitalWrite(7,HIGH);
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO);
    SdPlay.setFile("CD.AFM");
    SdPlay.play();
    while(!SdPlay.isStopped()) 
    {
      SdPlay.worker();
    }
    digitalWrite(7,LOW);
    break;
   
    case 5:
    digitalWrite(7,HIGH);
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO);
    SdPlay.setFile("AB.AFM");
    SdPlay.play();
    while(!SdPlay.isStopped()) 
    {
      SdPlay.worker();
    }
    digitalWrite(7,LOW);
    break;
     
     case 0:
     break;
  }
}
   
   
 
