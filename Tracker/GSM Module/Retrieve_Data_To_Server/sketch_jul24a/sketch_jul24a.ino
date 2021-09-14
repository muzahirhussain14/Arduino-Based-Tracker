String gsmResult = "";

void setup() {
  Serial.begin(115200);

  Serial.println("Testing GSM SIM800L");
  delay(500);

  while(1)
  {
    Serial.println("AT+CIPSHUT\r"); //RESPONSE= OK
    printSerialData();
    
    Serial.println("AT+CIPMUX=0\r"); //RESPONSE= OK
    printSerialData();
     
    Serial.println("AT+CGATT=1\r"); //RESPONSE= OK
    printSerialData();

    Serial.println("AT+CSTT=\"internet\",\"\",\"\"\r"); //RESPONSE= OK
    printSerialData();
   
    Serial.println("AT+CIICR\r"); //RESPONSE= OK
    printSerialData();
  
    Serial.println("AT+CIFSR\r"); //RESPONSE= Returns an IP
    printSerialData();
  
    Serial.println("AT+CIPSTART=\"TCP\",\"159.203.180.107\", 80\r"); //RESPONSE= CONNECTED OK
    printSerialData();
  
    Serial.println("AT+CIPSEND\r"); //RESPONSE= >
    printSerialData();

    /*GET /hello.htm HTTP/1.1
    User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)
    Host: www.tutorialspoint.com
    Accept-Language: en-us
    Accept-Encoding: gzip, deflate
    Connection: Keep-Alive*/

    Serial.println("GET http://159.203.180.107/trackerCode/ HTTP/1.1");
    printSerialData();
  
    Serial.println("Host: 159.203.180.107");
    printSerialData();

    Serial.println("Accept: text/plain, text/html");
    printSerialData();


    Serial.println("Accept-Language: en-us\r\n");
    printSerialData();
  
  
    Serial.write(0x1A); // Ctrl Z
    delay(1000);
    printSerialData();
    
  /*
    After sending all these instructions, I get the following response,
    OK
    HTTP/1.1 200 OK
    Friday December, 22
    +TCPCLOSE=0
    OK
  */
    Serial.println("AT+CIPCLOSE"); //RESPONSE= OK
    printSerialData();

    Serial.print(gsmResult);
    gsmResult = "";
    delay(5000);
  }
}

void printSerialData()
{
   delay(2000);
    
   while (Serial.available()) {  
       delay(5);
       
       if(Serial.available() > 0)
       {
        //char c = Serial.read();
        gsmResult += Serial.readString();
       }
   }
}

void loop() {
}
