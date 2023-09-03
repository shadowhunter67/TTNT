/* Nối chân LCD NOKIA 5110
 *  RST   / CE    / DC    / DIN   / CLK   / VCC / LIGHT / GND
 *  PIN 6 / PIN 7 / PIN 5 / PIN 4 / PIN 3 / 5V  / 5V    / GND   */
/******************************************************************************************************************************************************************************************/
#include <PCD8544.h> // Thư viện của LCD
static PCD8544 lcd;

// Cảm biến dòng: A2,A3 
int adc0; int adc1; 

// Cảm biến vật cản: 24,25 

// Switch nguồn: 53,52,51,50 để đọc giá trị
// Switch: 26,27 để đọc giá trị

// Cảm biến áp: A0,A1 để đọc giá trị
double U; int volt;

// Setup đổi menu
int dong;
int dem;
int dem1;
int menu;
int save;
int save1;

/******************************************************************************************************************************************************************************************/
void setup() {
  lcd.clear();
  lcd.begin(84, 48);
}
/******************************************************************************************************************************************************************************************/
void loop() {
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
  delay(100);
}
/******************************************************************************************************************************************************************************************/
void PICK_MOD(){
//Task1 - sensor1
  lcd.setCursor(6, 0);
  lcd.print("IR1/3: ");  
  lcd.print(digitalRead(22));
//Task2 - SW1
  lcd.setCursor(6, 1);
  lcd.print("PL1/3: ");
  lcd.print(digitalRead(24));
//Task3 - sensor2
  lcd.setCursor(6, 2);
  lcd.print("IR2/4: ");
  lcd.print(digitalRead(23));
//Task4 - SW2  
  lcd.setCursor(6, 3);
  lcd.print("PL2/4: ");
  lcd.print(digitalRead(25));
//Task5  
  lcd.setCursor(6, 4);
  lcd.print("U1/3: ");
  volt=analogRead(A0);
  Do_ap();
  if(U<3.20){U=1.35;}
  if(digitalRead(53)==0){U=0;}
  lcd.print(U,2);
  lcd.print(" V");
//Task6  
  lcd.setCursor(6, 5);
  lcd.print("U2/4: ");
  volt=analogRead(A1);
  Do_ap();
  if(U<3.22){U=1.35;}
  if(digitalRead(53)==0){U=0;}
  lcd.print(U,2);
  lcd.print(" V");
}
/******************************************************************************************************************************************************************************************/
void DUAL_ID(){
  lcd.setCursor(15, 0);
  lcd.print("DUAL ID");//52
//Task1
  lcd.setCursor(6, 2);
  lcd.print("ID1/3: ");
  Do_dong();
  if(adc0>5000){lcd.print("T");}
  else{lcd.print("F");}
//Task2   
  lcd.setCursor(6, 3);
  lcd.print("ID2/4: ");
  Do_dong();
  if(adc1>5000){lcd.print("T");}
  else{lcd.print("F");} 
//Task3  
  lcd.setCursor(6, 4);
  lcd.print("IR1/3: ");
  lcd.print(digitalRead(26));
//Task4  
  lcd.setCursor(6, 5);
  lcd.print("IR2/4: ");
  lcd.print(digitalRead(27));
}
/******************************************************************************************************************************************************************************************/
void QUAD_CIC(){
  lcd.setCursor(15, 0);
  lcd.print("QUAD CIC");//51
//Task1
  lcd.setCursor(6, 2);
  lcd.print("CIC1/3: ");
  Do_dong();
  if(adc0>5000){lcd.print("T");}
  else{lcd.print("F");} 
//Task2
  lcd.setCursor(6, 3);
  lcd.print("CIC2/4: ");
  Do_dong();
  if(adc1>5000){lcd.print("T");}
  else{lcd.print("F");} 
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
