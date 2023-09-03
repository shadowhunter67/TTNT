void Do_dong(){
// DUAL ID
  // Dong 1
  //1-1, chan 1 vs 2
  //1-2, chan 1 vs 3
  //1-3, chan 5 vs 7
  
  adc0 = analogRead(A2);
  adc0*=50;

  //Dong 2
  //2-1, chan 9 vs 11
  //2-2, chan 11 vs 13
  //2-3, chan 15 vs 16
  
  adc1 = analogRead(A3);
  adc1*=50;
  
  delay(100);
}
