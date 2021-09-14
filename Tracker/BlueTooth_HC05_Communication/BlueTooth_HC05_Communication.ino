void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.write("Link Ok:\n\n");
}

void loop() {
  // put your main code here, to run repeatedly:

  char data = Serial.read();

  if(data == '1'){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  if(data == '0'){
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.write("Hello World");
}
