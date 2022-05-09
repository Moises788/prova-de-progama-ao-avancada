#include <stdlib.h>
#include <stdio.h>

unsigned char decToByte( unsigned char codeBit){
  unsigned char bit;
  int numero = 0, cont;
  bit=128;

  for(cont=7; cont>=0; cont--){

    if((codeBit & bit) > 0){
      printf("1");
    }
    else{
      printf("0");
    }
    bit = bit>>1;
  }
  
  return numero;
}

void imprimematriz(unsigned char matriz[8][8] , int linhas, int colunas){
  printf("---------------------------- Matriz Gerada ---------------------------------\n\n");
  int i, j;
  for(i = 0; i < linhas; i++) {        
		for(j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n\n");
	}
}


int main(){
    unsigned char *pc, matriz[8][8];
    unsigned long long decodeBit;
    int i, j;
    int aux = 7;
  for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			if ((j%2) == 0){
            
            matriz[i][j] = 0;
        }

        else{
            matriz[i][j] = 1;
        } 
		}
	}
    pc = &decodeBit;
   matriz[0][1] = 0;
   matriz[0][0] = 0;
    imprimematriz(matriz,8,8);

    for ( i = 0; i < 8; i++){
      aux =7;
      pc[i] = 0;
      
      for( j = 0; j < 8; j++) {        
        pc[i] += matriz[i][j]<<aux;
        aux--;  
	    }
      printf("%d \n", pc[i]); 
       
    }

    printf("%llu \n", decodeBit);

     for(i=0; i<=7; i++){
    decToByte(pc[i]);
    printf("|");
  }
   
    return 0;
}