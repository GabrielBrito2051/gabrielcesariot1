#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct ELEMENTO{
    Forma forma;
    struct ELEMENTO* prox;
}elementofila;

typedef elementofila* pont;

typedef struct{
    pont inicio;
    pont fim;
    int tamanho;
}fila;

Fila criar_fila(){
    fila* f = malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;

    return f;
}

int verifica_fila_vazia(Fila f){
    return(((fila*)f)->inicio==NULL) ? 1 : 0;
}

int getTAMANHOfila(Fila f){
    fila* castfila = (fila*)f;
    return castfila->tamanho; 
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
    var->tamanho++;
}

void popFila(Fila f){
    fila* var = (fila*) f;
    pont apagar = var->inicio;
    var->inicio = var->inicio->prox;
    if(var->inicio==NULL){
        var->fim = NULL;
    }
    free(apagar);
    var->tamanho--;
}

Forma get_inicio_fila(Fila f){
    if(verifica_fila_vazia(f)==1){
        return NULL;
    }
    return (((fila*)f)->inicio->forma);
}

Forma buscar_na_fila(Fila f, int (*comparaElemento)(int i, void* elemento),int i){
    fila* varf = (fila*)f;
    pont atual = varf->inicio;
    while(atual != NULL){
        if(comparaElemento(i, atual->forma)==1){
            return atual->forma;
        }
        atual = atual->prox;
    }
    return NULL;
}

void removeDaFila(Fila f, Forma forma){
    fila* var = (fila*)f;
    pont atual = var->inicio;
    pont anterior = NULL;


    while (atual != NULL && atual->forma != forma) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("O elemento nao foi encontrado");
        return;
    }

    if (anterior == NULL) { 
        var->inicio = atual->prox;
    } 
    else {
        anterior->prox = atual->prox;
    }
    if (atual == var->fim) {
        var->fim = anterior;
    }
    free(atual);
}

void free_fila(Fila f){
    fila* var = (fila*) f;
    free(var);
}