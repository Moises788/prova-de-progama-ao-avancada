#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  unsigned char ***mat;
  int i, j, k, x=11, y=11, z=13;
  int xcenter = 5, ycenter =5, zcenter=6, rx=5, ry=5, rz=6;
  int planoz;
  
  mat = malloc (sizeof(int**)*x);

  for(i =0; i<x; i++){
    mat[i] = malloc(sizeof(int*)*y);
    for (j=0; j<y; j++){
      mat[i][j] = malloc(sizeof(int)*z);
      }
  } 
  for(i =0; i<x; i++){
    for (j=0; j<y; j++){
      for(k=0; k<z; k++){
        //mat[i][j][k]  = i+j+k;
        if (((pow(i-xcenter,2)/pow(rx, 2)) + (pow(j-ycenter,2)/pow(ry,2))+(pow(k-zcenter, 2)/pow(rz, 2))) <= 1){
          mat[i][j][k]  = 1;
        }
        else{
          mat[i][j][k]  = 0;
        }
          
        }
        
        }
      }
  printf("Digite a posição\n\n");

  scanf("%d", &planoz);
 for(i =0; i<x; i++){
    for (j=0; j<y; j++){
      printf("%d", mat[i][j][planoz]);
        }
   printf("\n");
      }
  
}