#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sobreposicao.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

#define epsilon 0.00001

typedef struct{
    double x, y, w, h;
}boundingbox;

BoundingBox criarBox(double x, double y, double w, double h){
    boundingbox *bb = malloc(sizeof(boundingbox));
    bb->x = x;
    bb->y = y;
    bb->w = w;
    bb->h =h;
    return ((boundingbox*)bb);
}

void calculaBoxRetangulo(Retangulo r, double* x, double* y, double* w, double* h){
    *x = getXretangulo(r);
    *y = getYretangulo(r);
    *w = getWretangulo(r);
    *h = getHretangulo(r);
}

void calculaBoxCirculo(Circulo c, double* x, double* y, double* w, double* h){
    *x = fabs(getXcirculo(c) - getRcirculo(c));
    *y = fabs(getYcirculo(c) - getRcirculo(c));
    *w = 2 * getRcirculo(c);
    *h = 2 * getRcirculo(c);
}

void calculaBoxLinha(Linha l, double* x, double* y, double* w, double* h){
    double x1, x2, y1, y2;
    x1 = getX1linha(l);
    x2 = getX2linha(l);
    y1 = getY1linha(l);
    y2 = getY2linha(l);

    *x = fmin(x1, x2);
    *y = fmin(y1, y2);
    *w = fabs(x1 - x2);
    *h = fabs(y1 - y2);
}

void calculaBoxTexto(Texto t, double* x, double* y, double* w, double* h){
    double xt = getXtexto(t);
    double yt = getYtexto(t);
    char ancora = getAtexto(t);
    char txto = getTXTOtexto(t);
    int tamanho = strlen(txto);
    double x1, x2;

    if(ancora=="i"){
        x1 = xt;
        x2 = xt + 10*tamanho;
    }

    else if(ancora == "m"){
        x1 = xt - 5 * tamanho;
        x2 = xt + 5 * tamanho;
    }

    else if(ancora == "f"){
        x1 = xt - 10 * tamanho;
        x2 = xt;
    }

    *x = fmin(x1, x2);
    *y = yt;
    *w = fabs(x1 - x2);
    *h = epsilon;
}

double getXbox(BoundingBox bb){
    return (((boundingbox*)bb)->x);
}

double getYbox(BoundingBox bb){
    return (((boundingbox*)bb)->y);
}

double getWbox(BoundingBox bb){
    return (((boundingbox*)bb)->w);
}

double getHbox(BoundingBox bb){
    return (((boundingbox*)bb)->h);
}

int ColisaoDeBoxes(BoundingBox aa, BoundingBox bb){
    boundingbox* a = (boundingbox*) aa;
    boundingbox* b = (boundingbox*) bb;
    int colisaox, colisaoy;

    if(a->x < b->x + b->w && a->x + a->w > b->x){
        colisaox = 1;
    }else{
        colisaox = 0;
    }
    if(a->y < b->y + b->h && a->y + a->h > b->y){
        colisaoy = 1;
    }else{
        colisaoy = 0;
    }

    if(colisaox == 1 && colisaoy == 1){
        return 1;
    }else{
        return 0;
    }
}