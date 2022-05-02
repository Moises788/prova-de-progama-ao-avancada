#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned char byteToDec( unsigned char codeBit){
  unsigned char bit, auxiliar;
  int numero = 0;
  bit=128;

  for(int cont=7; cont>=0; cont--){

    if((codeBit & bit) > 0){ 
      numero += pow(2, cont);
    }
    bit = bit>>1;
  }
  
  return numero;
}

int setmatriz(int linhas, int colunas, unsigned char **matriz){
    matriz = malloc(linhas * sizeof(unsigned char*));
    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(unsigned char));
    }

  for(int i = 0; i < linhas; i++) {
		for(int j = 0; j < colunas; j++) {
			if ((j%2) == 0){
            
            matriz[i][j] = 1;
        }

        else{
            matriz[i][j] = 0;
        }
		}
	}

  return matriz;
}

void imprimematriz(unsigned char **matriz, int linhas, int colunas){
  printf("---------------------------- Matriz Gerada ---------------------------------\n\n");
  for(int i = 0; i < linhas; i++) {        
		for(int j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n\n");
	}
}


int main(){
    unsigned char *pc, **matriz;
    unsigned __int64 decodeBit;
    int aux = 7;

    pc = malloc(8*sizeof(unsigned char*));
    //decodeBit = malloc(sizeof(unsigned long long*));
    matriz = setmatriz(8,8, matriz);
    
    for (int i = 0; i < 8; i++){
      pc[i] = 0;
    }
   
    
    imprimematriz(matriz,8,8);

    for (int i = 0; i < 8; i++){
      aux =7;
      for(int j = 0; j < 8; j++) {        
        pc[i] += byteToDec(matriz[i][j]<<aux);
        aux--;  
	    } 
    }
    for (int i = 0; i < 8; i++){
       printf("%d \n",pc[i]);
    }
   
    memcpy (&decodeBit, pc, sizeof (unsigned __int64));

    printf("%d \n", decodeBit);
   
    
    
    return 0;
}