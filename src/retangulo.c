#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

typedef struct{
    int i;
    double x, y, w, h;
    char *corb, *corp;
}retangulo;

Retangulo criar_retangulo(int i, double x, double y, double w, double h, char* corb, char* corp){
    retangulo *r = malloc(sizeof(retangulo));
    r->i = i;
    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;
    
    r->corb = (char*)malloc(strlen(corb)+1);
    if(r->corb == NULL){
        printf("Erro ao alocar memoria para a cor de borda");
        exit(1);
    }
    strcpy(r->corb,corb);

    r->corp = (char*)malloc(strlen(corp)+1);
    if(r->corp == NULL){
        printf("Erro ao alocar memoria para o cor de preenchimento");
        exit(1);
    }
    strcpy(r->corp,corp);

    return ((retangulo*)r);
}

int getIretangulo(Retangulo r){
    return ((retangulo*)r)->i;
}

double getXretangulo(Retangulo r){
    return ((retangulo*)r)->x;
}

double getYretangulo(Retangulo r){
    return ((retangulo*)r)->y;
}

double getWretangulo(Retangulo r){
    return ((retangulo*)r)->w;
}

double getHretangulo(Retangulo r){
    return ((retangulo*)r)->h;
}

char* getCORBretangulo(Retangulo r){
    return ((retangulo*)r)->corb;
}

char* getCORPretangulo(Retangulo r){
    return ((retangulo*)r)->corp;
}

void setIretangulo(Retangulo r, int i){
    ((retangulo*)r)->i = i;
}

void setXretangulo(Retangulo r, double x){
    ((retangulo*)r)->x = x;
}

void setYretangulo(Retangulo r, double y){
    ((retangulo*)r)->y = y;
}

void setWretangulo(Retangulo r, double w){
    ((retangulo*)r)->w = w;
}

void setHretangulo(Retangulo r, double h){
    ((retangulo*)r)->h = h;
}

void setCORBretangulo(Retangulo r, char* corb){
    strcpy(((retangulo*)r)->corb, corb);
}

void setCORPretangulo(Retangulo r, char* corp){
    strcpy(((retangulo*)r)->corp, corp);
}

double calcula_area_retangulo(Retangulo r){
    return (((retangulo*)r)->w * ((retangulo*)r)->h);
}