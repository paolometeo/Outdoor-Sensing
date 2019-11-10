/*  Trasforma un numero float    in un 
    numero intero arrotondato
*/
int Nword(float x) {
  int h;
  if(x >= 0) {
   h = int(x + 0.5); 
}
  if(x < 0){ 
  h = int(x - 0.5);
}
return h;
}
