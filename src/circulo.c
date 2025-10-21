#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

#define pi 3.14

typedef struct{
    int i;
    double x, y, r;
    char *corb, *corp;
}circulo;

Circulo criar_circulo(int i, double x, double y, double r, char* corb, char* corp){
    circulo *c = malloc(sizeof(circulo));
    c->i = i;
    c->x = x;
    c->y = y;
    c->r = r;

    c->corb = (char*)malloc(strlen(corb) + 1);
    if (c->corb == NULL){
        printf("Erro ao alocar memoria para a cor de borda");
        exit(1);
    }
    strcpy(c->corb, corb);

    c->corp = (char*)malloc(strlen(corp) + 1);
    if(c->corp == NULL){
        printf("Erro ao alocar memoria para a cor do preenchimento");
        exit(1);
    }
    strcpy(c->corp, corp);
    
    return ((circulo*)c);
}

int getIcirculo(Circulo c){
    return ((circulo*)c)->i;
}

double getXcirculo(Circulo c){
    return ((circulo*)c)->x;
}

double getYcirculo(Circulo c){
    return ((circulo*)c)->y;
}

double getRcirculo(Circulo c){
    return ((circulo*)c)->r;
}

char* getCORBcirculo(Circulo c){
    return ((circulo*)c)->corb;
}

char* getCORPcirculo(Circulo c){
    return ((circulo*)c)->corp;
}

void setIcirculo(Circulo c, int i){
    ((circulo*)c)->i = i;
}

void setXcirculo(Circulo c, double x){
    ((circulo*)c)->x = x;
}

void setYcirculo(Circulo c, double y){
    ((circulo*)c)->y = y;
}

void setRcirculo(Circulo c, double r){
    ((circulo*)c)->r = r;
}

void setCORBcirculo(Circulo c, char* corb){
    strcpy(((circulo*)c)->corb, corb);
}

void setCORPcirculo(Circulo c, char* corp){
    strcpy(((circulo*)c)->corp, corp);
}

double calcula_area_circulo(Circulo c){
    return pi * ((circulo*)c)->r * ((circulo*)c)->r;
}

void freeCorbCir(Circulo c){
    circulo* var = (circulo*)c;
    free(var->corb);
}

void freeCorpCir(Circulo c){
    circulo* var = (circulo*)c;
    free(var->corp);
}