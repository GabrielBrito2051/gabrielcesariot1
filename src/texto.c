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

texto criar_texto(int i, double x, double y, char* cor, char a, char* txto){
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
    t->corcompl = setCORCOMPLtexto(texto t);

    return ((texto*)t);
}

int getItexto(texto t){
    return ((texto*)t)->i;
}

double getXtexto(texto t){
    return ((texto*)t)->x;
}

double getYtexto(texto t){
    return ((texto*)t)->y;
}

char* getCORtexto(texto t){
    return ((texto*)t)->cor;
}

char* getCORCOMPLtexto(texto t){
    return ((texto*)t)->corcompl;
}

char getAtexto(texto t){
    return ((texto*)t)->a;
}

char getTXTOtexto(texto t){
    return ((texto*)t)->txto;
}

void setItexto(texto t, int i){
    ((texto*)t)->i = i;
}

void setXtexto(texto t, double x){
    ((texto*)t)->x = x;
}

void setYtexto(texto t, double y){
    ((texto*)t)->y = y;
}

void setCORtexto(texto t, char* cor){
    strcpy(((texto*)t)->cor, cor);
}

//funcao setCORCOMPLtexto em andamento
void setCORCOMPLtexto(texto t){

}

double calcula_area_texto(texto t){
    return (20 * strlen(((texto*)t)->txto));
}