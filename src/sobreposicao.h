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
    Arquivo .h relacionado a verificacao de sobreposicoes entre formas
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

/// @brief Compara se ha colisao entre duas bounding boxes
/// @param aa A primeira bounding box
/// @param bb A segunda bounding box
/// @return Retorna 1 se ha a colisao, e 0 caso contrario
int ColisaoDeBoxes(BoundingBox aa, BoundingBox bb);

#endif