#include "sculptor.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>


Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx; // lenght
    ny = _ny; // width
    nz = _nz; // height

    //----------------------------- Alocar para matriz 3d ------------------------------------
    v = new Voxel **[nx]; // matriz de tamanho nx para guardar ponteiro para faces
    v[0] = new Voxel *[nx * ny];// matriz de tamanho nx*ny para guardar ponteiro para linhas
    v[0][0] = new Voxel[nx * ny * nz];// matriz de tamanho nx*ny*nz para guardar voxels

    //--------------------------------- Fixar Ponteiros --------------------------------------
    for(int i=1; i<nx; i++){
        v[i] = v[i-1]+ny;

        for(int j=1; j<(nx*ny); j++){
            v[0][j] = v[0][j-1]+nz;

        }
    }
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                v[i][j][k].show = false;

            }
        }
    }

}

//----------------------------- Escolha da cor do voxel ----------------------------------
void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
//--------------------------------- Criar UM Voxel ---------------------------------------
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].show = true; // "Ligar" voxel nas coordenadas x y z
    v[x][y][z].a = a; // transparencia do voxel opaco
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;

}
//--------------------------------- Apagar UM Voxel ---------------------------------------
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false; // "Desligar" voxel nas coordenadas x y z
}
//------------------------ Criar um Paralelepipedo de Voxels ------------------------------

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    int DX = (x1-x0), DY = (y1-y0), DZ = (z1-z0); //indices (deltas) para os loops
    int indX, indY, indZ;//indices da matrix 3D

    for(int i=0; i<=DX; i++){
        for(int j=0; j<=DY; j++){
            for(int k=0; k<=DZ;k++){

                indX = (x0+i); indY = (y0+j); indZ = (z0+k);

                v[indX][indY][indZ].show = true; // "Ligar" voxel nas coordenadas x y z
                v[indX][indY][indZ].a = a; // transparencia do voxel opaco
                v[indX][indY][indZ].r = r;
                v[indX][indY][indZ].g = g;
                v[indX][indY][indZ].b = b;

            }
        }
    }
}
//----------------------- Apagar um Paralelepipedo de Voxels ------------------------------

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    int DX = (x1-x0), DY = (y1-y0), DZ = (z1-z0); //indices (deltas) para os loops
    int indX, indY, indZ; //indices da matrix 3D

    for(int i=0; i<=DX; i++){
        for(int j=0; j<=DY; j++){
            for(int k=0; k<=DZ;k++){

                indX = (x0+i); indY = (y0+j); indZ = (z0+k);
                v[indX][indY][indZ].show = false; // "Desligar" voxel nas coordenadas indx indy indz
            }
        }
    }
}
//------------------------------ Cria uma esfera de Voxels ---------------------------------
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    int indX, indY, indZ, powX, powY, powZ;
    int powR=(radius*radius),Dia=(2*radius);

    for(int i=0; i<=Dia; i++){
        for(int j=0; j<=Dia; j++){
            for(int k=0; k<=Dia;k++){

                indX = (xcenter-radius+i);
                indY = (ycenter-radius+j);
                indZ = (zcenter-radius+k);
                powX=((indX-xcenter)*(indX-xcenter));
                powY=((indY-ycenter)*(indY-ycenter));
                powZ=((indZ-zcenter)*(indZ-zcenter));
                if(radius>3){
                if(powX+powY+powZ< powR){
                    v[indX][indY][indZ].show = true; // "Ligar" voxel nas coordenadas x y z
                    v[indX][indY][indZ].a = a; // transparencia do voxel opaco
                    v[indX][indY][indZ].r = r;
                    v[indX][indY][indZ].g = g;
                    v[indX][indY][indZ].b = b;
                }
                }else{
                    if(powX+powY+powZ<= powR){
                        v[indX][indY][indZ].show = true; // "Ligar" voxel nas coordenadas x y z
                        v[indX][indY][indZ].a = a; // transparencia do voxel opaco
                        v[indX][indY][indZ].r = r;
                        v[indX][indY][indZ].g = g;
                        v[indX][indY][indZ].b = b;
                    }
                }
            }
        }
    }
}
//------------------------------ Apagar uma esfera de Voxels ---------------------------------
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int indX, indY, indZ, powX, powY, powZ;
    int powR=(radius*radius),Dia=(2*radius);

    for(int i=0; i<=Dia; i++){
        for(int j=0; j<=Dia; j++){
            for(int k=0; k<=Dia;k++){

                //(indX-xcenter)^2+(indY-ycenter)^2+(indZ-zcenter)^2= r^2
                indX = (xcenter-radius+i);
                indY = (ycenter-radius+j);
                indZ = (zcenter-radius+k);
                powX=((indX-xcenter)*(indX-xcenter));
                powY=((indY-ycenter)*(indY-ycenter));
                powZ=((indZ-zcenter)*(indZ-zcenter));

                if(radius>3){
                    if(powX+powY+powZ< powR){
                        v[indX][indY][indZ].show = false; // "Desigar" voxel nas coordenadas x y z
                    }
                }else{
                    if(powX+powY+powZ<= powR){
                        v[indX][indY][indZ].show = false; // "Desigar" voxel nas coordenadas x y z
                    }
                }
            }
        }
    }

}

