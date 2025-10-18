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

BoundingBox getBOXforma(Forma f1){
    double x, y, w, h;
    tipoforma tipo = getTipoForma(f1);
    if(tipo==tipo_circulo){
        calculaBoxCirculo((Circulo)f1, &x, &y, &w, &h);
    }

    else if(tipo == tipo_retangulo){
        calculaBoxRetangulo((Retangulo)f1, &x, &y, &w, &h);
    }

    else if(tipo == tipo_linha){
        calculaBoxLinha((Linha)f1, &x, &y, &w, &h);
    }

    else if(tipo == tipo_texto){
        calculaBoxTexto((Texto)f1, &x, &y, &w, &h);
    }

    return criarBox(x, y, w, h);
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

int colisaoCC(Circulo c1, Circulo c2){
    double r1, r2, distRaios, x1, y1, x2, y2;
    r1 = getRcirculo(c1);
    r2 = getRcirculo(c2);
    distRaios = r1 + r2;
    x1 = getXcirculo(c1);
    y1 = getYcirculo(c1);
    x2 = getXcirculo(c2);
    y2 = getYcirculo(c2);
    distRaios = distRaios * distRaios;
    double distCentros = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    if(distCentros > distRaios){
        return 0;
    }else{
        return 1;
    }
}

double clamp(double valor, double min, double max){
    if (valor < min) return min;
    if(valor > max) return max;
    return valor;
}

int colisaoCR(Circulo c, Retangulo r){
    double  cx = getXcirculo(c), cy = getYcirculo(c), cr = getRcirculo(c);
    double rx = getXretangulo(r), ry = getYretangulo(r), rw = getWretangulo(r), rh = getHretangulo(r);

    double maisPertox = clamp(cx, rx, rx + rw);
    double maisPertoy = clamp(cy, ry, ry + rh);

    double distX = cx - maisPertox;
    double distY = cy - maisPertoy;
    double distQuadrada = (distX * distX) + (distY * distY);

    if(distQuadrada > cr * cr){
        return 0;
    }else{
        return 1;
    }
}

int colisaoCL(Circulo c, Linha l){
    double  cx = getXcirculo(c), cy = getYcirculo(c), cr = getRcirculo(c);
    double x1, y1, x2, y2;
    getSegmentoLinha(l,&x1, &y1, &x2, &y2);
    double vetorx = x2 - x1;
    double vetory = y2 - y1;
    double tamanhovet = vetorx * vetorx + vetory * vetory;

    if(tamanhovet<epsilon){
        double dist = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
        if(dist > cr * cr){
            return 0;
        }else{
            return 1;
        }
    }
    double t = ((cx - x1) * vetorx + (cy - y1) * vetory) / tamanhovet;
    double t_clamp = clamp(t, 0.0, 1.0);
    double pontox = x1 + t_clamp * vetorx;
    double pontoy = y1 + t_clamp * vetory;
    double distx = cx - pontox;
    double disty = cy - pontoy;
    double dist = distx * distx + disty * disty;

    if(dist > cr * cr){
        return 0;
    }else{
        return 1;
    }
}

int colisaoRL(Retangulo r, Linha l){
    double rx = getXretangulo(r), ry = getYretangulo(r), rw = getWretangulo(r), rh = getHretangulo(r);
    double x1, y1, x2, y2;
    getSegmentoLinha(l, &x1, &y1, &x2, &y2);
    double dx = x2 - x1;
    double dy = y2 - y1;
    double t_min = 0.0, t_max = 1.0;

    if(fabs(dx)<epsilon){
        if(x1<rx || x1>rx + rw){
            return 0;
        }
    }else{
        double t_esquerdo = (rx - x1) / dx;
        double t_direito = (rx + rw -x1) / dx;
        double t_in_x = fmin(t_esquerdo, t_direito);
        double t_out_x = fmax(t_esquerdo, t_direito);
        t_min = fmax(t_min, t_in_x);
        t_max = fmin(t_max, t_out_x);
    }

    if(fabs(dy)<epsilon){
        if(y1<ry || y1 > ry + rh){
            return 0;
        }
    }else{
        double t_piso = (ry - y1) / dy;
        double t_teto = (ry + rh - y1) / dy;
        double t_in_y = fmin(t_piso, t_teto);
        double t_out_y = fmax(t_piso, t_teto);
        t_min = fmax(t_min, t_in_y);
        t_max = fmin(t_max, t_out_y);
    }

    if(t_min>t_max){
        return 0;
    }else{
        return 1;
    }
}

int colisaoLL(Linha l1, Linha l2){
    double x1, y1, x2, y2, x3, y3, x4, y4;
    getSegmentoLinha(l1, &x1, &y1, &x2, &y2);
    getSegmentoLinha(l2, &x3, &y3, &x4, &y4);
    double dx1 = x2 - x1, dy1 = y2 - y1, dx2 = x4- x3, dy2 = y4- y3;
    double denominador = (dx1 * dy2) - (dy1* dx2);
    if(fabs(denominador)<epsilon){
        return 0;
    }
    double t_num = (x3 - x1) * dy2 - (y3 - y1) * dx2;
    double u_num = (x3 - x1) * dy1 - (y3 - y1) * dx1;
    double t = t_num / denominador;
    double u = u_num / denominador;
    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        return 1;
    }
    return 0;
}

int verificaColisaoFormas(Forma f1, Forma f2){
    tipoforma tipo1 = getTipoForma(f1);
    tipoforma tipo2 = getTipoForma(f2);

    if (tipo1 == tipo_texto){
        tipo1 = tipo_linha;
    }
    if(tipo2 == tipo_texto){
        tipo2 = tipo_linha;
    }

    if(tipo1 == tipo_circulo && tipo2 == tipo_circulo){
        return colisaoCC(f1, f2);
    }

    else if(tipo1 == tipo_retangulo && tipo2 == tipo_retangulo){
        return 1;
    }

    else if(tipo1 == tipo_linha && tipo2 == tipo_linha){
        return colisaoLL(f1, f2);
    }

    else if(tipo1 == tipo_circulo && tipo2 == tipo_retangulo){
        return colisaoCR(f1, f2);
    }

    else if(tipo1 == tipo_retangulo && tipo1 == tipo_circulo){
        return colisaoCR(f2, f1);
    }

    else if(tipo1 == tipo_circulo && tipo2 == tipo_linha){
        return colisaoCL(f1, f2);
    }

    else if(tipo1 == tipo_linha && tipo2 == tipo_circulo){
        return colisaoCL(f2, f1);
    }

    else if(tipo1 == tipo_retangulo && tipo2 == tipo_linha){
        return colisaoRL(f1, f2);
    }
    
    else if(tipo1 == tipo_linha && tipo2 == tipo_retangulo){
        return colisaoRL(f2, f1);
    }

}

int verifica_sobreposicao(Forma f1, Forma f2){
    BoundingBox box1 = getBOXforma(f1);
    BoundingBox box2 = getBOXforma(f2);

    int colisao = ColisaoDeBoxes(box1, box2);

    free(box1);
    free(box2);

    if(colisao == 0){
        return 0;
    }

    return verificaColisaoFormas(f1, f2);
}