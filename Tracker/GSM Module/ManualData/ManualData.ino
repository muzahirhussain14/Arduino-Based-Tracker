#include <SoftwareSerial.h>
SoftwareSerial myGsm(7,8);


void setup() {
  // put your setup code here, to run once:

  myGsm.begin(115200);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available())
  {
    myGsm.println(Serial.readString());  
  }

  while(myGsm.available())
  {
    Serial.println(myGsm.readString());  
  }
}
