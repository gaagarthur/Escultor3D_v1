#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP

/**
 * @brief A estrutura de dados Voxel guarda as propriedades de um voxel.
 *
 */
struct Voxel {
    float r,g,b; // Cores
    float a; // Trasnparencia
    bool show; // Incluido ou nao
};

/**
* A classe Sculptor é utilizada para criar e manipular matrizes 3D de voxels.
* ============================================================================
*/
class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
public:
/**
* Construtor Sculptor() cria uma matriz de Voxels
* ---------------------------------------------
* @details Aloca  dinamicamente  uma  matriz 3D  de  Voxels com tamanho (_nx x _ny x _nz)
* @details e atribui, para cada um dos Voxels, valor de "desligado" (show = false).
* @param _nx :Comprimento na dimesão __X__ da matriz de Voxels
* @param _ny :Comprimento na dimesão __Y__ da matriz de Voxels
* @param _nz :Comprimento na dimesão __Z__ da matriz de Voxels
* #### Exemplo:
* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
* #include "sculptor.hpp"
*
* int main(void){
*    Sculptor escultura(20, 20, 20);
*    //Cria matriz de voxels de 20x20x20
* }
* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
    Sculptor(int _nx, int _ny, int _nz);
/**
 * Destrutor:
 * ----------
 * @details Libera a memória alocada com o construtor.
 */
    ~Sculptor();
    /**
     *  O método setColor serve para selecionar cor de desenho.
     *  --------
     * @details O método  setColor()  recebe  três cores  bases em formato rgb e um valor
     * @details de transparência da para ajustar a cor do voxel(s) a ser(em) desenhados.
     * @param  r representa o quanto da cor **vermelha** está presente na tonalidade desejada. Faixa: **[0.0 à 1.0]**
     * @param g representa o quanto da cor **verde** está presente na tonalidade desejada. Faixa: **[0.0 à 1.0]**
     * @param b representa o quanto da cor **azul** está presente na tonalidade desejada. Faixa: **[0.0 à 1.0]**
     * @param a representa a opacidade da tonalidade desejada. Faixa: **[0.0 à 1.0]**
     * #### Exemplo:
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
     * #include "sculptor.hpp"
     *
     * int main(void){
     *    Sculptor escultura(20, 20, 20);
     *    escultura.setColor(1.0, 0.0, 0.0, 0.5);
     *    //no setColor foi selecionada a cor vermelha
     *    // com opacidade de 50%.
     * }
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     */
    void setColor(float r, float g, float b, float a);
    /**
     * O método putVoxel "Liga" um único voxel nas coordenadas (x,y,z).
     * --------
     * @details Na matriz, nas coodenadas (x, y, z), são acessadas as
     * @details propriedas do voxel onde é feito show = true e o voxel
     * @details é pintado com a cor definida no setColor()
     * #### Exemplo:
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
     * #include "sculptor.hpp"
     *
     * int main(void){
     *    Sculptor escultura(20, 20, 20);
     *    escultura.setColor(1.0, 0.0, 0.0, 1.0);
     *    escultura.putVoxel(5, 4, 3);
     *    // ligado um voxel vermelho opaco
     *    // nas coordenadas (5, 4, 3)
     *
     * }
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     *
     */
    void putVoxel(int x, int y, int z);
    /**
     * O método cutVoxel "Liga" um único voxel nas coordenadas (x,y,z).
     * ---------
     * @details Na matriz, nas coodenadas (x, y, z), são acessadas as
     * @details propriedas do voxel onde é feito show = false.
     * #### Exemplo:
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
     * #include "sculptor.hpp"
     *
     * int main(void){
     *    Sculptor escultura(20, 20, 20);
     *    escultura.setColor(0.3, 0.9, 0.2, 1.0);
     *    escultura.putVoxel(6, 10, 4);
     *    escultura.cutVoxel(6, 10, 4);
     *    // Desligado um voxel em (6, 10, 4)
     *
     * }
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     */
    void cutVoxel(int x, int y, int z);
    /**
     * O método putBox "Liga" todos os voxels nas coordenadas pertencentes a um paralelepípedo retângulo.
     * ---------
     * @details Para formar um paralelepípedo são passados como parâmetrosseis valores
     * inteiros. Esses correspondem as coordenadas de dois
     * vértices opostos do paralelepípedo (o mais perto e o mais lonje da origem).
     * #### Exemplo:
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
     * #include "sculptor.hpp"
     *
     * int main(void){
     *    Sculptor escultura(10, 10, 10);
     *    escultura.setColor(1.0, 0.0, 0.0, 1.0);
     *    escultura.putBox(0,4,0,2,0,1);
     *    // ligado um paralelepipedo de voxels
     *    // que tem um vertice em (0, 0, 0)
     *    // e um oposto em (4,2,1)
     *
     * }
     * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     * #### paralelepipedo criado:
     * ![](putbox.png)
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * O método cutbox "Desliga" todos os voxels nas coordenadas pertencentes a um paralelepípedo retângulo.
     * ----------------
     * @details O cutBox() recebe valores da mesma forma que o método putBox()
     * porém ao invés de ligar os voxels ele os desativa.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /*void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  */
    void writeOFF(const char* filename);
};


#endif
