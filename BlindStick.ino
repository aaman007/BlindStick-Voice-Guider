#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"
#include <Servo.h>
 
TMRpcm tmrpcm;
Servo myservo;
 
int trigPin = 7;
int echoPin = 8;
int trigPin2 = 5;
int echoPin2 = 6;
long duration;
long distance;
int motor = 3;
int buzzer = 2;
 
void setup(){
    myservo.attach(motor);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);
    pinMode(buzzer,OUTPUT);
    Serial.begin(9600);
 
}
void rotatePlay()
{
  digitalWrite(buzzer,HIGH);
  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {
   Serial.println("SD fail");
   return;
   }
  tmrpcm.setVolume(3);
  Serial.println("Rotate Sound Playing");
  tmrpcm.play("rotate.wav");
  delay(5000);
  tmrpcm.stopPlayback();
  digitalWrite(buzzer,LOW);
}
void forwardPlay()
{
  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {
   Serial.println("SD fail");
   return;
   }
  tmrpcm.setVolume(3);
  Serial.println("Forward Sound Playing");
  tmrpcm.play("forward.wav");
  delay(5000);
  tmrpcm.stopPlayback();
}
long getDistanceUP()
{
     // Clears the trigPin
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin2, HIGH);
    
    // Calculating the distance
    distance= duration*0.034/2;
    
    // Prints the distance on the Serial Monitor
    Serial.print("Distance Up : ");
    Serial.println(distance);

    return distance;
}
long getDistanceDOWN()
{
     // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance= duration*0.034/2;
    
    // Prints the distance on the Serial Monitor
    Serial.print("Distance Down : ");
    Serial.println(distance);
    
    return distance;
}

void loop(){  
    bool flag = 0;
    for(int pos=0;pos<=60;pos+=20)
    {
      myservo.write(pos);
      long distUp = getDistanceUP();
      long distDown = getDistanceDOWN();
      
      if(distUp <= 45 || distDown <= 30)
      {
        flag = 1;
        break;
      }
    }
    if(!flag)
    {
      for(int pos=60;pos>=0;pos-=20)
      {
        myservo.write(pos);
        long distUp = getDistanceUP();
        long distDown = getDistanceDOWN();
        
        if(distUp <= 45 || distDown <= 30)
        {
          flag = 1;
          break;
        }
      }
    }
    
    if(flag)
      rotatePlay();
    else
      forwardPlay();
}