//----------------------------- Escrever no Documento .off ---------------------------------
void Sculptor::writeOFF(const char* filename){

    std::ofstream fout;
    fout.open(filename);
    fout << "OFF" << std::endl;
    //------------- contar quantos voxels serao exibidos----------------------------
    int NumVox = 0;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if (v[i][j][k].show == true){
                    NumVox++;
                }
            }
        }
    }
    //----------------------- Escrever # de vertices e faces -------------------------
    fout << (8*NumVox) << " " << (6*NumVox) << " " << 0 << std::endl;
    //--------------------- ponto flutuante com 2 casa decimais ----------------------
    fout << std::fixed<< std::setprecision(2);
    //------------------------------ posicao dos voxels ------------------------------
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show == true){
                    fout << (-0.5+i) << " " << (0.5+j) << " " << (-0.5+k) << std::endl;
                    fout << (-0.5+i) << " " << (-0.5+j) << " " << (-0.5+k) << std::endl;
                    fout << (0.5+i) << " " << (-0.5+j) << " " << (-0.5+k) << std::endl;
                    fout << (0.5+i) << " " << (0.5+j) << " " << (-0.5+k) << std::endl;
                    fout << (-0.5+i) << " " << (0.5+j) << " " << (0.5+k) << std::endl;
                    fout << (-0.5+i) << " " << (-0.5+j) << " " << (0.5+k) << std::endl;
                    fout << (0.5+i) << " " << (-0.5+j) << " " << (0.5+k) << std::endl;
                    fout << (0.5+i) << " " << (0.5+j) << " " << (0.5+k) << std::endl;
                }
            }
        }
    }

    fout<<std::endl;

    int NumPasses = 0, inc = 0;//inc = increment
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){

                float _r = v[i][j][k].r , _g = v[i][j][k].g, _b = v[i][j][k].b, _a = v[i][j][k].a;

                if(v[i][j][k].show == true){
                    inc = NumPasses*8;
                    fout << 4 << " " << (0+(inc)) << " " << (3+(inc)) << " " <<(2+(inc)) <<
                        " " << (1+(inc)) << " " << _r << " " << _g << " " << _b << " " << _a << std::endl;
                    fout << 4 << " " << (4+(inc)) << " " << (5+(inc)) << " " <<(6+(inc)) <<
                        " " << (7+(inc)) << " " << _r << " " << _g << " " << _b << " " << _a << std::endl;
                    fout << 4 << " " << (0+(inc)) << " " << (1+(inc)) << " " <<(5+(inc)) <<
                        " " << (4+(inc)) << " " << _r << " " << _g << " " << _b << " " << _a << std::endl;
                    fout << 4 << " " << (0+(inc)) << " " << (4+(inc)) << " " <<(7+(inc)) <<
                        " " << (3+(inc)) << " " << _r << " " << _g << " " << _b << " " << _a << std::endl;
                    fout << 4 << " " << (7+(inc)) << " " << (6+(inc)) << " " <<(2+(inc)) <<
                        " " << (3+(inc)) << " " << _r << " " << _g << " " << _b << " " << _a << std::endl;
                    fout << 4 << " " << (1+(inc)) << " " << (2+(inc)) << " " <<(6+(inc)) <<
                        " " << (5+(inc)) << " " << _r << " " << _g << " " << _b << " " << _a << std::endl;
                    NumPasses++;
                }
            }
        }
    }
    fout.close();
}

Sculptor::~Sculptor(){
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}
