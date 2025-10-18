#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formas.h"

typedef struct pacote{
    Forma forma;
    tipoforma tipo;
};

Pacote criarPacote(){
    Pacote pac = malloc(sizeof(Pacote));
    return pac;
}

tipoforma getTIPOFORMApacote(Pacote pac){
   return  pac->tipo;
}

void getSegmentoLinha(Forma f, double* x1, double*y1, double *x2, double* y2){
    tipoforma tipo = getTipoForma(f);
    if(tipo == tipo_linha){
        *x1 = getX1linha(f);
        *y1 = getY1linha(f);
        *x2 = getX2linha(f);
        *y2 = getY2linha(f);
    }else{
        double xt = getXtexto(f);
        double yt = getYtexto(f);
        char ancora = getAncoraTexto(f);
        const char* conteudo = getConteudoTexto(f);
        int tamanho = strlen(conteudo);

        *y1 = yt;
        *y2 = yt;

        if(ancora == "i"){
            *x1 = xt;
            *x2 = xt + 10.0 * tamanho;
        }
        
        else if(ancora == "f"){
            *x1 = xt - 10.0 * tamanho;
            *x2 = xt;
        }

        else if(ancora == "m"){
            *x1 = xt - 5*tamanho;
            *x2 = xt + 5*tamanho;
        }
    }
}

Forma getFORMApacote(Pacote pac){
    return pac->forma;
}

void freePACOTE(Pacote pac){
    free(pac);
}