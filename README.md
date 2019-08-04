# BlindStick-Voice-Navigator

### Project Description :
An arduino project for blind people using Arduino UNO board. It will guide a blind person by alerting when an obstacle is in front of him. Two sound commands are previously stored in MicroSD card. One of the sound is to command the blind person to "Rotate" when an obstacle is detected under 35/20 cm. The other sound file is the command to "Go forward" when no obstacle is detected under 35/20 cm.   
                
Two ultrasonic sensor detects higher objects and lower objects. Higher object range is 0-35 cm and lower object range is 0-20 cm.  The higher object detecting ulstrasonic sensor is always looking for objects inside 60 degree angle of front side. A servo motor is used to move the sensor.        
                
Additionally, a buzzer is used for alert when an object is detected.

### Components :
1. Arduino UNO
2. Breadboard
3. MicroSD Card Module [ Micro SD TF Card Module ]
4. Two Sonar Sensors [ HC-SR04 ]
5. Buzzer
6. Male to Male Jumper Wires
7. Male to Female Jumper Wires
8. Female to Female Jumper Wire
9. 9V Rechargeable Battery
10. 9V Battery Connector
11. MicroSD Card
12. Stick
13. Earphone

### Files:
Two .wav files (rotate.wav and forward.wav) on MicroSD card

### Interfacing :
First of all connect GND and +5V port of arduino with breadboard
#### Sonar Sensor (Higher Object detecting) and Arduino
1. GND with GND of Arduino
2. Echo with Digital Pin 6 of Arduino
3. Triger with Digital Pin 5 of Arduino
4. Vcc with +5V of Arduino
#### Sonar Sensor (Lower Object detecting) and Arduino
1. GND with GND of Arduino
2. Echo with Digital Pin 8 of Arduino
3. Triger with Digital Pin 7 of Arduino
4. Vcc with +5V of Arduino
#### MicroSD Card Module and Arduino
1. GND with GND of Arduino
2. Vcc with +5V of Arduino
3. MISO with Digitl Pin 12 of Arduino
4. MOSI with Digitl Pin 11 of Arduino
5. SCK with Digitl Pin 13 of Arduino
6. CS with Digitl Pin 10 of Arduino
#### Earphone/Speaker and Arduino
1. GND with GND of Arduino
2. Left/Right Speaker Pin with Digital Pin 9 of Arduino
#### Servo Motor and Arduino
1. RED (+5V) with +5V of Arduino
2. BROWN (GND) with GND of Arduino
3. ORANGE (PWM) with Digital Pin 3 of Arduino
#### Buzzer and Arduino
1. GND/Negative with GND of Arduino
2. Positive with Digital Pin 2 of Arduino
