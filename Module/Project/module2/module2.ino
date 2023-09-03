/* Nối chân LCD NOKIA 5110
 *  RST   / CE    / DC    / DIN   / CLK   / VCC/LIGHT/ GND
 * PIN 6  / PIN 7 / PIN 5 / PIN 4 / PIN 3 / 5V /5V   / GND   */
/******************************************************************************************************************************************************************************************/
#include <PCD8544.h> // Thư viện của LCD
static PCD8544 lcd;

// Cảm biến dòng, áp: A0, A1
int adc;
double U;
double I;
// Cảm biến vật cản(sensor): A2, A3
// SW: A4, A5, 13, 12, 11, 10, 9, 8
int SL;
// Setup đổi menu
int dem;
 
void setup(){lcd.begin(84, 48);}
 
void loop(){
  if(dem==0){Menu1();}
  if(dem==1){Menu2();}
  if(digitalRead(1)==0){lcd.clear();dem++;}
  if(digitalRead(0)==0){lcd.clear();dem--;}
  if(dem<0){dem=1;}
  if(dem==2){dem=0;}
}
/******************************************************************************************************************************************************************************************/
void Menu1(){
  lcd.setCursor(5, 0);
  lcd.print("Pick Mod: ");
  lcd.print(digitalRead(13));
//Task1 - sensor1-2
  lcd.setCursor(0, 2);
  lcd.print("IR1: ");  
  lcd.print(digitalRead(A2));
  lcd.print(" IR2: ");
  lcd.print(digitalRead(A3));
//Task2 - SW1-2
  lcd.setCursor(0, 3);
  lcd.print("PL1:");
  SL = digitalRead(A4); 
  SW();
  lcd.setCursor(43, 3);
  lcd.print("PL2:");
  SL = digitalRead(A5); 
  SW();
//Task3  
  lcd.setCursor(0, 4);
  lcd.print("U1: ");
  adc = analogRead(A0);
  Doc();
  if(digitalRead(13)==0){U=0;}
  lcd.print(U,3);
  lcd.print(" V");
//Task4  
  lcd.setCursor(0, 5);
  lcd.print("U2: ");
  adc = analogRead(A1);
  Doc();
  if(digitalRead(13)==0){U=0;}
  lcd.print(U,3);
  lcd.print(" V");
}
/******************************************************************************************************************************************************************************************/
void Menu2(){
  lcd.setCursor(5, 0);
  lcd.print("DUAL/QUAD ID");
//Task1
  lcd.setCursor(0, 2);
  lcd.print("I1: ");
  adc = analogRead(A0);
  Doc();
  if(I>0.903 || (digitalRead(12)==0 && digitalRead(11)==0 && digitalRead(10)==0)){I=0;}//0.902 //0.83 //0.73
  lcd.print(I,3);
  lcd.print(" A");
//Task2
  lcd.setCursor(0, 3);
  lcd.print("I2: ");
  adc = analogRead(A1);
  Doc();
  if(I>0.903 || (digitalRead(12)==0 && digitalRead(11)==0 && digitalRead(10)==0)){I=0;}//0.902 //0.83 //0.73
  lcd.print(I,3);
  lcd.print(" A"); 
//Task3
  lcd.setCursor(0, 4);
  lcd.print("IR1: ");
  lcd.print(digitalRead(A2));
//Task4
  lcd.setCursor(0, 5);
  lcd.print("IR2: ");
  lcd.print(digitalRead(A3));
}
/******************************************************************************************************************************************************************************************/
