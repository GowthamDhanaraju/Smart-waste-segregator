#include <Servo.h>
int value=A0;
int s2_pin=9;
int s1_pin=8;
int touch=6;
int led_w=12;
int led_d=11;
const int trigPin_1 = 2;
const int echoPin_1= 3;
long duration_1;
int distance_1;
Servo s1;
Servo s2;
void setup() {
    pinMode(value, INPUT);
    pinMode(touch,INPUT);
    pinMode(led_w,OUTPUT);
    pinMode(led_d,OUTPUT);
    Serial.begin(9600);
    s1.attach(s1_pin);
    s2.attach(s2_pin);
    pinMode(trigPin_1, OUTPUT);
    pinMode(echoPin_1, INPUT); 
}

void loop() {
  digitalWrite(led_d,LOW);
  digitalWrite(led_w,LOW);
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration_1 = pulseIn(echoPin_1, HIGH);
  // Calculating the distance
  distance_1= duration_1 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance_1);
  s1.write(90);
  s2.write(90);
  value=analogRead(A0);
  int v_m=digitalRead(touch);
  if (value>900 && v_m==HIGH)
    {
      s1.write(30);
      s2.write(150);
      Serial.print("DRY WASTE = ");
      Serial.print(value);
      Serial.print("\n");
    }
  else if (value<900 && v_m==HIGH)
    {
      s1.write(150);
      s2.write(30);
      Serial.print("wet WASTE = ");
      Serial.print(value);
      Serial.print("\n");
    }
    else
    {
      s1.write(90);
      s2.write(90);
      Serial.print("No waste placed\n");
    }
    if (distance_1>15 && distance_1<30 && v_m!=HIGH)
    {
      digitalWrite(led_d,HIGH);
    }
    else if (distance_1<15 && v_m!=HIGH)
    {
      digitalWrite(led_w,HIGH);
    }
    else
    {
      digitalWrite(led_w,LOW);
      digitalWrite(led_d,LOW);
    }
  delay(700);
}
