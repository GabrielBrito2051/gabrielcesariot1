#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct{
    int i;
    double x, y;
    char *cor, *corcompl, *txto;
    char a;
}texto;

Texto criar_texto(int i, double x, double y, char* cor, char a, char* txto){
    texto *t = malloc(sizeof(texto));
    t->i = i;
    t->x = x;
    t->y = y;
    t->a = a;

    t->cor = (char*)malloc(strlen(cor)+1);
    if(t->cor == NULL){
        printf("Erro ao alocar memoria para a cor do texto");
        exit(1);
    }
    strcpy(t->cor, cor);

    t->corcompl = (char*)malloc(strlen(cor)+1);
    if(t->corcompl == NULL){
        printf("Erro ao alocar memoria para a cor complementar do texto");
        exit(1);
    }
    setCORCOMPLtexto(t);

    return ((texto*)t);
}

int getItexto(Texto t){
    return ((texto*)t)->i;
}

double getXtexto(Texto t){
    return ((texto*)t)->x;
}

double getYtexto(Texto t){
    return ((texto*)t)->y;
}

char* getCORtexto(Texto t){
    return ((texto*)t)->cor;
}

char* getCORCOMPLtexto(Texto t){
    return ((texto*)t)->corcompl;
}

char getAtexto(Texto t){
    return ((texto*)t)->a;
}

char* getTXTOtexto(Texto t){
    return ((texto*)t)->txto;
}

void setItexto(Texto t, int i){
    ((texto*)t)->i = i;
}

void setXtexto(Texto t, double x){
    ((texto*)t)->x = x;
}

void setYtexto(Texto t, double y){
    ((texto*)t)->y = y;
}

void setCORtexto(Texto t, char* cor){
    strcpy(((texto*)t)->cor, cor);
}

void setCORCOMPLtexto(Texto t){
    int r, g, b;
    int Rcompl, Gcompl, Bcompl;
    char* p = ((texto*)t)->cor[1];
    sscanf(p, "%2x%2x%2x", &r, &g, &b);
    Rcompl = 255 - r;
    Gcompl = 255 - g;
    Bcompl = 255 - b;
    sprintf(((texto*)t)->corcompl, "#%X%X%X", Rcompl, Gcompl, Bcompl);
}

double calcula_area_texto(Texto t){
    return (20 * strlen(((texto*)t)->txto));
}