#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carregador.h"
#include "pilha.h"
#include "fila.h"
#include "formas.h"

typedef struct{
    int c;
    Pilha formas;
}carregador;

int compara_car(int c, Carregador car){
    carregador* carextra = (carregador*) car;
    return (carextra->c == c) ? 1 : 0;
}

Carregador cria_carregador(int c){
    carregador *car = malloc(sizeof(carregador));
    if(car==NULL){
        printf("Erro ao alocar memoria para o carregador %d", c);
        exit(1);
    }

    car->formas = criar_pilha();
    car->c = c;

    return ((carregador*)car);
}

int getIDcarregador(Carregador car){
    return ((carregador*)car)->c;
}

void destruir_carregador(Carregador car){
    carregador* var = (carregador*) car;
    destruir_pilha(var->formas);
    free(var);
}

Pilha getPILHAcarregador(Carregador car){
    return((carregador*)car)->formas;
}