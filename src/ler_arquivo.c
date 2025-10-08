#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ler_arquivo.h"

#define tamLinha 256

arquivo abre_arquivo_escrita(char* nome){
    arquivo arq = fopen(nome, "w");
    if(arq==NULL){
        printf("Erro ao abrir arquivo %s",nome);
        exit(1);
    }
    return arq;
}

arquivo abre_arquivo_leitura(char* nome){
    arquivo arq = fopen(nome, "r");
    if(arq==NULL){
        printf("Erro ao abrir o arquivo %s",nome);
        exit(1);
    }
    return arq;
}

char* le_linha(arquivo arq, char* linha){
    fgets(linha, tamLinha, arq);
    if(linha==NULL){
        printf("Erro ao ler uma linha do arquivo");
        exit(1);
    }
    return linha;
}

void fecha_arquivo(arquivo arq){
    fclose(arq);
}