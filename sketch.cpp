// C++ code
// This is Alarm Clock 1
// Start by turning the potentiometer to a desired value
// Then click the button and a timer based on the potentiometer will display in minutes
// The servo motor will turn 180 degrees and the buzzer will play 5 times at the end
// You will then be input another value for the potentiometer


// I am accessing the libary for the servo motor
#include <Servo.h>
// Defining notes for the buzzer
#define NOTE_C4  262

// Creating a servo object
Servo myservo ;
// Declaring a pin for the push button.

// Declaring the pins for the potentiometer, the led and the 7 Segment display
int potPin = A0 ;
int led = 12 ;
int a = 2 ;
int b = 3 ;
int c = 4 ;
int d = 5 ;
int e = 6 ;
int f = 7;
int g = 8 ;
// Declaring a variable for the timer. This starts at 30 because turning the led on and off would take 2 seconds in total
int timer = 30 ;
// Declaring a pin for the push button.
int buttonPin = 13;
// buttonState represents the button being pressed or not
int buttonState ;
// Pin for buzzer
int buzzer = 10 ;


// Detup function. Here, I am declaring the different components as inputs or outputs. I am also attaching the servo to  a pin.
void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  myservo.attach(9);
  pinMode(led,OUTPUT);
  pinMode(potPin,INPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT) ;
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(buttonPin,OUTPUT);
  pinMode(buzzer,OUTPUT);


}
// The clear all function turns of all the LED's on the 7 segment display
void clearAll()
{
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(g,LOW);
    digitalWrite(f,LOW);
}
// The main loop function.
void loop()
{
    // By turning the servo 20 degrees initially, I am preventing it from twitching uncontrollably
    myservo.write(20);
    clearAll();


    // Checking to see if button is clicked. If it is, the timer will start.
    buttonState = digitalRead(buttonPin);

  while (buttonState == 1)
  {

    buttonState = digitalRead(buttonPin);
    // These 2 lines are seeing the value from the potentiometer
    int userInput1 = analogRead(potPin);
    int userInput= map(userInput1,0,1023,0,5);
    // The conditional statements check whcih number should be displayed on the 7 segment and display it.
    if (userInput== 1)
    {
      clearAll();
      digitalOne();
      timer = 30 * 1 ;
      clearAll();
    }
    else if (userInput== 2)
    {
      clearAll();
      timer = 30 * 2 ;
      digitalTwo();
      clearAll();
    }
    else if (userInput== 3)
    {
      clearAll();
      timer = 30 * 3 ;
      digitalThree();
      clearAll();
    }
    else if (userInput== 4)
    {
      clearAll();
      digitalFour();
      timer = 30 * 4 ;
      clearAll();
    }
    else if (userInput== 5)
    {
       clearAll();
       digitalFive();
      timer = 30 * 5 ;
       clearAll();
     }
     else if (userInput== 0)
     {
       clearAll();
       digitalZero();
       timer = 30 * 0 ;
       clearAll();
     }
  }



    delay(1000);

    // For loop, which represents the LED turning on and off based on the time display on the 7 segment display
    for (int i = 0; i < timer; i ++)
    {
      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
      delay(1000);
    }


    digitalWrite(led,HIGH);
   delay(1000);
    // Moving servo 180 degrees, then waiting 3 seconds, then moving back
    myservo.write(180);
    delay(3000);
    myservo.write(20);
    delay(1000);
    // Playing buzzer 5 times
    for (int i = 0; i < 5; i ++)
    {
      tone (buzzer, NOTE_C4, 250);
      delay (1000);
    }
    delay(1000);
    // Turning off LED
    digitalWrite(led,LOW);

}
// Function to display # 1
void digitalOne()
{
    clearAll();
    digitalWrite (b, HIGH);
    digitalWrite (c, HIGH);
}
//  Function to display # 2
void digitalTwo()
{
    clearAll();
    digitalWrite (a, HIGH);
    digitalWrite (b, HIGH);
    digitalWrite (d, HIGH);
    digitalWrite (e, HIGH);
    digitalWrite (g, HIGH);

}
//  Function to display # 3
void digitalThree()
{
    clearAll();
    digitalWrite (a, HIGH);
    digitalWrite (b, HIGH);
    digitalWrite (c, HIGH);
    digitalWrite (d, HIGH);
    digitalWrite (g, HIGH);
}
//  Function to display # 4
void digitalFour()
{
    clearAll();
    digitalWrite (b, HIGH);
    digitalWrite (c, HIGH);
    digitalWrite (f, HIGH);
    digitalWrite (g, HIGH);
}
//  Function to display # 5

void digitalFive()
{
    clearAll();
    digitalWrite (a, HIGH);
    digitalWrite (c, HIGH);
    digitalWrite (d, HIGH);
    digitalWrite (f, HIGH);
    digitalWrite (g, HIGH);
}
//  Function to display # 0

void digitalZero()
{
  clearAll();
    digitalWrite (a, HIGH);
    digitalWrite (b, HIGH);
    digitalWrite (c, HIGH);
    digitalWrite (d, HIGH);
    digitalWrite (e, HIGH);
    digitalWrite (f, HIGH);
}




