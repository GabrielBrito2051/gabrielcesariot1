#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

typedef struct{
    int i;
    double x, y, w, h;
    char *corb, *corp;
}retangulo;

retangulo criar_retangulo(int i, double x, double y, double w, double h, char* corb, char* corp){
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

int getIretangulo(retangulo r){
    return ((retangulo*)r)->i;
}

double getXretangulo(retangulo r){
    return ((retangulo*)r)->x;
}

double getYretangulo(retangulo r){
    return ((retangulo*)r)->y;
}

double getWretangulo(retangulo r){
    return ((retangulo*)r)->w;
}

double getHretangulo(retangulo r){
    return ((retangulo*)r)->h;
}

char* getCORBretangulo(retangulo r){
    return ((retangulo*)r)->corb;
}

char* getCORPretangulo(retangulo r){
    return ((retangulo*)r)->corp;
}

void setIretangulo(retangulo r, int i){
    ((retangulo*)r)->i = i;
}

void setXretangulo(retangulo r, double x){
    ((retangulo*)r)->x = x;
}

void setYretangulo(retangulo r, double y){
    ((retangulo*)r)->y = y;
}

void setWretangulo(retangulo r, double w){
    ((retangulo*)r)->w = w;
}

void setHretangulo(retangulo r, double h){
    ((retangulo*)r)->w = w;
}

void setCORBretangulo(retangulo r, char* corb){
    strcpy(((retangulo*)r)->corb, corb);
}

void setCORPretangulo(retangulo r, char* corp){
    strcpy(((retangulo*)r)->corp, corp);
}

double calcula_area_retangulo(retangulo r){
    return (w*h);
}