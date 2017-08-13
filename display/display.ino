
#define trigPin 9
#define echoPin 10

long duration;
int distance, first, second, third;

int segA = 8;
int segB = 6;
int segC = 5;

int segD = 4;
int segE = 2;
int segF = 7;
int segG = 3;
int segPt = 0;
int d1 = 11;
int d2 = 13;
int d3 = 12;
int d4 = 0;

int count = 50;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(0,INPUT);

 


}

void loop() {

  
  
  while (count==50) {
     
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    
    distance = duration*0.034/2;
    int number = distance;
    first = number/100;
    second = number%100/10;
    third = number%10;
  
    Serial.print("Distance: ");
    Serial.println(distance);
  
    count=0;
  }
  count++;
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  sendDigit(first);
  digitalWrite(d1, LOW);
  delay(5);
  
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  sendDigit(second);
  digitalWrite(d2, LOW);
  delay(5);

  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  sendDigit(third);
  digitalWrite(d3, LOW);
  delay(5);
} 

void allLow() {

digitalWrite( segA, LOW); // A
digitalWrite( segB, LOW); // B
digitalWrite( segC, LOW); // C
digitalWrite( segD, LOW); // D
digitalWrite( segE, LOW); // E
digitalWrite( segF, LOW); // F
digitalWrite( segG, LOW); // G
digitalWrite(d1, LOW);
digitalWrite(d2, LOW);
digitalWrite(d3, LOW);


}

void allHigh() {

digitalWrite( segA, HIGH); // A
digitalWrite( segB, HIGH); // B
digitalWrite( segC, HIGH); // C
digitalWrite( segD, HIGH); // D
digitalWrite( segE, HIGH); // E
digitalWrite( segF, HIGH); // F
digitalWrite( segG, HIGH); // G
digitalWrite(d1, HIGH);
digitalWrite(d2, HIGH);
digitalWrite(d3, HIGH);


}

void one()
{
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);

}
void two()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, LOW);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void three()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void four()
{
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void five()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void six()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void seven()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);

}
void eight()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void nine()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void zero()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);

}

void cee()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, LOW);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);
}

void point()
{
digitalWrite(segPt, HIGH);
}

void selectDigit(int d)
{
/*
digitalWrite(d1,HIGH);

digitalWrite(d2,HIGH);
digitalWrite(d3,HIGH);
digitalWrite(d4,HIGH);
*/

  switch (d)
  {
    case 1:
      digitalWrite(d1, LOW);
      break;
    case 2:
      digitalWrite(d2, LOW);
      break;
    case 3:
      digitalWrite(d3, LOW);
      break;
    default:
      digitalWrite(d4, LOW);
      break;
  }
}

void sendDigit(int x)
{
switch(x)
{
case 1:
one();
break;
case 2:
two();
break;
case 3:
three();
break;
case 4:
four();
break;
case 5:
five();
break;
case 6:
six();
break;
case 7:
seven();
break;
case 8:
eight();
break;
case 9:
nine();
break;
case 10:
cee();
break;
default:
zero();
break;
}
}

int tens(float x)
{
float divided = x/10.0;
return (int)divided;
}

int ones(float x)
{
float divided = x - (10.0 * tens(x));
// Serial.print(divided);
// Serial.println(" ***ones***");
return (int)divided;
}

int points(float x)
{
float divided = x - (10.0 * tens(x)) - ones(x);
divided *= 10;
return (int)divided;
}
