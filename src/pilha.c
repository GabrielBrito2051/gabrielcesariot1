#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct ELEMENTO{
    Forma forma;
    struct ELEMENTO *prox;
}elementopilha;

typedef elementopilha* pont;

typedef struct{
    pont topo;
    int tamanho;
}pilha;

Pilha criar_pilha(){
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;
    p->tamanho = 0;

    return p;
}

int verifica_pilha_vazia(Pilha p){
    return (((pilha*)p)->topo == NULL) ? 1 : 0;
}

int getTAMANHOpilha(Pilha p){
    return ((pilha*)p)->tamanho;
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
    if(verifica_pilha_vazia(p)==1){
        printf("Nao foi possivel dar pop, pilha vazia");
        return;
    }
    pilha *var = (pilha*) p;
    pont apagar = var->topo;
    var->topo = var->topo->prox;
    free(apagar);
}

Forma get_topo_pilha(Pilha p){
    if(verifica_pilha_vazia(p)==1){
        return NULL;
    }
    return (((pilha*)p)->topo->forma);
}

void free_pilha(Pilha p){
    pilha* var = (pilha*)p;
    free(var);
}