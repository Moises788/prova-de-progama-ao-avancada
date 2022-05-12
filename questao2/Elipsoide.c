/*
  Questão: 2 - prova de ponteiros
  Aluno: Moisés de Medeiros Galvão
  PROGRAMACAO AVANCADA - T01 
  Professor: AGOSTINHO DE MEDEIROS BRITO JUNIOR
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned char ***setSpace(unsigned char ***matriz, int x, int y, int z);
void freeMatriz(unsigned char ***matriz, unsigned int x, unsigned int y);
void sendPlan(unsigned char ***matriz, unsigned int x, unsigned int y, unsigned int z);

int main(void) {
  unsigned char ***matriz;
  unsigned int planoz, x, y, z;
  
  printf("digite as dimensões do espaço tridimensional: \n");
  printf("obs: os eixos x, y e z devem ser impares para que a elipsóide toque os extremos do espaço.\n ");

  printf("eixo x:\n ");
  scanf("%d", &x);
  
  printf("eixo y:\n ");
  scanf("%d", &y);
  
  printf("eixo z:\n ");
  scanf("%d", &z);

  //enviando a elipsoide para a matriz
  matriz = setSpace(matriz, x, y, z);

  printf("Digite a posição\n\n");
  scanf("%d", &planoz);

  //cortando a elipsoide no plano z escolhido e visualizando a figura em vista superior
  sendPlan(matriz, x, y, planoz );
  freeMatriz( matriz, x, y); //libera memória alocada
 
}

//função que realia o cálculo necessário para formar a elipsóide
unsigned char ***setSpace(unsigned char ***matriz, int x, int y, int z){
  int centro_x, centro_y, centro_z; 
  //Calculo para encontrar o centro de cada eixo
  centro_x = (x-1)/2;
  centro_y = (y-1)/2;
  centro_z = (z-1)/2;
  
  //Alocação dinâmica dos espaço tridimencional
  matriz = malloc (sizeof(int**)*x);
  for(int i =0; i<x; i++){
    matriz[i] = malloc(sizeof(int*)*y);
    for (int j=0; j<y; j++){
      matriz[i][j] = malloc(sizeof(int)*z);
    }
  } 

//impementação da fórmula da elipsóide
//Referência: indície 1.2 do site:  //http://www.mat.ufpb.br/~sergio/winplot/vetorial/quadricas.html#:~:text=1.2.-,Elips%C3%B3ide,os%20eixos%20maior%20e%20menor.
  for(int i =0; i<x; i++){
    for (int j=0; j<y; j++){
      for(int k=0; k<z; k++){
        if (((pow(i-centro_x,2)/pow(centro_x, 2)) + (pow(j-centro_y,2)/pow(centro_y,2))+(pow(k-centro_z, 2)/pow(centro_z, 2))) <= 1){
          matriz[i][j][k]  = 'X'; //Preenchend o formato da elipsóide com um 'X'
        }
        else{
          matriz[i][j][k]  = 'o'; //espaços vazios representados com um 'o'
        }
          
      }
        
    }
  }

  return matriz;
  freeMatriz( matriz, x, y); //liberando memória
  
}

//função para impressão da matriz a partir de um plano z (vista superior da figura)
void sendPlan(unsigned char ***matriz, unsigned int x, unsigned int y, unsigned int z){
  for(int i =0; i<x; i++){
    for (int j=0; j<y; j++){
      printf("%c", matriz[i][j][z]);
        }
   printf("\n");
      }
}
//função que liberar a memória alocada
void freeMatriz(unsigned char ***matriz, unsigned int x, unsigned int y){
  //liberando o eixo z
  for ( int i=0 ; i<x ; i++){
      for ( int j=0; j<y ; j++){
      free( matriz[i][j] );
    }
  }
  //liberando o eixo y
  for ( int i=0 ; i<x ; i++ ){
  free ( matriz [i] );
  }
  //liberando o eixo x
  free( matriz );
}