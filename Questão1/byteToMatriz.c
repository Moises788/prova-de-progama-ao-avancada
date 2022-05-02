#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned char byteToDec( unsigned char codeBit){
  unsigned char bit, auxiliar;
  int aux, numero = 0;
  bit=128;

  for(int cont=7; cont>=0; cont--){

    if((codeBit & bit) > 0){ 
      numero += pow(2, cont);
    }
    else{
      aux = 0;
    }
    bit = bit>>1;
    aux++;
  }
  
  return numero;
}



int main(){
    unsigned char *pc, matriz[8];
    int aux = 7;
    pc = malloc (8 * sizeof (int));
    pc = 0;
    
    for(int i = 7; i >= 0; i--){
        
        if ((i%2) == 0){
            
            matriz[i] = 1;
        }

        else{
            matriz[i] = 1;
        }
        
    }

     for(int i = 0; i < 8; i++) {        
        pc += byteToDec(matriz[i]<<aux);
        aux--;
        
	} 

    
    
    printf("%d", byteToDec(pc));

    
    return 0;
}