#include <SPI.h>

int slaveSelect = 10;
bool flag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(slaveSelect, OUTPUT);
  SPI.begin();

  digitalWrite(slaveSelect, LOW);       // enable Slave
    
 // SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  // put your main code here, to run repeatedly:
  
//  digitalWrite(slaveSelect, LOW);       // enable Slave
  if(flag == false)
  {
    SPI.transfer('5');
    Serial.print("5 is sent\n");
    
    flag = true;
  }
  else if(flag == true)
  {
    SPI.transfer('6');
    Serial.print("6 is sent\n");
    
    flag = false;  
  }
//  digitalWrite(slaveSelect, HIGH);      // disable Slave
}
