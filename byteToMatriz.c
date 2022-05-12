/*
  Questão: 1 - prova de ponteiros
  Aluno: Moisés de Medeiros Galvão
  PROGRAMACAO AVANCADA - T01 
  Professor: AGOSTINHO DE MEDEIROS BRITO JUNIOR
 */

#include <stdlib.h>
#include <stdio.h>

//função responsável por representar um byte em binário
void decToByte( unsigned char codeBit){ 
  unsigned char bit;
  int numero = 0, cont;
  bit=128;

  for(cont=7; cont>=0; cont--){

    if((codeBit & bit) > 0){
      printf("1 ");
    }
    else{
      printf("0 ");
    }
    bit = bit>>1;
  }
}

//função responsável por converter cada linha de uma matriz 8x8 em um byte
//e retornar esses 8 bytes em uma variável unsigned long long.
unsigned long long compMat(unsigned char matriz[8][8]){  
  int aux;
  unsigned char *pc;
  unsigned long long bigByte;

  pc = &bigByte;
  
  for (int i = 0; i < 8; i++){
    aux =7;
    pc[i] = 0;
    
    //realiza deslocamento da matriz para converter a linha em um byte e armazenar na posição desejada
    for(int j = 0; j < 8; j++) {        
      pc[i] += matriz[i][j]<<aux; 
      aux--;
    }   
  } 
  return bigByte; //retorna a matriz compactada
}

//função para imprimir uma matriz 8x8.
void imprimematriz(unsigned char matriz[8][8]){
  printf("---------------------------- Matriz Gerada ---------------------------------\n\n");
  int i, j;
  for(i = 0; i < 8; i++) {        
		for(j = 0; j < 8; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

//função que converte uma variável unusigned long long em uma matriz binária 8x8
//essa função apenas realiza um print dessa matriz
void send(unsigned long long bigByte ){
  unsigned char *pAux;
  pAux = &bigByte;
  //chama função que converte um byte em binário e imprime em formato de matriz
  for(int i=0; i<=7; i++){
    decToByte(pAux[i]);
    printf("\n");
  }

}

int main(){
  unsigned char matriz[8][8]; //matriz a ser convertida
  unsigned long long decodeBit; //variável que vai receber a matriz em long long
  char resposta; //variável auxiliar
  int i, j; //variáveis que armazena indicíes da linha e coluna da matriz 
  int aux; //auxiliar para ligar ou desligar led;
  
  //laço for para incrementar valores n matriz
  for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			if ((j%2) == 0){ //colunas par recebem valor 0
            
            matriz[i][j] = 0;
        }

        else{ //colunas ímpar recebe 1
            matriz[i][j] = 1;
        } 
		}
	}
  //imprime matriz construida
  imprimematriz(matriz); 

  //condensa matriz em um unsigned long long
  decodeBit = compMat(matriz);
  printf("\nMatriz compactada: %llu \n\n", decodeBit);

  //recupera a matriz a partir da sua forma compactada
  send(decodeBit);

  //opção para escolher ligar ou desligar um led específico da matriz
  printf("Deseja ligar ou desligar um led específico? \n");
  printf("s/n: \n");
  scanf("%c", &resposta);
    
  if(resposta == 's'){
    printf("digite a linha: ");
    scanf("%d", &i);
    printf("\n ");
    
    printf("digite a coluna: ");
    scanf("%d", &j); 
    printf("\n ");
    
    printf("1 - desliga e 0 desliga: ");
    scanf("%d", &aux);
    
    matriz[i][j] = aux;
    decodeBit = compMat(matriz);
    send(decodeBit);
    
    while(1){
      printf("deseja ligar ou desligar um outro led específico?\n");
      printf("s/n: \n");
      scanf("%c", &resposta);
      
      if(resposta == 's'){
      printf("digite a linha: ");
      scanf("%d", &i);
      printf("\n ");
      
      printf("digite a coluna: ");
      scanf("%d", &j); 
      printf("\n ");
      
      printf("1 - desliga e 0 desliga: \n ");
      scanf("%d", &aux);
      
      matriz[i][j] = aux;
      decodeBit = compMat(matriz);
      send(decodeBit);
      
      }
      
      else if(resposta == 'n'){
        break;
      }
    }
  }
  else{
    exit(1);
  }
  
  return 0;
}