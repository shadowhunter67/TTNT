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

// Menu
int dong;
int dem;
int dem1;
int menu;
int save;
int save1;

void setup(){lcd.begin(84, 48);}
 
void loop(){
  Giaodien();

  if(dem==0){menu1();menu=1;
  if(dong<0){dong=3;}
  if(dong>3){dong=0;}
  daunhay();}

  if(dem==10){daunhay();
  if(dong<0){dong=3;}
  if(dong>3){dong=0;}
  if(dong==0 && menu==1){SMART_PICK();menu=3;} 
  if(dong==1 && menu==1){SNT();menu=4;dong=0;}
  if(dong==2 && menu==1){menu=5;dong=0;dem=20;} 
  if(dong==3 && menu==1){PRE();menu=6;dong=0;}
  }
  
  if(dem==20){
  if(dong==0 && menu==3){PICK_MOD();menu=3;save1=0;save=1;} 
  if(dong==1 && menu==3){DUAL_ID();menu=3;save1=0;save=1;}
  if(dong==2 && menu==3){QUAD_CIC();menu=3;save1=0;save=1;}
  
  if(dong==0 && menu==4){A();menu=4;save1=1;save=1;} 
  if(dong==1 && menu==4){B();menu=4;save1=1;save=1;}

  if(dong==0 && menu==5){CARR();if(digitalRead(1)==0){lcd.clear();dem=0;dong=0;}}
  
  if(dong==0 && menu==6){SR();menu=6;save1=3;save=1;} 
  if(dong==1 && menu==6){BR();menu=6;save1=3;save=1;}
  if(dong==2 && menu==6){LC();menu=6;save1=3;save=1;}
  }
}
/******************************************************************************************************************************************************************************************/
void PICK_MOD(){
//Task1 - sensor1
  lcd.setCursor(6, 0);
   lcd.print("IR1/3: ");
   lcd.print(digitalRead(A2));  
//Task2 - SW1
  lcd.setCursor(6, 1);
  lcd.print("PL1/3: ");
  lcd.print(digitalRead(A4));
//Task3 - sensor2
  lcd.setCursor(6, 2);
  lcd.print("IR2/4: ");
  lcd.print(digitalRead(A3)); 
//Task4 - SW2
  lcd.setCursor(6, 3);
  lcd.print("PL2/4: ");
  lcd.print(digitalRead(A5)); 
//Task5  
  lcd.setCursor(6, 4);
  lcd.print("U1/3: ");
  adc = analogRead(A0);
  Doc();
  if(digitalRead(13)==0){U=0;}
  lcd.print(U,2);
  lcd.print(" V");
//Task4  
  lcd.setCursor(6, 5);
  lcd.print("U2/4: ");
  adc = analogRead(A1);
  Doc();
  if(digitalRead(13)==0){U=0;}
  lcd.print(U,2);
  lcd.print(" V");
}
/******************************************************************************************************************************************************************************************/
void DUAL_ID(){
  lcd.setCursor(22, 0);
  lcd.print("DUAL ID");//12
//Task1
  lcd.setCursor(6, 2);
  lcd.print("I1/3: ");
  adc = analogRead(A0);
  Doc();
  if(digitalRead(12)==0){I=0;}
  if(I==0){lcd.print("F");}
  else{lcd.print("T");}
//Task2
  lcd.setCursor(6, 3);
  lcd.print("I2/4: ");
  adc = analogRead(A1);
  Doc();
  if(digitalRead(12)==0){I=0;}
  if(I==0){lcd.print("F");}
  else{lcd.print("T");}
//Task3
  lcd.setCursor(6, 4);
  lcd.print("IR1/3: ");
  lcd.print(digitalRead(A2));
//Task4
  lcd.setCursor(6, 5);
  lcd.print("IR2/4: ");
  lcd.print(digitalRead(A3));
}
/******************************************************************************************************************************************************************************************/
void QUAD_CIC(){
  lcd.setCursor(18, 0);
  lcd.print("QUAD CIC");
//Task1
  lcd.setCursor(6, 2);
  lcd.print("CIC1/3: ");
  adc = analogRead(A0);
  Doc();
  if(digitalRead(11)==0){I=0;}
  if(I==0){lcd.print("F");}
  else{lcd.print("T");}
//Task2
  lcd.setCursor(6, 3);
  lcd.print("CIC2/4: ");
  adc = analogRead(A1);
  Doc();
  if(digitalRead(11)==0){I=0;}
  if(I==0){lcd.print("F");}
  else{lcd.print("T");}
}
/******************************************************************************************************************************************************************************************/
void A(){
  lcd.setCursor(30, 0);
  lcd.print("A");
  lcd.setCursor(6, 2);
  lcd.print("IRH: ");
  lcd.setCursor(6, 3);
  lcd.print("IRP: ");
  lcd.setCursor(6, 4);
  lcd.print("IRC: ");
}
/******************************************************************************************************************************************************************************************/
void B(){
  lcd.setCursor(30, 0);
  lcd.print("B");
  lcd.setCursor(6, 2);
  lcd.print("IRD: ");
  lcd.setCursor(6, 3);
  lcd.print("IRW1: ");
  lcd.setCursor(6, 4);
  lcd.print("IRW2: ");
  lcd.setCursor(6, 5);
  lcd.print("IRT: ");
}
/******************************************************************************************************************************************************************************************/
void CARR(){
  lcd.setCursor(15, 0);
  lcd.print("Carriage");
  lcd.setCursor(6, 2);
  lcd.print("IR3: ");
  lcd.setCursor(6, 3);
  lcd.print("IR4: ");
  lcd.setCursor(6, 4);
  lcd.print("IR5: ");
  }
/******************************************************************************************************************************************************************************************/
void SR(){
  lcd.setCursor(5, 0);
  lcd.print("Border Reject");
  lcd.setCursor(6, 2);
  lcd.print("IR1: ");
  lcd.setCursor(6, 3);
  lcd.print("IR2: ");
  lcd.setCursor(6, 4);
  lcd.print("IR3: ");
  lcd.setCursor(6, 5);
  lcd.print("IR4: ");
}
/******************************************************************************************************************************************************************************************/
void BR(){
  lcd.setCursor(5, 0);
  lcd.print("Signal Reject");
  lcd.setCursor(6, 2);
  lcd.print("IR1: ");
  lcd.setCursor(6, 3);
  lcd.print("IR2: ");
}
/******************************************************************************************************************************************************************************************/
void LC(){
  lcd.setCursor(5, 0);
  lcd.print("Coil && Latch");
  lcd.setCursor(6, 2);
  lcd.print("LD: ");
  lcd.setCursor(6, 3);
  lcd.print("I1: ");
  lcd.setCursor(6, 4);
  lcd.print("I2: ");
  lcd.setCursor(6, 5);
  lcd.print("I3: ");
}
/******************************************************************************************************************************************************************************************/
