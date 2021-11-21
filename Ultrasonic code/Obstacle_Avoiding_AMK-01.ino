// www.roboindia.com //

//Buy Arduino Multipurposae Kit : https://amzn.to/2IRQtae   //
//Technical Enquiry: support@roboindia.com  //


#include <HCSR04.h>
#include <Servo.h>

// Define Motor Pin
const int Motor_L_F = 2;
const int Motor_L_B = 3;
const int Motor_R_F = 4;
const int Motor_R_B = 5;

// Define Ultrasonic Sensor Pin
#define Echo  7
#define Trig  8

// Variable to store distance
int Front_D = 0;
int Left_D = 0;
int Right_D = 0;

int Max_D = 50;  // Max distance to obastacle 


UltraSonicDistanceSensor distanceSensor(Trig, Echo);  // Initialize sensor

Servo Servo_1;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 

  
  // Define Motor Pin as output
  pinMode(Motor_L_F, OUTPUT);
  pinMode(Motor_L_B, OUTPUT);
  pinMode(Motor_R_F, OUTPUT);
  pinMode(Motor_R_B, OUTPUT);

  Servo_1.attach(9);  // attaches the servo on pin 9 to the servo object
  int pos = 90;
  Servo_1.write(pos);
  delay(1000);

  
}

void loop() {
    // put your main code here, to run repeatedly:
   Front_D = distanceSensor.measureDistanceCm(); // measuring fornt distance  
   if (Front_D < Max_D)
   {
     Stop();
     Get_D();     
     if(Right_D > Max_D)
     {
       Right();
       delay(400);
       Forward();
     }
     else if ( Left_D > Max_D)
     {
       Left();
       delay(400);
       Forward();     
     }     
     else  {           
       Back();
       delay (500);
       Stop();      
      }
   }
   else{   
    Forward();   
   } 
}


void Forward(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Right(){
  //Stop Right Motor
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);

  //Run Left Motor in Forward Direction
  digitalWrite(Motor_L_F, HIGH);
  digitalWrite(Motor_L_B, LOW);
  
  }

void Left(){
  //Stop Left Motor
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, HIGH);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Back(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, HIGH);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, HIGH);
  
  }

void Stop(){
  // Run Left Motor In Forward Direction
  digitalWrite(Motor_L_F, LOW);
  digitalWrite(Motor_L_B, LOW);

  //Run Right Motor in Forward Direction
  digitalWrite(Motor_R_F, LOW);
  digitalWrite(Motor_R_B, LOW);
  
  }

void Get_D(){
    Servo_1.write(0);   // Right Position 
    delay(500);
    Right_D = distanceSensor.measureDistanceCm();     
    Servo_1.write(90);  // Front Positon 
    delay(500);
    Front_D = distanceSensor.measureDistanceCm();     
    Servo_1.write(180); // Left position of servo
    delay(500);
    Left_D = distanceSensor.measureDistanceCm();  
    Servo_1.write(90);  // back to front
    delay(250);
  }
