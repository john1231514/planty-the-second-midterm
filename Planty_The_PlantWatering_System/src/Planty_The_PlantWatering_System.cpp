/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

int Last500MillisSec;
int currentTime;
int moisture;
const int air = 5248;
const int water = 1760;
const int moistSoil = 3370;
const int drySoil = 3520;


// Run the application and system concurrently in separate threads
//SYSTEM_THREAD(ENABLED);

// setup() runs once, when the device is first turned on
void setup() {
Serial.begin();
waitFor(Serial.isConnected,10000);
Serial.println("Ready To Go");
pinMode(A5,INPUT);
pinMode(S4,OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  moisture=analogRead(A5);
    Serial.printf("moisture sensor %i\n", moisture);

  if((currentTime -Last500MillisSec)>500) {
    Last500MillisSec = millis();
   digitalWrite(S4,LOW);
  }
  else{digitalWrite(S4,HIGH);}


  }


