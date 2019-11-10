/*  
 *   From a float number to the near unsigned integer 
*/
word Nword(float x) {
  word h;
  if(x >= 0) {
   h = word(x + 0.5); 
}
  if(x < 0){ 
  h = word(x - 0.5);
}
return h;
}
