//#include "HX711.h"
//HX711 scale;
//SCK:A0;OUT:A1  
void setup() {
  Serial.begin(9600);
//  scale.begin(A1, A0);
//  scale.set_scale(2280.f);
//  scale.tare(); // reset the scale to 0
}
  
void loop() {
//  Serial.print("Reading:\t");
//  Serial.println(scale.get_units(),0);
//  scale.power_down();
  Serial.println(analogRead(A0));
  delay(500);
//  scale.power_up();
}
