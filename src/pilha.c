#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct ELEMENTO{
    void* forma;
    struct ELEMENTO *prox;
}elementopilha;

typedef elementopilha* pont;

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

int getTAMANHOpilha(Pilha p){
    pont extra = ((pilha*)p)->topo;
    int tam = 0;
    while (extra!=NULL){
        tam++;
        extra = extra->prox;
    }

    return tam;
}

void pushPilha(Pilha p, Forma forma){
    pilha *var = (pilha*) p;
    pont novo = malloc(sizeof(elementopilha));
    if(novo == NULL){
        printf("Erro ao alocar memoria para a pilha");
        exit(1);
    }
    novo->forma = forma;
    novo->prox = var->topo;
    var->topo = novo;
}

void popPilha(Pilha p){
    if(verifica_se_vazia(p)==1){
        printf("Nao foi possivel dar pop, pilha vazia");
        exit(1);
    }
    pilha *var = (pilha*) p;
    pont apagar = var->topo;
    var->topo = var->topo->prox;
    free(apagar);
}

Forma get_topo_pilha(Pilha p){
    return (((pilha*)p)->topo->forma);
}