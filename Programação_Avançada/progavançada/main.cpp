#include <iostream>
#include <fstream>
#include <string>
#include "sculptor.h"

int main(void){
	Sculptor exemplo(60,60,60);
  	Sculptor caveiraOP(60,60,60);
	
	exemplo.putBox(15,20,36,40,30,36);
  	exemplo.cutBox(17,19,38,40,30,32);
  
	exemplo.setColor(1,1,1,1);
  	exemplo.putEllipsoid(5,25,30,6,10,6);
  	exemplo.cutEllipsoid(5,30,30,6,10,6);
  
  	exemplo.setColor(1,0,1, 0.5);
  	exemplo.putSphere(29,30,30,10); 
  	exemplo.cutSphere(29,35,30,10);
 	
  	exemplo.writeOFF((char*)"exemplo.off");

  	caveiraOP.putBox(18,20,36,38,30,31);
	caveiraOP.putBox(17,19,37,39,30,31);
	caveiraOP.putBox(16,18,38,40,30,31);
	caveiraOP.putBox(15,17,39,41,30,31);
	caveiraOP.putBox(14,16,40,42,30,31);
	caveiraOP.putBox(15,17,41,43,30,31);
	caveiraOP.putBox(13,15,39,41,30,31);
	//osso 01 parte de baixo:
	caveiraOP.setColor(1,1,1,1);
	caveiraOP.putBox(39,41,17,19,30,31);
	caveiraOP.putBox(37,39,15,17,30,31);
	caveiraOP.putBox(38,40,16,18,30,31);
	caveiraOP.putBox(37,39,17,19,30,31);
	caveiraOP.putBox(36,38,18,20,30,31);
	caveiraOP.putBox(35,37,19,21,30,31);
	caveiraOP.putBox(34,36,20,22,30,31);
	
	//osso 02 parte de cima:
	caveiraOP.setColor(1,1,1,1);
	caveiraOP.putBox(44,46,39,41,30,31);
	caveiraOP.putBox(42,44,41,43,30,31);
	caveiraOP.putBox(43,45,40,42,30,31);
	caveiraOP.putBox(42,44,39,41,30,31);
	caveiraOP.putBox(41,43,38,40,30,31);
	caveiraOP.putBox(40,42,37,39,30,31);
	caveiraOP.putBox(39,41,36,38,30,31);
	//osso 02 parte de baixo:
	caveiraOP.putBox(23,25,20,22,30,31);
	caveiraOP.putBox(22,24,19,21,30,31);
	caveiraOP.putBox(21,23,18,20,30,31);
	caveiraOP.putBox(20,22,17,19,30,31);
	caveiraOP.putBox(19,21,16,18,30,31);
	caveiraOP.putBox(20,22,15,17,30,31);
	caveiraOP.putBox(18,20,17,19,30,31);
   
	
	//maxilar:
	caveiraOP.setColor(1,1,1,1);
  caveiraOP.putEllipsoid(29,25,30,6,10,6);
    
  //cranio:
  caveiraOP.setColor(1,1,1,1);
  caveiraOP.putSphere(29,30,30,10); 
    
  //Chapeu
  caveiraOP.setColor(1,0.8,0,1);
  caveiraOP.putSphere(29,34,30,8); 
  
  //aba do chapeu
 	caveiraOP.putEllipsoid(29,35,30,20,1,20);
 	caveiraOP.setColor(1,0,0,1);
  caveiraOP.putEllipsoid(29,36,30,10,1,10);
	caveiraOP.putEllipsoid(29,37,30,10,1,8);
	
	//olho esquerdo:
	caveiraOP.setColor(0,0,0,1);
	caveiraOP.cutBox(23,27,28,33,37,40);
	caveiraOP.putBox(23,27,28,33,37,40);
	caveiraOP.cutVoxel(27,30,39);
	caveiraOP.putVoxel(27,30,39);
	caveiraOP.cutVoxel(27,29,39);
	caveiraOP.putVoxel(27,29,39);
	caveiraOP.cutVoxel(27,31,39);
	caveiraOP.putVoxel(27,31,39);
	caveiraOP.putVoxel(22,29,39);
	caveiraOP.putVoxel(22,30,39);
	caveiraOP.putVoxel(22,31,39);
	caveiraOP.putVoxel(25,27,39);
	caveiraOP.putVoxel(25,33,39);
	caveiraOP.putVoxel(24,27,39);
	caveiraOP.putVoxel(24,33,39);
	
	//olho direito:
	caveiraOP.setColor(0,0,0,1);
	caveiraOP.cutBox(32,36,28,33,37,40);
	caveiraOP.putBox(32,36,28,33,37,40);
	caveiraOP.cutVoxel(36,30,39);
	caveiraOP.putVoxel(36,30,39);
	caveiraOP.cutVoxel(36,29,39);
	caveiraOP.putVoxel(36,29,39);
	caveiraOP.cutVoxel(36,31,39);
	caveiraOP.putVoxel(36,31,39);
	caveiraOP.putVoxel(31,29,39);
	caveiraOP.putVoxel(31,30,39);
	caveiraOP.putVoxel(31,31,39);
	caveiraOP.putVoxel(34,27,39);
	caveiraOP.putVoxel(34,33,39);
	caveiraOP.putVoxel(33,27,39);
	caveiraOP.putVoxel(33,33,39);
	
	//nariz:
	caveiraOP.cutVoxel(28,26,39);
	caveiraOP.cutVoxel(29,26,39);
	caveiraOP.cutVoxel(30,26,39);
	caveiraOP.putVoxel(28,26,39);
	caveiraOP.putVoxel(29,26,39);
	caveiraOP.putVoxel(30,26,39);
	caveiraOP.putVoxel(28,25,39);
	caveiraOP.putVoxel(29,25,39);
	caveiraOP.putVoxel(30,25,39);
	caveiraOP.putVoxel(27,25,39);
	caveiraOP.putVoxel(31,25,39);
	caveiraOP.putVoxel(28,24,39);
	caveiraOP.putVoxel(29,24,39);
	caveiraOP.putVoxel(30,24,39);
	
	
	//boca:
	caveiraOP.cutVoxel(29,22,34);
	caveiraOP.cutVoxel(29,21,34);
	caveiraOP.cutVoxel(29,20,34);
	
	caveiraOP.cutVoxel(29,22,35);
	caveiraOP.cutVoxel(29,21,35);
	caveiraOP.cutVoxel(29,20,35);
	
	caveiraOP.cutVoxel(29,19,34);
	caveiraOP.cutVoxel(29,18,34);
	
	caveiraOP.putVoxel(29,22,34);
	caveiraOP.putVoxel(29,21,34);
	caveiraOP.putVoxel(29,20,34);
	caveiraOP.putVoxel(29,19,34);
	caveiraOP.putVoxel(29,18,34);
	
	caveiraOP.cutVoxel(28,20,34);
	caveiraOP.cutVoxel(28,20,35);
	caveiraOP.cutVoxel(27,20,35);

	caveiraOP.cutVoxel(30,20,34);
	caveiraOP.cutVoxel(30,20,35);
	caveiraOP.cutVoxel(31,20,35);
	
	caveiraOP.cutVoxel(28,20,34);
	caveiraOP.cutVoxel(28,20,35);
	caveiraOP.cutVoxel(27,20,35);

	caveiraOP.putVoxel(30,20,34);
	caveiraOP.putVoxel(31,20,34);
	
	caveiraOP.putVoxel(28,20,34);
	caveiraOP.putVoxel(27,20,34);
	
	caveiraOP.cutVoxel(26,21,34);
	caveiraOP.putVoxel(26,21,34);
	caveiraOP.putVoxel(25,21,34);
	caveiraOP.cutVoxel(27,22,35);
	caveiraOP.putVoxel(27,22,35);
	caveiraOP.cutVoxel(28,22,35);
	caveiraOP.putVoxel(28,22,35);
	
	caveiraOP.cutVoxel(27,18,34);
	caveiraOP.putVoxel(27,18,34);
	caveiraOP.cutVoxel(28,18,34);
	caveiraOP.putVoxel(28,18,34);
	
	caveiraOP.cutVoxel(32,21,34);
	caveiraOP.putVoxel(32,21,34);
	caveiraOP.putVoxel(33,21,34);
	
	caveiraOP.cutVoxel(30,22,35);
	caveiraOP.putVoxel(30,22,35);
	caveiraOP.cutVoxel(31,22,35);
	caveiraOP.putVoxel(31,22,35);
	
	caveiraOP.cutVoxel(30,18,34);
	caveiraOP.putVoxel(30,18,34);
	caveiraOP.cutVoxel(31,18,34);
	caveiraOP.putVoxel(31,18,34);
	
	caveiraOP.cutVoxel(26,22,35);
	caveiraOP.cutVoxel(26,22,34);
	caveiraOP.putVoxel(26,22,34);
	caveiraOP.cutVoxel(26,20,34);
	caveiraOP.putVoxel(26,20,34);
	caveiraOP.putVoxel(26,19,34);
	caveiraOP.putVoxel(26,18,34);
	
	caveiraOP.cutVoxel(32,22,35);
	caveiraOP.cutVoxel(32,22,34);
	caveiraOP.putVoxel(32,22,34);
	caveiraOP.cutVoxel(32,20,34);
	caveiraOP.putVoxel(32,20,34);
	caveiraOP.putVoxel(32,19,34);
	caveiraOP.putVoxel(32,18,34);
	
	caveiraOP.putBox(5,55,5,55,8,10); //'bandeira 3d'
	
  caveiraOP.writeOFF((char*)"caveiraOnePiece.off");


}