void Doc(){
  U = ( adc / 1024.0 ) * 5;
  
  if(digitalRead(13)==1){
  I = (( 2.5 - U ) * 0.525);}
  
  if(digitalRead(12)==1){
  I = (( 2.5 - U ) * 0.48);}
  
  if(digitalRead(11)==1){
  I = (( 2.5 - U ) * 0.68);}

}
