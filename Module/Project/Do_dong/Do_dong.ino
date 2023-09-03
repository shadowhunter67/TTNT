int adc0;
int adc1;
int dem1;
int dem2;

void setup() {

  Serial.begin(9600);

}
void loop(){
// DUAL ID
  // Dong 1
  //1-1, chan 1 vs 2
  //1-2, chan 1 vs 3
  //1-3, chan 5 vs 7
  adc0 = analogRead(28);
  Serial.print("IR1: ");
  Serial.print(adc0);
  Serial.print("  ");
  if(adc0>5000){adc0=1;}
  else{adc0=0;}
  Serial.println(adc0);
//  if(dem1==3){Serial.println("FAIL");}
//  else {Serial.println("OK");}

  //Dong 2
  //2-1, chan 9 vs 11
  //2-2, chan 11 vs 13
  //2-3, chan 15 vs 16
  
  adc1 = analogRead(29);
  Serial.print("IR2: ");
  Serial.print(adc1);
  Serial.print("  ");
  if(adc1>5000){adc1=1;}
  else{adc1=0;}
  Serial.println(adc1);
//  if(dem2==3){Serial.println("FAIL");}
//  else {Serial.println("OK");}
  
  Serial.println(" ");
  delay(1000);
}
