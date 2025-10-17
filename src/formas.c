#include <stdio.h>
#include <stdlib.h>
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

Forma getFORMApacote(Pacote pac){
    return pac->forma;
}

void freePACOTE(Pacote pac){
    free(pac);
}