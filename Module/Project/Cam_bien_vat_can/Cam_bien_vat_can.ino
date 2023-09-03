void setup() 
{ //pinMode(A0, OUTPUT);
  Serial.begin(9600);}
  
void loop() 
{ 
  Serial.print("IR1: ");
  Serial.println(analogRead(A0));
  Serial.println(" ");
  delay(500);
  
}


  
