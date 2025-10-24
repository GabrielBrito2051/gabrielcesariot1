#ifndef boundingbox_h
#define boundingbox_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

/*
    Arquivo .h relacionado a verificacao de sobreposicoes entre formas na arena
*/

typedef void* BoundingBox;

/// @brief Cria uma nova bounding box, retangulo que circunscreve as formas
/// @param x A coordenada x da ancora da box
/// @param y A coordenada y da ancora da box
/// @param w A largura da box
/// @param h A altura da box
/// @return Retorna o ponetiro para a bounding box criada
BoundingBox criarBox(double x, double y, double w, double h);

/// @brief Calcula as dimensoes da bounding box para ficar compativel com um retangulo. Os valores sao passados e alterados por referencia
/// @param r O retangulo
/// @param x A coordenada x da ancora da box
/// @param y A coordenada y da ancora da box
/// @param w A largura da box
/// @param h A altura da box
void calculaBoxRetangulo(Retangulo r, double* x, double* y, double* w, double* h);

/// @brief Calcula as dimensoes da bounding box para ficar compativel com um circulo. Os valores sao passados e alterados por referencia
/// @param c 
/// @param x A coordenada x da ancora da box
/// @param y A coordenada y da ancora da box
/// @param w A largura da box
/// @param h A altura da box
void calculaBoxCirculo(Circulo c, double* x, double* y, double* w, double* h);

/// @brief Calcula as dimensoes da bounding box para ficar compativel com uma linha. Os valores sao passados e alterados por referencia
/// @param l 
/// @param x A coordenada x da ancora da box
/// @param y A coordenada y da ancora da box
/// @param w A largura da box
/// @param h A altura da box
void calculaBoxLinha(Linha l, double* x, double* y, double* w, double* h);

/// @brief Calcula as dimensoes da bounding box para ficar compativel com um texto. Os valores sao passados e alterados por referencia
/// @param t 
/// @param x A coordenada x da ancora da box
/// @param y A coordenada y da ancora da box
/// @param w A largura da box
/// @param h A altura da box
void calculaBoxTexto(Texto t, double* x, double* y, double* w, double* h);

/// @brief Pega a coordenada x da ancora da box
/// @param bb A bounding box
double getXbox(BoundingBox bb);

/// @brief Pega a coordenada y da ancora da bounding box
/// @param bb A bounding box
double getYbox(BoundingBox bb);

/// @brief Pega a largura da bounding box
/// @param bb A bounding box
double getWbox(BoundingBox bb);

/// @brief Pega a altura da bounding box
/// @param bb A bounding box
double getHbox(BoundingBox bb);

/// @brief Calcula a distancia entre dois pontos
/// @param x1 Coordenada x do primeiro ponto
/// @param x2 Coordenada x do segundo ponto
/// @param y1 Coordenada y do primeiro ponto
/// @param y2 Coordenada y do segundo ponto
/// @return Retorna a distancia entre os dois pontos
double distEntrePontos(double x1, double x2, double y1, double y2);

/// @brief Cria e retorna a bounding box para qualquer forma generica
/// @param f1 A forma que tera sua box criada
/// @return Retornao ponteiro para a box criada
BoundingBox getBOXforma(Pacote f1);

/// @brief Verifica se ha sobreposicao entre dois circulos
/// @param c1 O primeiro circulo
/// @param c2 O segundo circulo
/// @return Retorna 1 se ha a sobreposicao e 0 caso contrario
int colisaoCC(Pacote c1, Pacote c2);

/// @brief Funcao para "prender" um calor entre um minimo e um maximo
/// @param valor O valor que se deseja prender
/// @param min O valor minimo
/// @param max O valor maximo
/// @return Retorna um valor entre o minimo e maximo (inclusos)
double clamp(double valor, double min, double max);

/// @brief Verifica se ha sobreposicao entre um circulo e um retangulo
/// @param c O circulo
/// @param r O retuangulo
/// @return  Retorna 1 se ha a sobreposicao e 0 caso contrario
int colisaoCR(Pacote c, Pacote r);

/// @brief Verifica se existe sobreposicao entre um circulo e uma linha
/// @param c O circulo
/// @param l A linha
/// @return  Retorna 1 se ha a sobreposicao e 0 caso contrario
int colisaoCL(Pacote c, Pacote l);

/// @brief Verifica se ha sobreposicao entre um retangulo e uma linha
/// @param r O retangulo
/// @param l A linha
/// @return  Retorna 1 se ha a sobreposicao e 0 caso contrario
int colisaoRL(Pacote r, Pacote l);

/// @brief Verifica se ha colisao entre duas linhas(textos inclusos)
/// @param l1 A primeira linha
/// @param l2 a segunda linha
/// @return Retorna 1 se ha sobreposicao e 0 caso contrario
int colisaoLL(Pacote l1, Pacote l2);

/// @brief Compara se ha colisao entre duas bounding boxes
/// @param aa A primeira bounding box
/// @param bb A segunda bounding box
/// @return Retorna 1 se ha a colisao, e 0 caso contrario
int ColisaoDeBoxes(BoundingBox aa, BoundingBox bb);

/// @brief Verifica a sobreposicao das formas caso suas bounding boxes estejam sobrepostas
/// @param f1 A primeira forma
/// @param f2 A segunda forma
/// @return Retorna 1 se houver a sobreposicao e 0 caso contrario
int verificaColisaoFormas(Pacote f1, Pacote f2);

/// @brief Funcao que engloba as funcoes de verificar a colisao de boxes e colisao das formas em si
/// @param f1 A primeira forma
/// @param f2 A segunda forma
/// @return Retorna 1 se houver a sobreposicao e 0 caso contrario
int verifica_sobreposicao(Pacote f1, Pacote f2);

#endif