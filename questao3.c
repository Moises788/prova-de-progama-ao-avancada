/**
 * Questão: 3
 * Aluno: Moisés de Medeiros Galvão
 * Turma: T02
 * Professor: IGNACIO SANCHEZ GENDRIZ
 */

#include <stdio.h>
#include <stdlib.h>

int setmatriz(int linhas, int colunas, int **matriz);
int MultMat(int **matriz_a, int **matriz_b, int linha_a,int coluna_a, int coluna_b);
void imprimematriz(int **matriz, int linhas, int colunas);
void freematriz(int colunas, int **matriz);

int main(){
  int **matriza, **matrizb, **matrizc;
  int NLinA, NColA;
  int NLinB, NColB;

  printf("Digite o numero de linhas da matriz A\n");
  scanf("%i", &NLinA);

  printf("Digite o numero de colunas da matriz A\n");
  scanf("%i", &NColA);
  
  matriza = setmatriz(NLinA, NColA, matriza);
  imprimematriz(matriza, NLinA, NColA);
  
  printf("Digite o numero de linhas da matriz B\n");
  scanf("%i", &NLinB);

  printf("Digite o numero de colunas da matriz B\n");
  scanf("%i", &NColB);
  
  matrizb = setmatriz(NLinB,NColB,matrizb);
  imprimematriz(matrizb, NLinB, NColB);
  
  if (NColA == NLinB)
  {
    matrizc = MultMat(matriza, matrizb, NLinA, NColA, NColB);
  imprimematriz(matrizc, NLinA, NColB);
  }
  else{
    printf("Matrizes incompativeis para multiplicar");
  }
  
  freematriz(NColB, matrizc);
  freematriz(NColB, matrizb);
  freematriz(NColA, matriza);

  return 0;
}

void imprimematriz(int **matriz, int linhas, int colunas){
  printf("---------------------------- Matriz Gerada ---------------------------------\n\n");
  for(int i = 0; i < linhas; i++) {        
		for(int j = 0; j < colunas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n\n");
	}
}

int setmatriz(int linhas, int colunas, int **matriz){
    matriz = malloc(linhas * sizeof(int*));

    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }
  for(int i = 0; i < linhas; i++) {
		for(int j = 0; j < colunas; j++) {
			printf("Digite o valor de [%d,%d] da matriz\n", i, j);
			scanf("%d", &matriz[i][j]);
		}
		printf("\n"); 
	}

  return matriz;
}

void freematriz(int colunas, int **matriz){
  for(int i = 0; i < colunas; i++){
        free(matriz[i]);
    }
  free(matriz);
}

int MultMat(int **matriz_a, int **matriz_b, int linha_a,int coluna_a, int coluna_b){
  int **matriz_c;
  
  matriz_c = malloc(linha_a * sizeof(int*));
    for(int i = 0; i < linha_a; i++){
        matriz_c[i] = malloc(coluna_b * sizeof(int));
    }

  for(int linha = 0; linha < linha_a; linha++)
    for(int coluna = 0; coluna < coluna_b; coluna++){
      
      int somaprod=0;
      
      for(int i=0; i < coluna_a; i++){
        somaprod += (matriz_a[linha][i] * matriz_b[i][coluna]);
      }

      matriz_c[linha][coluna] = somaprod;
    }

    return matriz_c;
}
