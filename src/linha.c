#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linha.h"

typedef struct{
    int i;
    double x1, y1, x2, y2;
    char *cor, *corcompl;
}linha;

linha criar_linha(int i, double x1, double y1, double  x2, double y2, char* cor){
    linha *l = malloc(sizeof(linha));
    l->i = i;
    l->x1 = x1;
    l->y1 = y1;
    l->x2 = x2;
    l->y2 = y2;

    l->cor = (char*)malloc(strlen(cor)+1);
    if (l->cor==NULL){
        printf("Erro ao alocar memoria para a cor da linha");
        exit(1);
    }
    strcpy(l->cor,cor);

    l->corcompl = setCORCOMPLlinha(linha l);
}

int getIlinha(linha l){
    return ((linha*)l)->i;
}

double getX1linha(linha l){
    return ((linha*)l)->x1;
}

double getY1linha(linha l){
    return ((linha*)l)->y1
}

double getX2linha(linha l){
    return ((linha*)l)->x2;
}

double getY2linha(linha l){
    return ((linha*)l)->y2;
}

char* getCORlinha(linha l){
    return ((linha*)l)->cor;
}

char* getCORCOMPLlinha(linha l){
    return ((linha*)l)->corcompl;
}

void setIlinha(linha l, int i){
    ((linha*)l)->i =i;
}

void setX1linha(linha l, int x1){
    ((linha*)l)->x1 = x1;
}

void setY1linha(linha l, int y1){
    ((linha*)l)->y1 = y1;
}

void setX2linha(linha l, int x2){
    ((linha*)l)->x2 = x2;
}

void setY2linha(linha l, int y2){
    ((linha*)l)->y2 = y2;
}

void setCORlinha(linha l, char* cor){
    strcpy(((linha*)l)->cor, cor);
}

// funcao 'setCORCOMPLlinha' ainda incompleta
void setCORCOMPLlinha(linha l){
    l->corcompl = (char*)malloc(strlen(cor)+1);
    if(l->corcompl == NULL){
        printf("Erro ao alocar memoria para a cor complementar da linha");
        exit(1);
    }

    char R[2], G[2], B[2];

}

double calcula_area_linha(linha l){
    return (sqrt(pow(((linha*)l)->x1 - ((linha*)l)->x2) + pow(((linha*)l)->y1 - ((linha*)l)->y2)));
}