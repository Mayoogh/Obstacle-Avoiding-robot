/* 
 *  Obstacle_Avoiding_robot- Avishkar
 *  Coder - Mayoogh Girish
 *  Website - http://bit.do/Avishkar
 *  This is a autonomous robot whicch avoids obstacles found in path
 */

int trig = 3, echo = 2;
int LMA=8,LMB=9,RMA=10,RMB=11;
int pos = 90; 
float distance, duration  ;
 
void setup() 
{ 
  pinMode(LMA,OUTPUT);
  pinMode(LMB,OUTPUT);
  pinMode(RMA,OUTPUT);
  pinMode(RMB,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(trig,LOW);   
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
//  Serial.print(distance);
//  Serial.println();
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
