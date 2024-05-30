#include <iostream>
#include "sculptor.hpp"

#include<ctime>

int main(void){

    Sculptor santa(64, 64, 64);

    santa.setColor(1.0, 1.0, 1.0, 1.0);
    santa.putBox(0,63,0,63,0,63);
    santa.cutBox(1,62,0,63,1,62);
    santa.cutBox(0,63,1,62,1,62);
    santa.cutBox(1,62,1,62,0,63);
// axis
    santa.setColor(1.0, 0.0, 0.0, 1.0);// x axis
    for(int i=1;i<5;i++){santa.putVoxel(i,0,0);}
    santa.setColor(0.0, 1.0, 0.0, 1.0);// y axis
    for(int i=1;i<5;i++){santa.putVoxel(0,i,0);}
    santa.setColor(0.0, 0.0, 1.0, 1.0);// z axis
    for(int i=1;i<5;i++){santa.putVoxel(0,0,i);}

//teste----------
    std::srand(std::time(0));
    santa.setColor(0.83, 0.94, 0.94, 0.80);
    for(int i=0; i<64; i++){
        for(int j=0; j<64; j++){
            for(int k=0; k<64; k++){
                if((rand()%300)%150==0){
                    santa.putVoxel(i,j,k);
                }
            }
        }
    }
// Piso
    santa.setColor(0.78, 0.49, 0.31, 0.4);
    santa.putBox(1,62,1,62,0,1);
// footboard
    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putBox(1,62,1,62,2,6);
    santa.cutBox(2,61,1,61,2,6);
// Wall
    /*santa.setColor(0.52, 0.98, 1.0, 1.0);
    santa.putBox(0,0,1,62,1,62);
    santa.putBox(63,63,1,62,1,62);
    santa.putBox(1,62,63,63,1,62);
    */

//presents
    santa.setColor(0.90, 0.25, 0.25, 1.0);
    santa.putBox(4,15,5,12,2,6);

    santa.setColor(1.0, 0.8, 0.2, 1.0);
    santa.putBox(4,15,8,9,2,6);
    santa.putBox(9,10,5,12,2,6);



//hat

    santa.setColor(0.90, 0.25, 0.25, 1.0);
    santa.putSphere(30,29,53,7);
    santa.putSphere(33,29,53,7);
    santa.putSphere(30,30,53,7);
    santa.putSphere(33,30,53,7);
    santa.cutBox(22,43,20,40,46,51);

    santa.setColor(0.90, 0.25, 0.25, 1.0);
    santa.putSphere(35,30,56,5);
    santa.putSphere(38,31,54,5);
    santa.cutSphere(36,31,50,5);
    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putSphere(42,31,49,3);

    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putBox(23,40,22,37,52,53);
    santa.cutBox(23,24,22,23,52,53);
    santa.cutBox(23,23,24,24,52,53);
    santa.cutBox(25,25,22,22,52,53);

    santa.cutBox(23,24,36,37,52,53);
    santa.cutBox(23,23,35,35,52,53);
    santa.cutBox(25,25,37,37,52,53);

    santa.cutBox(39,40,22,23,52,53);
    santa.cutBox(38,38,22,22,52,53);
    santa.cutBox(40,40,24,24,52,53);

    santa.cutBox(39,40,36,37,52,53);
    santa.cutBox(38,38,37,37,52,53);
    santa.cutBox(40,40,35,35,52,53);

// Pernas
    santa.setColor(0.90, 0.25, 0.25, 1.0);
    santa.putBox(21,26,28,33,2,15);
    santa.putBox(37,42,28,33,2,15);

// Sapato
    santa.setColor(0.16, 0.14, 0.14, 1.0);
    santa.putBox(21,26,25,33,2,5);
    santa.putBox(37,42,25,33,2,5);
    santa.cutBox(21,26,30,31,2,2);
    santa.cutBox(37,42,30,31,2,2);
    santa.cutBox(21,26,31,31,3,3);
    santa.cutBox(37,42,31,31,3,3);

// Meia
    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putBox(20,27,27,34,6,7);
    santa.putBox(36,43,27,34,6,7);

// Corpo
    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putBox(31,32,20,22,15,39);//faixa branca
    santa.setColor(0.90, 0.25, 0.25, 1.0);//cor
    santa.putBox(20,43,23,38,15,40);//main
    santa.putBox(21,42,24,37,41,41);
    santa.putBox(23,40,21,22,15,38);//frente
    santa.putBox(19,19,26,37,15,38);//direito
    santa.putBox(44,44,26,37,15,38);//esquedo
    santa.putBox(21,42,39,39,15,38);//tras
// Cinto
    santa.setColor(0.16, 0.14, 0.14, 1.0);
    santa.putBox(22,41,20,22,18,21);//frente
    santa.putBox(20,43,38,40,18,21);//tras
    santa.putBox(18,20,26,38,18,21);//ireita
    santa.putBox(43,45,26,38,18,21);//esquerda
    santa.putBox(19,21,22,25,18,21);//rente direita
    santa.putBox(42,44,22,25,18,21);//frente esquerda
    santa.setColor(1.0, 0.8, 0.2, 1.0);
    santa.putBox(29,34,19,19,18,21);//fivela
    santa.cutBox(30,33,19,19,19,20);//fivela

// Rosto
    santa.setColor(1.0, 0.79, 0.73, 1.0);
    santa.putSphere(31,29,49,7);//cabeca
    santa.putSphere(32,29,49,7);
    santa.putBox(29,34,27,31,42,44);//neck
    santa.cutSphere(31,29,49,6);//cabeca Cut
    santa.cutSphere(32,29,49,6);
    santa.setColor(1.0, 0.67, 0.58, 1.0);
    santa.putSphere(28,23,48,1);//bochecha
    santa.putSphere(35,23,48,1);
    santa.cutVoxel(28,22,48);
    santa.cutVoxel(35,22,48);
    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putSphere(29,23,49,1);//olho
    santa.putSphere(34,23,49,1);
    santa.cutVoxel(29,22,49);
    santa.cutVoxel(34,22,49);
    santa.setColor(0.36, 0.74, 1.0, 1.0);
    santa.putVoxel(29,23,49);//pupila
    santa.putVoxel(34,23,49);
    santa.setColor(1.0, 0.69, 0.60, 1.0);
    santa.putSphere(31,21,48,1);//nariz
    santa.putSphere(32,21,48,1);
    santa.setColor(0.83, 0.94, 0.94, 1.0);
    santa.putBox(31,32,22,26,41,47);//barba
    santa.putBox(30,33,22,26,42,48);
    santa.putBox(29,34,22,26,43,48);
    santa.putBox(28,35,23,26,44,46);
    santa.putBox(27,36,24,26,45,46);
    santa.setColor(0.96, 0.80, 0.84, 1.0);
    santa.setColor(0.16, 0.14, 0.14, 1.0);
    santa.putBox(31,32,22,22,44,45);
//Arm
    santa.setColor(0.90, 0.25, 0.25, 1.0);
    for(int i=0; i<6; i++){
        int x=0, z=0;
        x=i+43;
        z=36-(i*3);
        santa.putBox(x,x+3,28,34,z,z+5);

    }
    for(int i=0; i<6; i++){
        int x=0, z=0;
        x=17-i;
        z=36-(i*3);
        santa.putBox(x,x+3,28,34,z,z+5);

    }
//glove
    santa.setColor(0.16, 0.14, 0.14, 1.0);
    santa.putBox(11,15,27,35,16,21);
    santa.putBox(11,15,27,35,16,21);

//tree
    santa.setColor(0.36, 0.26, 0.22, 1.0);
    santa.putBox(49,52,49,52,1,15);
    santa.setColor(0.06, 0.50, 0.06, 1.0);
    santa.putBox(42,59,42,59,10,15);
    santa.putBox(44,57,44,57,16,20);
    santa.putBox(46,55,46,55,21,27);
    santa.putBox(48,53,48,53,28,35);
    santa.putBox(50,51,50,51,36,43);

// Cut otimizar
    santa.cutBox(21,42,24,37,16,19);//cut
    santa.cutBox(22,25,29,32,2,15);//deixar perna oca
    santa.cutBox(38,41,29,32,2,15);//deixar perna oca


    santa.writeOFF("santa.off");

}
