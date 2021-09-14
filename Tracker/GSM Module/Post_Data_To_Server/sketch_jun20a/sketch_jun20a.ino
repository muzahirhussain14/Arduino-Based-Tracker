#include <SoftwareSerial.h>
SoftwareSerial myGsm(7,8);

void setup() {
  myGsm.begin(115200);
  Serial.begin(9600);

  Serial.println("Testing GSM SIM800L");
  delay(500);

  while(1)
  {
    myGsm.println("AT+CIPSHUT\r"); //RESPONSE= OK
    delay(200);
    printSerialData();
  
    myGsm.println("AT+CIPMUX=0\r"); //RESPONSE= OK
    delay(200);
    printSerialData();
  
    myGsm.println("AT+CGATT=1\r"); //RESPONSE= OK
    delay(200);
    printSerialData();
  
    myGsm.println("AT+CSTT=\"internet\",\"\",\"\"\r"); //RESPONSE= OK
    delay(500);
    printSerialData();
  
    myGsm.println("AT+CIICR\r"); //RESPONSE= OK
    delay(2000);
    printSerialData();
  
    myGsm.println("AT+CIFSR\r"); //RESPONSE= Returns an IP
    delay(2000);
    printSerialData();
  
    myGsm.println("AT+CIPSTART=\"TCP\",\"159.203.180.107\", 80\r"); //RESPONSE= CONNECTED OK
    delay(500);
    printSerialData();
  
    myGsm.println("AT+CIPSEND\r"); //RESPONSE= >
    delay(1000);
    printSerialData();
  
    myGsm.println("POST http://159.203.180.107/trackerCode/ HTTP/1.1");
    delay(200);
    printSerialData();
  
    myGsm.println("Host: 159.203.180.107");
    delay(200);
    printSerialData();
  
    myGsm.println("Content-Type: application/x-www-form-urlencoded");
    delay(200);
    printSerialData();
  
    myGsm.println("Content-Length: 20\r\n");
    delay(200);
    printSerialData();
  
    myGsm.println("Celsius=TEMPERATURE");
    delay(200);
    printSerialData();
  
    myGsm.write(0x1A); // Ctrl Z
    delay(3000);
    printSerialData();
  /*
    After sending all these instructions, I get the following response,
    OK
    HTTP/1.1 200 OK
    Friday December, 22
    +TCPCLOSE=0
    OK
  */
    myGsm.println("AT+CIPCLOSE"); //RESPONSE= OK
    delay(200);
    printSerialData();
  
    myGsm.println("AT+CIPSHUT"); //RESPONSE= OK
    delay(200);
    printSerialData();
  }
}

void printSerialData()
{
  if(myGsm.available() > 0)
    Serial.println(myGsm.readString());
}

void loop() {
}
