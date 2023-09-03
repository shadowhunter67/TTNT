/* Nối chân LCD NOKIA 5110
 *  RST   / CE    / DC    / DIN   / CLK   / VCC/LIGHT/ GND
 * PIN 6  / PIN 7 / PIN 5 / PIN 4 / PIN 3 / 5V /5V   / GND   */
/******************************************************************************************************************************************************************************************/
#include <PCD8544.h> // Thư viện của LCD
static PCD8544 lcd;
int dong;
int dem;
int menu;
int dem1;
int save;
int save1;
void setup(){lcd.begin(84, 48);}

void loop(){
  if(digitalRead(A0)==0){dong--;}
  if(digitalRead(A1)==0){dong++;}
  
  if(dem==0){menu1();menu=1;
  if(dong<0){dem=1;dong=5;lcd.clear();}
  if(dong>5){dem=1;dong=0;lcd.clear();}
  daunhay();}

  if(dem==1){menu2();menu=2;
  if(dong>5){dem=0;dong=0;lcd.clear();}
  if(dong<0){dem=0;dong=5;lcd.clear();}
  daunhay();}

  
  if(dem>=10 && dem<20){daunhay();
// Menu1
  if(dong==0 && menu==1){task1();menu=3;save1=dong;} 
  if(dong==1 && menu==1){task2();menu=3;save1=dong;}
  if(dong==2 && menu==1){task3();menu=3;save1=dong;}
  if(dong==3 && menu==1){task4();menu=3;save1=dong;}
  if(dong==4 && menu==1){task5();menu=3;save1=dong;}
  if(dong==5 && menu==1){task6();menu=3;save1=dong;}
// Menu2
  if(dong==0 && menu==2){task7();menu=3;save1=dong;}
  if(dong==1 && menu==2){task8();menu=3;save1=dong;}
  if(dong==2 && menu==2){task9();menu=3;save1=dong;}
  if(dong==3 && menu==2){task10();menu=3;save1=dong;}
  if(dong==4 && menu==2){task11();menu=3;save1=dong;}
  if(dong==5 && menu==2){task12();menu=3;save1=dong;}
  }
  
  if(dem==20){
  if(dong==0 && menu==3){task1_1();menu=4;save=1;} 
  if(dong==1 && menu==3){task1_2();menu=4;save=1;}}
  if(dem==21){
  if(dong==0 && menu==3){task11_1();menu=4;save=2;} 
  if(dong==1 && menu==3){task11_2();menu=4;save=2;}}
 
  if(digitalRead(A2)==0){lcd.clear();dem+=10;}
  if(digitalRead(A3)==0){lcd.clear();dem-=10;menu=save;dong=save1;}
  if(digitalRead(A4)==0){lcd.clear();dem=0;dong=0;}
  if(dem<0){lcd.clear();dem=0;dong=0;}
  if(dem>21){lcd.clear();dem=0;dong=0;}
}
/******************************************************************************************************************************************************************************************/
void daunhay(){
  lcd.setCursor(0, dong);
  lcd.print(">");
  delay(100);
  lcd.setCursor(0, dong);
  lcd.print(" ");
  delay(100);
}
/******************************************************************************************************************************************************************************************/
void menu1(){
//Task1
  lcd.setCursor(6, 0);
  lcd.print("Task1");
//Task2
  lcd.setCursor(6, 1);
  lcd.print("Task2");
//Task3
  lcd.setCursor(6, 2);
  lcd.print("Task3");
//Task4  
  lcd.setCursor(6, 3);
  lcd.print("Task4");
//Task5  
  lcd.setCursor(6, 4);
  lcd.print("Task5");
//Task6  
  lcd.setCursor(6, 5);
  lcd.print("Task6");
}
/******************************************************************************************************************************************************************************************/
void menu2(){
//Task7
  lcd.setCursor(6, 0);
  lcd.print("Task7");
//Task8
  lcd.setCursor(6, 1);
  lcd.print("Task8");
//Task9
  lcd.setCursor(6, 2);
  lcd.print("Task9");
//Task10  
  lcd.setCursor(6, 3);
  lcd.print("Task10");
//Task11  
  lcd.setCursor(6, 4);
  lcd.print("Task11");
//Task10  
  lcd.setCursor(6, 5);
  lcd.print("Task12");
}
/******************************************************************************************************************************************************************************************/
void task1(){
  lcd.setCursor(6, 0);
  lcd.print("Task1.1");
  lcd.setCursor(6, 1);
  lcd.print("Task1.2");}

void task1_1(){
  lcd.setCursor(6, 0);
  lcd.print("task1-1");}

void task1_2(){
  lcd.setCursor(6, 0);
  lcd.print("task1-2");}
    
void task2(){
  lcd.setCursor(6, 0);
  lcd.print("Task2");}
void task3(){
  lcd.setCursor(6, 0);
  lcd.print("Task3");}
void task4(){
  lcd.setCursor(6, 0);
  lcd.print("Task4");}
void task5(){
  lcd.setCursor(6, 0);
  lcd.print("Task5");}
void task6(){
  lcd.setCursor(6, 0);
  lcd.print("Task6");}
void task7(){
  lcd.setCursor(6, 0);
  lcd.print("Task7");}
void task8(){
  lcd.setCursor(6, 0);
  lcd.print("Task8");}
void task9(){
  lcd.setCursor(6, 0);
  lcd.print("Task9");}
void task10(){
  lcd.setCursor(6, 0);
  lcd.print("Task10");}
void task11(){
  lcd.setCursor(6, 0);
  lcd.print("Task11.1");
  lcd.setCursor(6, 1);
  lcd.print("Task11.2");}

void task11_1(){
  lcd.setCursor(6, 0);
  lcd.print("task11-1");}

void task11_2(){
  lcd.setCursor(6, 0);
  lcd.print("task11-2");}

void task12(){
  lcd.setCursor(6, 0);
  lcd.print("Task12");}
