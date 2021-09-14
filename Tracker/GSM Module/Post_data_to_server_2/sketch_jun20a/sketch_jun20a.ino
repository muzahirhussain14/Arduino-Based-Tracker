String completeResult = "";
String currentResult = "";

String commands[] = {"AT+CIPSHUT\r", "AT+CIPMUX=0\r", "AT+CGATT=1\r", "AT+CSTT=\"internet\",\"\",\"\"\r", "AT+CIICR\r",
                     "AT+CIFSR\r", "AT+CIPSTART=\"TCP\",\"159.203.180.107\", 80\r", "AT+CIPSEND\r", "POST http://159.203.180.107/trackerCode/ HTTP/1.1",
                     "Host: 159.203.180.107", "Content-Type: application/x-www-form-urlencoded", "Content-Length: 20\r\n", "Celsius=TEMPERATURE"};
int commandIndex = 0;
const int totalCommands = 13;

void setup() {
  Serial.begin(115200);
  //delay(30000);
  delay(15000);
}

void sendCommand(short commandNumber)
{
  Serial.println(commands[commandNumber]);
  delay(2300);

  currentResult = "";
  
  while(Serial.available())
    currentResult += Serial.readString();

  //check if error
  if(((currentResult.indexOf("+CME") > 0) || (currentResult.indexOf("+CMS") > 0) || currentResult == "") && commandNumber > 1)
  {
    delay(5000);
    Serial.println("AT+CIPCLOSE\r");
    delay(5000);

    Serial.println("AT\r");
    delay(2000);
    
    commandIndex = 0;                           // restart complete process
    completeResult = "";
  }

  else    // on success
    completeResult += currentResult;


  if(commandNumber == (totalCommands - 1))      // send ctrl+z at the end
  {
    Serial.write(0x1A); // Ctrl Z
    delay(3000);
    commandIndex = 1;                           // new starting point for commands

    while(Serial.available()){
      completeResult += Serial.readString();
      delay(10);
    }

    Serial.println("AT+CIPCLOSE\r");
    delay(2000);
    
    Serial.println(completeResult);
    completeResult = "";
  }
}


void loop() {
  sendCommand(commandIndex++);
}
