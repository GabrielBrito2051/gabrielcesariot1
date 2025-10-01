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

pilha *criar_pilha(){
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;

    return p;
}

int verifica_se_vazia(pilha *p){
    return (p->topo == NULL) ? 1 : 0;
}

void push(pilha *p, void* forma){
    pont novo = malloc(sizeof(elemento));
    if(novo == NULL){
        printf("Erro ao alocar memoria para a pilha");
        exit(1);
    }
    novo->forma = forma;
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(pilha *p){
    if(verifica_se_vazia(p)==1){
        printf("Nao foi possivel dar pop, pilha vazia");
        exit(1);
    }
    pont p = p->topo;
    p->topo = p->topo->prox;
    free(p);
}

void* get_topo_pilha(pilha *p){
    return p->topo->forma;
}