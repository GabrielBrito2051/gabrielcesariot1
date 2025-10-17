#include <stdio.h>
#include <stdlib.h>
#include "disparador.h"
#include "fila.h"
#include "carregador.h"

typedef struct{
    int d;
    double x, y;
    Forma pos_disparo;
    Carregador cesq, cdir;
}disparador;

Disparador criar_disparador(int d, double x, double y){
    disparador *disp = malloc(sizeof(disparador));
    disp->d = d;
    disp->x = x;
    disp->y = y;
    disp->pos_disparo = NULL;
    disp->cesq = NULL;
    disp->cdir = NULL;

    return ((disparador*)disp);
}

int  compara_disp(int d, Disparador DispDaLista){
    disparador* dispextra = (disparador*) DispDaLista;
    return (dispextra->d == d) ? 1 : 0;
}

void free_disp(Disparador disp){
    disparador* var = (disparador*)disp;
    free(var);
}

void attach_carreador(Disparador disp, Carregador car, char lado){
    disparador* castdisp = (disparador*) disp;
    if (lado == "e"){
        castdisp->cesq = car;
    }else{
        castdisp->cdir = car;
    }
}

int shift(Disparador disp, char lado){
    disparador* castdisp = (disparador*) disp;
    Carregador origem = (lado=="d") ? castdisp->cesq : castdisp->cdir;
    Carregador destino = (lado=="d") ? castdisp->cdir : castdisp->cesq;

    if(castdisp->pos_disparo!=NULL){
        if(destino != NULL){
                Pilha pilha_destino = getPILHAcarregador(destino);
                pushPilha(pilha_destino, castdisp->pos_disparo);
        }else{
            printf("O carregador de destino nao existe!");
            return 0;
        }
        castdisp->pos_disparo = NULL;
    }

    if(origem!=NULL){
        Pilha pilha_origem = getPILHAcarregador(origem);
        if(verifica_pilha_vazia(pilha_origem)==0){
            castdisp->pos_disparo = get_topo_pilha(pilha_origem);
            popPilha(pilha_origem);
            return 1;
        }else{
             printf("Nao ha mais formas no carregador de origem, disparador agora esta vazio!");
            castdisp->pos_disparo=NULL;
            return 0;
        }
    }else{
       printf("Nao ha um carregador no disparador, esta vazio!");
        castdisp->pos_disparo=NULL;
        return 0;
    }
}

Forma disparar_forma(Disparador disp){
    disparador* castdisp = (disparador*) disp;
    if(castdisp==NULL || castdisp->pos_disparo==NULL){
        printf("Nao ha uma forma na posicao de disparo!");
        return NULL;
    }
     
    Forma forma_disparada = castdisp->pos_disparo;
    castdisp->pos_disparo = NULL;

    return forma_disparada;
}

int getIDdisparador(Disparador disp){
    disparador* castdisp = (disparador*) disp;
    return castdisp->d;
}

double getXdisparador(Disparador disp){
    disparador* castdisp = (disparador*) disp;
    return castdisp->x;
}

double getYdisparador(Disparador disp){
    disparador* castdisp = (Disparador*) disp;
    return castdisp->y;
}

Forma getFormaNaMira(Disparador disp){
    disparador* castdisp = (disparador*)disp;
    return castdisp->pos_disparo;
}