/* 
 *  Obstacle_Avoiding_robot- Avishkar
 *  Coder - Mayoogh Girish
 *  Website - http://bit.do/Avishkar
 *  This is a autonomous robot whicch avoids obstacles found in path
 */

int trig2=11,echo2=10 ;
int LMA=2,LMB=3,RMA=4,RMB=5;
int pos = 90; 
float distance, duration  ;
 
void setup() 
{ 
  pinMode(LMA,OUTPUT);
  pinMode(LMB,OUTPUT);
  pinMode(RMA,OUTPUT);
  pinMode(RMB,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(trig2,LOW);   
  delay(2);
  digitalWrite(trig2,HIGH);
  delay(10);
  digitalWrite(trig2,LOW);
  duration = pulseIn(echo2,HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println();
  delay(100);
  

  if(distance>25)           //NO Obstacle
  {
    Serial.println("");
    Serial.println("Moving forward");
    digitalWrite(RMA,HIGH);
    digitalWrite(RMB,LOW);  //forward
    digitalWrite(LMA,HIGH);
    digitalWrite(LMB,LOW);
  }
  else if(distance<40)      //Obstacle Found in 40cm
  { 

    Serial.println("");
    Serial.println("Obstacle ");
    digitalWrite(LED,LOW);
    digitalWrite(RMA,HIGH);
    digitalWrite(RMB,HIGH);  //stop
    digitalWrite(LMA,HIGH);
    digitalWrite(LMB,HIGH);
    delay(350);
    
    Serial.println("");
    Serial.println("Moving back");
    digitalWrite(RMA,LOW);
    digitalWrite(RMB,HIGH);   //take back
    digitalWrite(LMA,LOW);
    digitalWrite(LMB,HIGH);
    delay(350);  

    Serial.println("");
    Serial.println("Making right turn");
    digitalWrite(RMA,LOW);
    digitalWrite(RMB,HIGH);   //right turn
    digitalWrite(LMA,HIGH);
    digitalWrite(LMB,LOW);
    delay(500);
 }
}
