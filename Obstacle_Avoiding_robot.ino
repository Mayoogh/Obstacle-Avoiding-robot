/* 
 *  Obstacle_Avoiding_robot- Avishkar
 *  Coder - Mayoogh Girish
 *  Website - http://bit.do/Avishkar
 *  This is a autonomous robot whicch avoids obstacles found in path
 *  
 *  Add NewPing Library, Go to Sketch > Include Library > Manage Libraries . Search for NewPing and install it
 */

#include <NewPing.h>

#define TRIGGER_PIN  3   // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4   // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define RMA 8            // Right Motor terminal A
#define RMB 9            // Right Motor terminal B
#define LMA 10           // Left Motor terminal A
#define LMB 11           // Left Motor terminal B

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600);
}

void loop() {

  int distance = sonar.ping_cm();   //Store distance in cm

  if (distance >= 40)        //NO Obstacle
  {
    forward();
  }
  else if (distance < 40)   //Obstacle Found in 40cm, Stop - Move backward - Make right turn
  {
    stop();
    delay(350);
    backward();
    delay(350);
    right();
    delay(500);
  }
}

void forward() {
  Serial.println("");
  Serial.println("Moving forward");
  digitalWrite(RMA, HIGH);
  digitalWrite(RMB, LOW);
  digitalWrite(LMA, HIGH);
  digitalWrite(LMB, LOW);
}
void backward() {
  Serial.println("");
  Serial.println("Moving Backward");
  digitalWrite(RMA, LOW);
  digitalWrite(RMB, HIGH);
  digitalWrite(LMA, LOW);
  digitalWrite(LMB, HIGH);
}
void left() {
  Serial.println("");
  Serial.println("Making right turn");
  digitalWrite(RMA, HIGH);
  digitalWrite(RMB, LOW);
  digitalWrite(LMA, LOW);
  digitalWrite(LMB, HIGH);
}
void right() {
  Serial.println("");
  Serial.println("Making left turn");
  digitalWrite(RMA, LOW);
  digitalWrite(RMB, HIGH);
  digitalWrite(LMA, HIGH);
  digitalWrite(LMB, LOW);
}
void stop() {
  Serial.println("");
  Serial.println("Stop");
  digitalWrite(RMA, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMA, LOW);
  digitalWrite(LMB, LOW);
}
