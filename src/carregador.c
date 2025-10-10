#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carregador.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include "pilha.h"
#include "linha.h"
#include "fila.h"

typedef void* node;

typedef struct{
    int i;
    Pilha pontpilha;
}carregador;

Carregador cria_carregador(int i){
    carregador *car = malloc(sizeof(carregador));
    if(car==NULL){
        printf("Erro ao alocar memoria para o carregador %d", i);
        exit(1);
    }
    car->pontpilha = criar_pilha();
    car->i = i;
    return car;
}

int getIcarregador(Carregador car){
    return ((carregador*)car)->i;
}

Carregador load_carregador(Carregador car, Fila f, int i){
    carregador *castcar = ((carregador*)car);
    f = criar_fila();
    int tam = getTAMANHOfila(f);
    node n;
    if(i>tam){
        printf("Erro ao inserir as formas no carregador, o numero de formas indicadas e maior que a quantidade de formas no chao");
        exit(1);
    }
    for(int j;j<i;j++){
        pushPilha(castcar, get_inicio_fila(f));
        popFila(f);
    }

    return castcar;
}

void free_carregador(Carregador car){
    carregador *castcar = ((carregador*)car);
    free(castcar);
}