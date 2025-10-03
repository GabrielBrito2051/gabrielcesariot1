#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct ELEMENTO{
    void* forma;
    struct ELEMENTO *prox;
}elemento;

typedef elemento* pont;

typedef struct{
    pont topo;
}pilha;

Pilha criar_pilha(){
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;

    return p;
}

int verifica_se_vazia(Pilha p){
    return (((pilha*)p)->topo == NULL) ? 1 : 0;
}

void push(Pilha p, void* forma){
    pilha *var = (pilha*) p;
    pont novo = malloc(sizeof(elemento));
    if(novo == NULL){
        printf("Erro ao alocar memoria para a pilha");
        exit(1);
    }
    novo->forma = forma;
    novo->prox = var->topo;
    var->topo = novo;
}

void pop(Pilha p){
    if(verifica_se_vazia(p)==1){
        printf("Nao foi possivel dar pop, pilha vazia");
        exit(1);
    }
    pilha *var = (pilha*) p;
    pont p = var->topo;
    var->topo = var->topo->prox;
    free(p);
}

void* get_topo_pilha(Pilha p){
    pilha *var = (pilha*) p;
    return var->topo->forma;
}