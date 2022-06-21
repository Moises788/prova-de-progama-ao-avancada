#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;
    r = 1; g= 1; b = 1;
    // Alocação dinâmica da matriz 3d
    v = new Voxel**[nx];
     for (int i =0; i<nx; i++){
      v[i] = new Voxel*[ny];

        for (int j =0; j<ny; j++){
       v[i][j]= new Voxel[nz];
      }
    }
}

Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
               delete[] v[i][j];
            }
        }
        for (int i=0; i <nx; i++){
            delete[] v[i];
        }

        delete[] v;

        nx = 0; ny = 0; nz = 0;}

void Sculptor::setColor(float r, float g, float b, float a) // define a cor e transparência de cada voxel
{
    Sculptor::r = r; Sculptor::g = g; Sculptor::b = b; Sculptor::a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true; v[x][y][z].r = r; v[x][y][z].g = g; v[x][y][z].b = b; v[x][y][z].a = a;    

}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
    
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
}

void Sculptor::writeOFF( char *filename){
  int quantvox = 0;
  std::ofstream arquivo;
  arquivo.open(filename);
if (arquivo.is_open()){
    arquivo<<"OFF\n";

    // varre todos os voxel e analisa os que devem ser exibidos no .off
    for (int i = 0; i < nx; i++){
        for (int j = 0; j <ny; j++){
            for (int k = 0; k <nz; k++){
                if(v[i][j][k].isOn == true){
                    quantvox++;
                }
            }
        }
    }

    arquivo<<quantvox * 8<<" "<<quantvox * 6 << " " << "0" << std::endl; // mostra a quantidade total de vertices, faces e arestas
}
/*
O arquivo tem que ser escrito da seguinte forma:

OFF                                                 | Inicia escrevendo o nome OFF
                                                    
NVertices  NFaces  NArestas                         | Quantidade de verticies, faces e arestas
x[0]  y[0]  z[0]                                    | Escreve coordenada de cada verticie (são identados de 0 a n)
...                                                 |
x[NVertices-1]  y[NVertices-1]  z[NVertices-1]      | Aqui é o final da escrita dos vérticies
                                                    
Nv v[0] v[1] ... v[Nv-1]  r g b a                   | Depois escreve o número de vérticies seguidos de sua sequência
Nv v[0] v[1] ... v[Nv-1]  r g b a                   | da regra da mão direita (para um quadrado o número de vérticie é 4)
...                                                 | Depois segue com a cor RGB da face
Nv v[0] v[1] ... v[Nv-1]  r g b a                   | Aqui finaliza as faces
*/
else{
    std::cout << "Erro ao abrir arquivo de texto."; 
    }
    
    arquivo.close();
}