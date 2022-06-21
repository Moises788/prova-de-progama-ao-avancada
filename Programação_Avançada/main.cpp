#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
int main(){
  // cria um escultor cuja matriz tem 10x10x10 voxels
  Sculptor voxel(1,1,1);
  // para mudar a cor do voxel
  voxel.setColor(0,0,1.0,1.0); // azul
  // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  voxel.putVoxel(0,0,0);
  // grava a escultura digital no arquivo "trono.off"
  voxel.writeOFF("seila.off");

}