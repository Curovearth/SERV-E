
#include <Servo.h>

Servo myservo, ms2, ms3, ms4;


const int Pin = 9;
const int Pin1 = 10;
const int Pin2 = 11;
const int Pin3 = 3;
// 
char Text;

String Spilt;

String angle;

int pos = 0;    // variable to store the servo position

int k1;


void setup() {

Serial.begin(9600);

pinMode (Pin, OUTPUT);
pinMode (Pin1, OUTPUT);
pinMode (Pin2, OUTPUT);
pinMode (Pin3, OUTPUT); 


myservo.attach(Pin);
ms3.attach(Pin1);
ms3.attach(Pin2);
ms4.attach(Pin3);


}


void loop() {


  if(Serial.available())

  {

    Text = Serial.read();  

    Spilt = Spilt + Text; 


if (Text == '*') {

      Serial.println(Spilt);

      Spilt = Spilt.substring(0, Spilt.length() - 1); // Delete last char *

      k1 = Spilt.indexOf('*');

      angle = Spilt.substring(0, k1);

      myservo.write(angle.toInt());
      ms2.write(angle.toInt());
      ms3.write(angle.toInt());
      ms4.write(angle.toInt());

//      delay(15);  

  

      Spilt = "";   

  }

      }

 

} 
