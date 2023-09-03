void Do_ap(){
  U = map(volt,0,1023, 0, 2500); //+ offset;// map 0-1023 to 0-2500 and add correction offset
  U /=100;// divide by 100 to get the decimal values 
  delay(100);
}
