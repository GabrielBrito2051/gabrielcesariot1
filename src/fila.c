#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct ELEMENTO{
    Forma forma;
    int tipoforma;
    struct ELEMENTO* prox;
}elementofila;

typedef elementofila* pont;

typedef struct{
    pont inicio;
    pont fim;
}fila;

Fila criar_fila(){
    fila* f = malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int verifica_se_vazia(Fila f){
    return(((fila*)f)->inicio==NULL) ? 1 : 0;
}

int getTAMANHOfila(Fila f){
    pont extra = ((fila*)f)->inicio;
    int tam = 0;
    while(extra!=NULL){
        extra = extra->prox;
        tam++;
    }
    return tam;
}

void pushFila(Fila f, Forma forma){
    fila* var = (fila*) f;
    pont novo = malloc(sizeof(elementofila));
    if(novo==NULL){
        printf("Erro ao alocar memoria para a fila");
        exit(1);
    }

    novo->forma = forma;
    novo->prox = NULL;

    if(var->inicio==NULL){
        var->inicio = novo;
    }else{
        var->fim->prox = novo;
    }
    var->fim = novo;
}

void popFila(Fila f){
    fila* var = (fila*) f;
    pont apagar = var->inicio;
    var->inicio = var->inicio->prox;
    if(var->inicio==NULL){
        var->fim = NULL;
    }
    free(apagar);
}

Forma get_inicio_fila(Fila f){
    return (((fila*)f)->inicio->forma);
}